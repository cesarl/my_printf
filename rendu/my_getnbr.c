/*
** my_getnbr.c for my_getnbr in /home/leblic_c//Documents/lib
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Wed Mar 21 12:54:11 2012 cesar leblic
** Last update Fri Mar 23 17:11:56 2012 cesar leblic
*/

int	my_getnbr(char *str)
{
  int	res;
  int	counter;
  int	sign;

  counter = 0;
  sign = 1;
  res = 0;
  while (str[counter])
    {
      if (str[counter] == '-')
	sign *= -1;
      else if (my_char_isnum(str[counter]) == 1)
	res = res * 10 + (str[counter] - 48);
      else if (str[counter] != '+')
	return (res * sign);
      counter += 1;
    }
  return (res * sign);
}
