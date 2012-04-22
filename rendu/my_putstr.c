#include "my_printf.h"
int	my_putstr(char *s)
{
  int	counter;

  counter = 0;
  while (s[counter])
    {
      my_putchar(s[counter]);
      counter += 1;
    }
  return (counter);
}
