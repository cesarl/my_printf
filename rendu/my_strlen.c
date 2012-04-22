/*
** my_strlen.c for my_strlen in /home/leblic_c//Documents/lib
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Wed Mar 21 12:31:49 2012 cesar leblic
** Last update Sun Apr 22 16:43:38 2012 cesar leblic
*/

#include "my.h"
int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    counter += 1;
  return (counter);
}
