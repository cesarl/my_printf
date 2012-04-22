/*
** put_width.c for put_width in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:47:44 2012 cesar leblic
** Last update Sun Apr 22 16:47:45 2012 cesar leblic
*/

#include "my.h"
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
