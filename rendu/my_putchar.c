/*
** my_putchar.c for putchar in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:42:40 2012 cesar leblic
** Last update Sun Apr 22 16:42:41 2012 cesar leblic
*/

#include "my.h"
int	my_putchar(char c)
{
  write (1, &c, 1);
  return (1);
}
