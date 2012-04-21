
#ifndef		__MY_PRINTF__
#define		__MY_PRINTF__

typedef struct	s_flag
{
  int		data;
  struct	s_flag *next;
} t_flag;

typedef struct	s_arg
{
  t_flag	*flags;
  int		width;
  int		precision;
  int		length;
  int		specifier;
  char		fakespec;
  struct	s_arg *next;
} t_arg;

char		*cpy_str(char *src, int s, int e);
int		my_push_flag(t_flag **list, int value);
int		is_flags(int cnt, char *str, char *val);
int		put_flags(int cnt, char *str, t_arg *args);
int		put_width(int cnt, char *str, t_arg *args);
int		put_precision(int cnt, char *str, t_arg *args);
int		put_length(int cnt, char *str, t_arg *args);
int		put_specifier(int cnt, char *str, t_arg *args);
void		nbr_tobase(int n, char *base);
void		my_putallstr(char *str);
int		my_push_args(t_arg **list, t_arg *element);
void		print_spaces(t_arg *args);
void		print_flags(t_arg *args, va_list ap);
void		print_spec(t_arg *args, va_list ap);
t_arg		*parser(char *str, va_list ap);
int		my_printf(char *str, ...);

#endif
