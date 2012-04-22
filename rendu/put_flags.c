/*
** put_flags.c for put_flags in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:47:02 2012 cesar leblic
** Last update Sun Apr 22 16:47:03 2012 cesar leblic
*/

#include <stdlib.h>
#include "my.h"
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
