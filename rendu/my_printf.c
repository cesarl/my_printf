int	my_printf(char *str, ...)
{
  va_list	ap;
  int		cnt;
  char		*token;

  cnt = 0;
  va_start(ap, str);
  my_putchar('\n');
  my_putnbr(parser(str, ap));
  my_putchar('\n');
}
