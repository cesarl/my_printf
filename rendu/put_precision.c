#include "my_printf.h"
int	put_precision(int cnt, char *str, t_arg *args)
{
  int	start;

  if (str[cnt] != '.')
    {
      args->precision = -1;
      return (cnt);
    }
  start = ++cnt;
  while (my_char_isnum(str[cnt]) == 1)
    cnt += 1;
  if (start != cnt)
    args->precision = my_getnbr(cpy_str(str, start, cnt));
  else
    args->precision = -1;
  return (cnt);  
}
