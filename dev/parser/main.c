
#include <stdarg.h>
#include "my.h"

int	my_printf(char *str, ...)
{
  va_list	ap;
  int		cnt;
  char		*token;

  cnt = 0;
  va_start(ap, str);
  while (str[cnt])
    {
      if (str[cnt] == '%')
	{
	  if (str[cnt + 1] == 's')
	    {
	      my_putstr(va_arg(ap, char *));
	      cnt += 1;
	    }
	  else if (str[cnt + 1] == 'd')
	    {
	      my_put_nbr(va_arg(ap, int));
	      cnt += 1;
	    }
	}
      else
	my_putchar(str[cnt]);
      cnt += 1;
    }
}

int	main()
{
  my_printf("%s\n%d\n\n", "tu va bien ?", 2589);
  long lday   = 5;
  long lmonth = 1;
  long lyear  = 2006;
  my_printf("the date is: %02ld.%02ld.%04ld\n",lday,lmonth,lyear);
}
