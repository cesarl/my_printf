/*
** libmy.h for libmy.h in /home/leblic_c//Documents/lib_my_c/include
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Fri Mar 23 17:54:12 2012 cesar leblic
** Last update Thu Mar 29 11:05:05 2012 cesar leblic
*/

#ifndef __LIBMY_H__
#define __LIBMY_H__

void    my_aff_alpha();
void    my_aff_chiffre();
int     my_aff_comb();
int     my_aff_isneg(int n);
void    my_rev_alpha();
int     my_char_isalpha(char c);
int     my_char_isalphanum(char c);
int     my_char_isnum(char c);
char    *my_convert_base(char *nbr, char *base_from, char *base_to);
char    *my_evil_str(char *str);
int     my_factorielle_it(int nb);
int     my_factorielle_rec(int nb);
int     my_getnbr_base(char *str, char *base);
int     my_getnbr(char *str);
int     my_is_prime(int nb);
int     my_power_it(int nb, int power);
int     my_power_rec(int nb, int power);
void    my_putchar(char c);
void    my_put_int_tab(int *str);
void    my_put_nbr(int nb);
void    my_putstr(char *s);
char    *my_revstr(char *str);
int     my_show_wordtab(char **tab);
int     my_sign(int n);
void    my_sort_int_tab(int *tab, int size);
int     my_square_root(int nb);
char    *my_strcapitalize(char *str);
char    *my_strcat(char *dest, char *src);
int     my_strcmp(char *s1, char *s2);
char    *my_strcpy(char *dest, char *src);
char    *my_strdup(char *src);
int     my_str_isalpha(char *str);
int     my_str_isempty(char *str);
int     my_str_islower(char *str);
int     my_str_isnum(char *str);
int     my_str_isprintable(char *str);
int     my_str_isupper(char *str);
char    *my_strlcat(char *dest, char *src, int size);
int     my_strlen(char *str);
char    *my_strlowcase(char *str);
char    *my_strncat(char *dest, char *src, int nb);
int     my_strncmp(char *s1, char *s2, int n);
char    *my_strncpy(char *dest, char *src, int n);
char    *my_strstr(char *str, char *to_find);
char    **my_str_to_wordtab(char *str);
char    *my_strupcase(char *str);
char    *my_sum_params(int argc, char **argv);
int     my_swap(int *a, int *b);
int	my_word_nbr(char *str);
struct  s_stock_par     *my_param_to_tab(int ac, char **av);
int     my_show_tab(struct s_stock_par *par);

struct  s_stock_par
{
  int   size_param;
  char  *str;
  char  *copy;
  char  **tab;
};

typedef struct	s_stock_par	 t_stock_par;

#endif
