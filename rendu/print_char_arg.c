/*
** print_char_arg.c for print_char_arg in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:45:34 2012 cesar leblic
** Last update Sun Apr 22 16:55:10 2012 cesar leblic
*/

#include <stdarg.h>
#include "my.h"
int	print_char_arg(int nbr, va_list ap)
{
  int	res;

  res = 0;
  if (nbr == 10)
    res += my_putstr(va_arg(ap, char *));
  else if (nbr == 9)
    res += my_putallstr(va_arg(ap, char *));
  return (res);
}
