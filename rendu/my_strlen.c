/*
** my_strlen.c for my_strlen in /home/leblic_c//Documents/lib
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Wed Mar 21 12:31:49 2012 cesar leblic
** Last update Wed Mar 21 12:32:59 2012 cesar leblic
*/

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    counter += 1;
  return (counter);
}
