#ifndef FT_FSTRING_H
# define FT_FSTRING_H

# include "libft.h"
# include <stdarg.h>

typedef char t_fstring_type;
# define FSTRING_CHAR 'c'
# define FSTRING_STRING 's'
# define FSTRING_DECIMAL 'd'
# define FSTRING_INT 'i'
# define FSTRING_UNSIGNED 'u'
# define FSTRING_HEX 'x'
# define FSTRING_HEX_UPPER 'X'
# define FSTRING_POINTER 'p'
# define FSRTING_PERCENT '%'

typedef t_list* t_fstring;
typedef struct s_fstring_content
{
    t_fstring_type	type;
    void			*data;
}   t_fstring_content;

t_fstring   ft_fstring_new_char(char c);

t_fstring   ft_fstring_new_string(t_string str);

t_fstring   ft_fstring_new_decimal(int n);

t_fstring   ft_fstring_new_int(int n);

t_fstring   ft_fstring_new_unsigned(unsigned int n);

t_fstring   ft_fstring_new_hex(unsigned int n);

t_fstring   ft_fstring_new_hex_upper(unsigned int n);

t_fstring   ft_fstring_new_pointer(void *ptr);

void        ft_fstring_clear(t_fstring fstring);

t_fstring   ft_fstring_parsev(const t_string format, va_list args);

t_fstring   ft_fstring_parse(const t_string format, ...);

#endif