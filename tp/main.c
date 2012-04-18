/* http://www.linux-kheops.com/doc/man/manfr/man-html-0.9/man3/stdarg.3.html */
/* http://www.codingunit.com/printf-format-specifiers-format-conversions-and-formatted-output */

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int	fct(int fmt, ...)
{
  va_list ap;
  int     d;
  char	  *s;

  d = 0;
  va_start  (ap, fmt);
  while (d < fmt)
    {
      s = va_arg (ap, char *);
      my_putstr(s);
      d++;
    }
  va_end (ap);

  //  printf("\n%d\n%s\n%s", 15, "blop", "fick");
}

int	main()
{
  //fct(3, "ca ca", "prout", " bidule chouette");
  printf("%#o", "merde");
}
