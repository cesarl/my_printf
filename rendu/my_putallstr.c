/*
** my_putallstr.c for putallstr in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:42:19 2012 cesar leblic
** Last update Sun Apr 22 16:42:25 2012 cesar leblic
*/

#include <stdio.h>
#include "my.h"
int	my_putallstr(char *str)
{
  int	c;
  int	res;

  c = 0;
  res = 0;
  while (str[c])
    {
      if (str[c] < 32 || str[c] >= 127)
	res += nbr_tobase(str[c], "01234567", "\\0");
      else
	res += my_putchar(str[c]);
      c += 1;
    }
  return (res);
}
