#include "my_printf.h"
int	nbr_tobase(int n, char *base, char *supplement)
{
  int	len;
  int	div;
  int	res;

  len = my_strlen(base);
  div = 1;
  res = 0;
  if (supplement)
    res += my_putstr(supplement);
  while (len <= n / div)
    div *= len;
  while (div)
    {
      res += my_putchar(base[n / div % len]);
      div /= len;
    }
  return (res);
}
