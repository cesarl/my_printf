/*
** print_flags.c for print_flags in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:45:49 2012 cesar leblic
** Last update Sun Apr 22 16:51:52 2012 cesar leblic
*/

#include <stdarg.h>
#include "my.h"

int	print_flags(t_arg *args, va_list ap)
{
  int	res;

  res = 0;
  if (args)
    {
      while (args->flags)
	{
	  if (args->flags->data == 2)
	    res += print_spaces(args);
	  args->flags = args->flags->next;
	}
    }
  return (res);
}
