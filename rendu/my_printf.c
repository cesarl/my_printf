/*
** my_printf.c for my_printf in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:41:16 2012 cesar leblic
** Last update Sun Apr 22 16:41:17 2012 cesar leblic
*/

#include <stdarg.h>
#include "my.h"
int	my_printf(char *str, ...)
{
  va_list	ap;
  int		cnt;

  cnt = 0;
  va_start(ap, str);
  cnt = parser(str, ap);
  return (cnt);
}
