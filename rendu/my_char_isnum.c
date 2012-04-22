/*
** my_char_isnum.c for my_char_isnum in /home/leblic_c//Documents/lib
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Wed Mar 21 14:05:54 2012 cesar leblic
** Last update Thu Mar 22 16:21:37 2012 cesar leblic
*/

int     my_char_isnum(char c)
{
  if (c >= 48 && c <= 57)
    return (1);
  else
    return (0);
}
