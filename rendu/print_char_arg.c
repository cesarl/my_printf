int	print_char_arg(int nbr, va_list ap)
{
  int	res;

  res = 0;
  if (nbr == 10) //s
    res += my_putstr(va_arg(ap, char *));
  else if(nbr == 9) //S 
    res += my_putallstr(va_arg(ap, char *));
  return (res);
}
