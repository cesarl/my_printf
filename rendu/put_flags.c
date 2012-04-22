#include <stdlib.h>
#include "my_printf.h"
int	put_flags(int cnt, char *str, t_arg *args)
{
  args->flags = NULL;
  while (is_flags(cnt, str, "-+ #0") != -1)
    {
      my_push_flag(&args->flags, is_flags(cnt, str, "-+ #0"));
      cnt += 1;
    }
  return (cnt);
}
