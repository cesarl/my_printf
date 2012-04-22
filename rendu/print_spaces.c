int	print_spaces(t_arg *args)
{
  int	c;

  c = 0;
  if (args->width > 0)
    {
      while (c < args->width)
	{
	  my_putchar(' ');
	  c += 1;
	}
    }
  return (args->width);
}
