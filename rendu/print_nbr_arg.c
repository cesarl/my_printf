/*
** print_nbr_arg.c for print_nbr_arg in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:46:16 2012 cesar leblic
** Last update Sun Apr 22 16:52:15 2012 cesar leblic
*/

#include <stdarg.h>
#include "my.h"
int    	print_nbr_arg(int nbr, va_list ap)
{
  int	res;

  res = 0;
  if (nbr == 1 || nbr == 2 || nbr == 4)
    res += my_putnbr(va_arg(ap, int));
  else if (nbr == 3)
    res += nbr_tobase(va_arg(ap, int), "01234567", "");
  else if (nbr == 5)
    res += nbr_tobase(va_arg(ap, int), "0123456789abcdef", "");
  else if (nbr == 6)
    res += nbr_tobase(va_arg(ap, int), "0123456789ABCDEF", "");
  else if (nbr == 8)
    res += nbr_tobase(va_arg(ap, int), "01", "");
  else if (nbr == 0)
    res += my_putchar(va_arg(ap, int));
  else if (nbr == 7)
    res += nbr_tobase(va_arg(ap, int), "0123456789abcdef", "0x");
  return (res);
}
