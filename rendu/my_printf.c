#include <stdarg.h>
#include "my_printf.h"
int	my_printf(char *str, ...)
{
  va_list	ap;
  int		cnt;

  cnt = 0;
  va_start(ap, str);
  cnt = parser(str, ap);
  return (cnt);
}
