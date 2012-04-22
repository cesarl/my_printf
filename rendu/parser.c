#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
int	parser(char *str, va_list ap)
{
  int	cnt;
  t_arg	*args;
  t_arg *tmp;
  int	res;

  cnt = 0;
  args = NULL;
  res = 0;
  while (str[cnt])
    {
      if (str[cnt] == '%')
	{
	  tmp = malloc(sizeof(*tmp));
	  cnt = put_flags(cnt + 1, str, tmp);
	  cnt = put_width(cnt, str, tmp);
	  cnt = put_precision(cnt, str, tmp);
	  cnt = put_specifier(cnt, str, tmp);
	  my_push_args(&args, tmp);
	}
      cnt += 1;
    }
  res += print_flags(args, ap);
  res += print_spec(args, ap);
  return (res);
}
