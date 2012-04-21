#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

typedef struct s_flag
{
  int	data;
  struct s_flag *next;
} t_flag;

typedef struct s_arg
{
  t_flag *flags;
  int	width;
  int	precision;
  int	length;
  int	specifier;
  char	fakespec;
  struct s_arg *next;
} t_arg;

char	*cpy_str(char *src, int s, int e)
{
  char	*cpy;
  int	cnt;
  int	str_cnt;

  cpy = malloc(sizeof(char) * (e - s));
  cnt = 0;
  str_cnt = s;
  while (cnt <= (e - s))
    {
      cpy[cnt] = src[str_cnt];
      cnt += 1;
      str_cnt += 1;
    }
  cpy[cnt] = '\0';
  return (cpy);
}

int     my_push_flag(t_flag **list, int value)
{
  t_flag *element;
  t_flag *tmp;

  tmp = *list;
  element = malloc(sizeof(*element));
  if (element == NULL)
    return (1);
  element->data = value;
  element->next = NULL;
  if ((*list) == NULL)
    {
      (*list) = element;
      return (1);
    }
  while ((*list)->next != NULL)
    {
      (*list) = (*list)->next;
    }
  (*list)->next = element;
  (*list) = tmp;
  return (0);
}

int	is_flags(int cnt, char *str, char *val)
{
  int	c;

  c = 0;
  while (val[c])
    {
      if (val[c] == str[cnt])
	return (c);
      c += 1;
    }
  return (-1);
}

int	put_flags(int cnt, char *str, t_arg *args)
{
  args->flags = NULL;
  while (is_flags(cnt, str, "-+ #0") != -1)
    {
      my_push_flag(&args->flags, is_flags(cnt, str, "-+ #0"));
      cnt += 1;
    }
  return (cnt);
}

int	put_width(int cnt, char *str, t_arg *args)
{
  int	start;

  start = cnt;
  while (my_char_isnum(str[cnt]) == 1)
    cnt += 1;
  if (start != cnt)
    args->width = my_getnbr(cpy_str(str, start, cnt));
  else
    args->width = 0;
  return (cnt);
}

int	put_precision(int cnt, char *str, t_arg *args)
{
  int	start;

  if (str[cnt] != '.')
    {
      args->precision = -1;
      return (cnt);
    }
  start = ++cnt;
  while (my_char_isnum(str[cnt]) == 1)
    cnt += 1;
  if (start != cnt)
    args->precision = my_getnbr(cpy_str(str, start, cnt));
  else
    args->precision = -1;
  return (cnt);  
}

int	put_length(int cnt, char *str, t_arg *args)
{

}

int	put_specifier(int cnt, char *str, t_arg *args)
{
  int	mem;

  mem = is_flags(cnt, str, "cdieEfgGosuxXpn%bS");
  if (mem == -1)
    args->fakespec = str[cnt];
  args->specifier = mem;
  return (cnt + 1);
}

void	nbr_tobase(int n, char *base)
{
  int	len;
  int	div;

  len = my_strlen(base);
  div = 1;
  while (len <= n / div)
    div *= len;
  while (div)
    {
      my_putchar(base[n / div % len]);
      div /= len;
    }
}

void	my_putallstr(char *str)
{
  int	c;

  c = 0;
  while (str[c])
    {
      if (str[c] < 32 || str[c] >= 127)
	{
	  my_putstr("\\0");
	  nbr_tobase(str[c], "01234567");
	}
      else
	my_putchar(str[c]);
      c += 1;
    }
}

int     my_push_args(t_arg **list, t_arg *element)
{
  t_arg *tmp;

  tmp = *list; 
  element->next = NULL;
  if ((*list) == NULL)
    {
      (*list) = element;
      return (1);
    }
  while ((*list)->next != NULL)
    {
      (*list) = (*list)->next;
    }
  (*list)->next = element;
  (*list) = tmp;
  return (0);
}

void	print_spaces(t_arg *args)
{
  int	c;

  c = 0;
  if (args->width > 0)
    {
      while (c < args->width)
	{
	  my_putchar(' ');
	  c += 1;
	}
    }
}

void	print_flags(t_arg *args, va_list ap)
{
  //-+ #0
  if (args)
    {
      while (args->flags)
	{
	  if (args->flags->data == 2) // space
	    print_spaces(args);
	  args->flags = args->flags->next;
	}
    }
}

void	print_spec(t_arg *args, va_list ap)
{
  while (args)
    {
      //cdieEfgGosuxXpn%bS
      if (args->specifier == 15) //%
	my_putchar('%');
      else if (args->specifier == 1 || args->specifier == 2 || args->specifier == 10) // d i
	my_put_nbr(va_arg(ap, int));
      else if (args->specifier == 8) // o
	nbr_tobase(va_arg(ap, int), "01234567");
      else if (args->specifier == 11) //x
	nbr_tobase(va_arg(ap, int), "0123456789abcdef");
      else if (args->specifier == 12) //X
	nbr_tobase(va_arg(ap, int), "0123456789ABCDEF");
      else if (args->specifier == 16) //B
	nbr_tobase(va_arg(ap, int), "01");
      else if (args->specifier == 0) //c
	my_putchar(va_arg(ap, int));
      else if (args->specifier == 9) //s
	my_putstr(va_arg(ap, char *));
      else if(args->specifier == 17) //S NE FONCTIONNE PAS !!!
	my_putallstr(va_arg(ap, char *));
      else if (args->specifier == 13) //p
	{
	  my_putstr("0x");
	  nbr_tobase(va_arg(ap, int), "0123456789abcdef");
	}
      else
	{
	  my_putchar('%');
	  my_putchar(args->fakespec);
	}
      args = args->next;
    }
}

t_arg	*parser(char *str, va_list ap)
{
  int	cnt;
  t_arg	*args;
  t_arg *tmp;

  cnt = 0;
  args = NULL;
  while (str[cnt])
    {
      if (str[cnt] == '%')
	{
	  tmp = malloc(sizeof(*tmp));
	  cnt = put_flags(cnt + 1, str, tmp);
	  cnt = put_width(cnt, str, tmp);
	  cnt = put_precision(cnt, str, tmp);
	  //	  cnt = put_length(cnt, str, args);
	  cnt = put_specifier(cnt, str, tmp);
	  my_push_args(&args, tmp);
	}
      cnt += 1;
    }
  print_flags(args, ap);
  print_spec(args, ap);
}


int	my_printf(char *str, ...)
{
  va_list	ap;
  int		cnt;
  char		*token;

  cnt = 0;
  va_start(ap, str);
  parser(str, ap);
  my_putchar('\n');
}

int	main()
{
  int	ret[2];
  char	*str = "astek";
  char	stre[] = {'a', 's', 10, 'e', 'k', 0};
  printf("##### Tests simple : 1 point par test reussi #####\n");
  printf(   "0) Modulo [%%] : {%%}\n");
  my_printf("=> Modulo [%%] : {%%}\n");
  printf(   "1) Nombre signe [d] : {%d}\n", 42);
  my_printf("=> Nombre signe [d] : {%d}\n", 42);
  printf(   "2) Nombre signe [i] : {%i}\n", 42);
  my_printf("=> Nombre signe [i] : {%i}\n", 42);
  printf(   "3) Nombre octal [o] : {%o}\n", 012345);
  my_printf("=> Nombre octal [o] : {%o}\n", 012345);
  printf(   "4) Nombre non signe [u] : {%u}\n", 42);
  my_printf("=> Nombre non signe [u] : {%u}\n", 42);
  printf(   "5) Nombre hexadecimal [x] : {%x}\n", 0x12345);
  my_printf("=> Nombre hexadecimal [x] : {%x}\n", 0x12345);
  printf(   "6) Nombre hexadecimal [X] : {%X}\n", 0x12345);
  my_printf("=> Nombre hexadecimal [X] : {%X}\n", 0x12345);
  printf(   "7) Nombre binaire [b] : {101111101111110000001}\n");
  my_printf("=> Nombre binaire [b] : {%b}\n", 1564545);
  printf(   "8) Caractere [c] : {%c}\n", 42);
  my_printf("=> Caractere [c] : {%c}\n", 42);
  printf(   "9) Chaine [s] : {%s}\n", str);
  my_printf("=> Chaine [s] : {%s}\n", str);
  printf(   "10) Chaine etendue [S] : as\\012ek\n");
  my_printf("=>  Chaine etendue [S] : %S\n", stre);
  printf(   "11) Pointeur [p] : {%p}\n", str);
  my_printf("=>  Pointeur [p] : {%p}\n", str);
  printf(   "12) Mauvais parametre [k] : {%k}\n", 42);
  my_printf("=>  Mauvais parametre [k] : {%k}\n", 42);

  printf("Appuyez sur [entree] pour continuer...\n");
  getchar();

  printf("\n##### Tests pour verifier : -1pt par resultat errone #####\n");
  printf(   "1) Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  my_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  printf(   "2) Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
  my_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
  printf(   "3) Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  my_printf("=> Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  printf(   "4) Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  my_printf("=> Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  printf(   "5) Affichage multiple [s S X] : {%s} {as\\012ek} {%X}\n", str, -1);
  my_printf("=> Affichage multiple [s S X] : {%s} {%S} {%X}\n", str, stre, -1);
  printf(   "5) Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  my_printf("=> Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  printf(   "6) Affichage long [s S s ...] : %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek\n", str, str, str, str, str, str);
  my_printf("=> Affichage long [s S s ...] : %s %S %s %S %s %S %s %S %s %S %s %S\n", str, stre, str, stre, str, stre, str, stre, str, stre, str, stre);

  printf("Appuyez sur une touche pour continuer...\n");
  getchar();

  printf("\n##### Formatage : 1pt pour 3 tests reussis  #####\n");
  printf(   "1) Formatage simple [#d] : {%#d}\n", 42);
  my_printf("=> Formatage simple [#d] : {%#d}\n", 42);
  printf(   "2) Formatage simple [#x] : {%#x}\n", 0x12345);
  my_printf("=> Formatage simple [#x] : {%#x}\n", 0x12345);
  printf(   "3) Formatage simple [#o] : {%#o}\n", 012345);
  my_printf("=> Formatage simple [#o] : {%#o}\n", 012345);
  printf(   "4) Formatage simple [0d] : {%0d}\n", 42);
  my_printf("=> Formatage simple [0d] : {%0d}\n", 42);
  printf(   "5) Formatage simple [5d] : {%5d}\n", 42);
  my_printf("=> Formatage simple [5d] : {%5d}\n", 42);
  printf(   "6) Formatage simple [ d] : {% d}\n", 42);
  my_printf("=> Formatage simple [ d] : {% d}\n", 42);
  printf(   "7) Formatage simple [-d] : {%-d}\n", 42);
  my_printf("=> Formatage simple [-d] : {%-d}\n", 42);
  printf(   "8) Formatage simple [+d] : {%+d}\n", 42);
  my_printf("=> Formatage simple [+d] : {%+d}\n", 42);
  printf(   "9) Formatage simple [+d] : {%+d}\n", -42);
  my_printf("=> Formatage simple [+d] : {%+d}\n", -42);
  printf(   "10) Formatage multiple [ 5d] : {% 5d}\n", 42);
  my_printf("=>  Formatage multiple [ 5d] : {% 5d}\n", 42);
  printf(   "11) Formatage multiple [-32o] : {%-32o}\n", 012345);
  my_printf("=>  Formatage multiple [-32o] : {%-32o}\n", 012345);
  printf(   "12) Formatage multiple [-10+d] : {%+-10d}\n", 12345);
  my_printf("=>  Formatage multiple [-10+d] : {%-10+d}\n", 12345);
  printf(   "13) Formatage compose [-5cP] : %-5cP\n", 42);
  my_printf("=>  Formatage compose [-5cP] : %-5cP\n", 42);
  printf(   "14) Formatage compose [-30sP]: %-30sP\n", str);
  my_printf("=> Formatage compose [-30sP]: %-30sP\n", str);
  printf(   "15) Formatage compose [-4SP] : as\\012ekP\n");
  my_printf("=>  Formatage compose [-4SP] : %-4SP\n", stre);
  printf(   "16) Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
  my_printf("=>  Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
  printf(   "17) Formatage ultracompose [#15.12b] : {101111101111110000001}\n");
  my_printf("=>  Formatage ultracompose [#15.12b] : {%#15.12b}\n", 1564545);
  printf(   "18) Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
  my_printf("=>  Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
  printf(   "19) Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
  my_printf("=>  Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
  printf(   "20) Formatage pourcent [30%%] : {%30%}\n");
  my_printf("=>  Formatage pourcent [30%%] : {%30%}\n");
  printf(   "21) Formatage pourcent [-30pourcent] : {%-30%}\n");
  my_printf("=>  Formatage pourcent [-30pourcent] : {%-30%}\n");
  ret[0] = printf(   "22) Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
  ret[1] = my_printf("=>  Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
  printf(   "23) Verification de la valeur de retour [d] : {%d}\n", ret[0]);
  my_printf("=>  Verification de la valeur de retour [d] : {%d}\n", ret[1]);
  printf(   "24) Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
  my_printf("=>  Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
  
  my_printf("Segmentation fault ;)\n");
  
  return(0);
}

/* int	my_printf(char *str, ...) */
/* { */
/*   va_list	ap; */
/*   int		cnt; */
/*   char		*token; */

/*   cnt = 0; */
/*   va_start(ap, str); */
/*   while (str[cnt]) */
/*     { */
/*       if (str[cnt] == '%') */
/* 	{ */
/* 	  if (str[cnt + 1] == 's') */
/* 	    { */
/* 	      my_putstr(va_arg(ap, char *)); */
/* 	      cnt += 1; */
/* 	    } */
/* 	  else if (str[cnt + 1] == 'd') */
/* 	    { */
/* 	      my_put_nbr(va_arg(ap, int)); */
/* 	      cnt += 1; */
/* 	    } */
/* 	} */
/*       else */
/* 	my_putchar(str[cnt]); */
/*       cnt += 1; */
/*     } */
/* } */
