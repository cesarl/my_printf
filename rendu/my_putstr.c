/*
** my_putstr.c for putstr in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:43:08 2012 cesar leblic
** Last update Sun Apr 22 16:43:16 2012 cesar leblic
*/

#include "my.h"
int	my_putstr(char *s)
{
  int	counter;

  counter = 0;
  while (s[counter])
    {
      my_putchar(s[counter]);
      counter += 1;
    }
  return (counter);
}
