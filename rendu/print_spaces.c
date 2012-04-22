/*
** print_spaces.c for print_spaces in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:46:33 2012 cesar leblic
** Last update Sun Apr 22 16:46:34 2012 cesar leblic
*/

#include <stdarg.h>
#include "my.h"
int	print_spaces(t_arg *args)
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
  return (args->width);
}
