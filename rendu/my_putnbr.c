/*
** my_putnbr.c for putnbr in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:42:51 2012 cesar leblic
** Last update Sun Apr 22 16:42:56 2012 cesar leblic
*/

#include "my.h"
int	my_putnbr(int nb)
{
  int	div;
  int	res;

  div = 1;
  res = 0;
  if (nb < 0)
    {
      res += my_putchar('-');
      if (nb > -2147483648)
	nb *= -1;
      else
	{
	  nb = 147483648;
	  res += my_putchar('2');
	}
    }
  while (nb / div >= 10)
    div *= 10;
  while (div)
    {
      res += my_putchar(nb / div % 10 + '0');
      div /= 10;
    }
  return (res);
}
