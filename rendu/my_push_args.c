/*
** my_push_args.c for push_args in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:41:42 2012 cesar leblic
** Last update Sun Apr 22 16:51:07 2012 cesar leblic
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
int     my_push_args(t_arg **list, t_arg *element)
{
  t_arg *tmp;

  tmp = *list;
  element->next = NULL;
  if ((*list) == NULL)
    {
      (*list) = element;
      return (1);
    }
  while ((*list)->next != NULL)
    {
      (*list) = (*list)->next;
    }
  (*list)->next = element;
  (*list) = tmp;
  return (0);
}
