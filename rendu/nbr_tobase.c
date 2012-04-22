/*
** nbr_tobase.c for nbr_tobase in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:43:56 2012 cesar leblic
** Last update Sun Apr 22 16:44:09 2012 cesar leblic
*/

#include "my.h"
int	nbr_tobase(int n, char *base, char *supplement)
{
  int	len;
  int	div;
  int	res;

  len = my_strlen(base);
  div = 1;
  res = 0;
  if (supplement)
    res += my_putstr(supplement);
  while (len <= n / div)
    div *= len;
  while (div)
    {
      res += my_putchar(base[n / div % len]);
      div /= len;
    }
  return (res);
}
