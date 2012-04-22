/*
** my_printf.h for my_printf in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:41:27 2012 cesar leblic
** Last update Sun Apr 22 16:41:29 2012 cesar leblic
*/

#include	<stdarg.h>
#ifndef		__MY_PRINTF__
#define		__MY_PRINTF__

typedef struct	s_flag
{
  int		data;
  struct	s_flag *next;
} t_flag;

typedef struct	s_arg
{
  t_flag	*flags;
  int		width;
  int		precision;
  int		length;
  int		specifier;
  char		fakespec;
  struct	s_arg *next;
} t_arg;

char		*cpy_str(char *src, int s, int e);
int		my_push_flag(t_flag **list, int value);
int		is_flags(int cnt, char *str, char *val);
int		put_flags(int cnt, char *str, t_arg *args);
int		put_width(int cnt, char *str, t_arg *args);
int		put_precision(int cnt, char *str, t_arg *args);
int		put_length(int cnt, char *str, t_arg *args);
int		put_specifier(int cnt, char *str, t_arg *args);
int		nbr_tobase(int n, char *base, char *sup);
int		my_putallstr(char *str);
int		my_push_args(t_arg **list, t_arg *element);
int		print_spaces(t_arg *args);
int		print_flags(t_arg *args, va_list ap);
int		print_spec(t_arg *args, va_list ap);
int		parser(char *str, va_list ap);
int		my_printf(char *str, ...);
int	    	print_nbr_arg(int nbr, va_list ap);
int		my_putnbr(int nb);
int		my_putchar(char c);
int		my_putstr(char *s);
int		print_char_arg(int nbr, va_list ap);

#endif
