##
## Makefile for Evalexpr Makefile in /home/leblic_c//Documents/Piscine/evalexpr
## 
## Made by cesar leblic
## Login   <leblic_c@epitech.net>
## 
## Started on  Thu Mar 29 15:10:19 2012 cesar leblic
## Last update Thu Apr  5 11:36:03 2012 cesar leblic
##

CC      = gcc

RM	= rm -f

NAME	= libmy.a

SRCS	= cpy_str.c \
	  is_flag.c \
	  my_printf.c \
	  my_push_args.c \
	  my_push_flag.c \
	  my_putallstr.c \
	  my_putchar.c \
	  my_putnbr.c \
	  nbr_tobase.c \
	  parser.c \
	  print_char_arg.c \
	  print_nbr_arg.c \
	  print_spaces.c \
	  print_spec.c \
	  put_flags.c \
	  put_precision.c \
	  put_specifier.c \
	  put_width.c

OBJS	= $(SRCS:.c=.o)

all:	$(OBJS)
	ar rc $(NAME) $(OBJS);
	ranlib $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all