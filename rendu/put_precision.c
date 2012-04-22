/*
** put_precision.c for put_precision in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:47:17 2012 cesar leblic
** Last update Sun Apr 22 16:54:33 2012 cesar leblic
*/

#include "my.h"
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
