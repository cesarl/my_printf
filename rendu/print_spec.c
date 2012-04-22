#include <stdarg.h>
#include "my_printf.h"
int    	print_spec(t_arg *args, va_list ap)
{
  int	res;

  res = 0;
  while (args)
    { 
      if(args->specifier >= 0 && args->specifier <= 8)
	res += print_nbr_arg(args->specifier, ap);
      else if(args->specifier >= 9 && args->specifier <= 10)
	res += print_char_arg(args->specifier, ap);
      else if(args->specifier == 11)
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
