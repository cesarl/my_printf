/*
** put_specifier.c for put_specifier in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:47:33 2012 cesar leblic
** Last update Sun Apr 22 16:47:34 2012 cesar leblic
*/

#include "my.h"
int	put_specifier(int cnt, char *str, t_arg *args)
{
  int	mem;

  mem = is_flags(cnt, str, "cdiouxXpbSs%");
  if (mem == -1)
    args->fakespec = str[cnt];
  args->specifier = mem;
  return (cnt + 1);
}
