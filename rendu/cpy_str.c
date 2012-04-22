/*
** cpy_str.c for cpy_str in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:39:32 2012 cesar leblic
** Last update Sun Apr 22 16:39:38 2012 cesar leblic
*/

#include <stdlib.h>
#include "my.h"
char	*cpy_str(char *src, int s, int e)
{
  char	*cpy;
  int	cnt;
  int	str_cnt;

  cpy = malloc(sizeof(char) * (e - s));
  if (cpy == NULL)
    return (NULL);
  cnt = 0;
  str_cnt = s;
  while (cnt <= (e - s))
    {
      cpy[cnt] = src[str_cnt];
      cnt += 1;
      str_cnt += 1;
    }
  cpy[cnt] = '\0';
  return (cpy);
}
