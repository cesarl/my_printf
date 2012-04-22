/*
** print_spec.c for print_spec in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:46:47 2012 cesar leblic
** Last update Sun Apr 22 16:54:56 2012 cesar leblic
*/

#include <stdarg.h>
#include "my.h"
int    	print_spec(t_arg *args, va_list ap)
{
  int	res;

  res = 0;
  while (args)
    {
      if (args->specifier >= 0 && args->specifier <= 8)
	res += print_nbr_arg(args->specifier, ap);
      else if (args->specifier >= 9 && args->specifier <= 10)
	res += print_char_arg(args->specifier, ap);
      else if (args->specifier == 11)
	{
	  res += my_putchar('%');
	  args = args->next;
	}
      else
	{
	  res += my_putchar('%');
	  res += my_putchar(args->fakespec);
	}
      args = args->next;
    }
  return (res);
}
