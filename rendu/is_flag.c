/*
** is_flag.c for is_flags in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:39:58 2012 cesar leblic
** Last update Sun Apr 22 16:40:03 2012 cesar leblic
*/

#include "my.h"
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
