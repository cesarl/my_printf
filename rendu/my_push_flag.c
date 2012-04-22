/*
** my_push_flag.c for push_flag in /home/leblic_c//Documents/my_printf/rendu
** 
** Made by cesar leblic
** Login   <leblic_c@epitech.net>
** 
** Started on  Sun Apr 22 16:42:02 2012 cesar leblic
** Last update Sun Apr 22 16:42:08 2012 cesar leblic
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
int     my_push_flag(t_flag **list, int value)
{
  t_flag *element;
  t_flag *tmp;

  tmp = *list;
  element = malloc(sizeof(*element));
  if (element == NULL)
    return (1);
  element->data = value;
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
