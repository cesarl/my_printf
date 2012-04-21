#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_printf.h"

int	put_flags(int cnt, char *str, t_arg *args)
{
  args->flags = NULL;
  while (is_flags(cnt, str, "-+ #0oOxX") != -1)
    {
      my_push_flag(&args->flags, is_flags(cnt, str, "-+ #0oOxX"));
      cnt += 1;
    }
  return (cnt);
}

int	put_width(int cnt, char *str, t_arg *args)
{
  int	start;

  start = cnt;
  while (my_char_isnum(str[cnt]) == 1)
    cnt += 1;
  if (start != cnt)
    args->width = my_getnbr(cpy_str(str, start, cnt));
  else
    args->width = 0;
  return (cnt);
}

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

int	put_length(int cnt, char *str, t_arg *args)
{

}

int	put_specifier(int cnt, char *str, t_arg *args)
{
  int	mem;

  mem = is_flags(cnt, str, "cdieEfgGosuxXpn%bS");
  if (mem == -1)
    args->fakespec = str[cnt];
  args->specifier = mem;
  return (cnt + 1);
}
