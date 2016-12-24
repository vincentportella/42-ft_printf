/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:13:08 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 06:02:35 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <wchar.h>
# include <locale.h>
# include "libft/libft.h"

int	g_i;

typedef struct		s_flag
{
	int				hash;
	int				zero;
	int				plus;
	int				minus;
	int				space;
}					t_flag;

typedef struct		s_format
{
	t_flag			*flag;
	int				min_width;
	int				period;
	int				precision;
	int				length;
	int				type;
}					t_format;

typedef struct		s_string
{
	char			*str;
	int				len;
	struct s_string	*next;
}					t_string;

int					get_flags(char *s, t_format *format, int *i);
void				get_precision(char *s, t_format *format, int *i);
void				get_length(char *s, t_format *format, int *i);
void				get_type(char *s, t_format *format, int *i);

void				format_precision(char *s, t_format *format,
					char **p, char **k);
void				format_sign(char **s, t_format *format, long arg);
void				format_width(char *s, t_format *format, char **p, char **k);
void				format_space(char **s, t_format *format, char *k);

void				print_ptr(char **s, t_format *format, void *arg);
void				print_chr(char **s, t_format *format, void *arg);
void				print_ch2(char **s, t_format *format, void *arg);

void				print_bin(char **s, t_format *format, unsigned long arg);
void				print_dec(char **s, t_format *format, long arg);
void				print_hex(char **s, t_format *format, unsigned long arg);

void				print_uns(char **s, t_format *format, unsigned long arg);
void				print_oct(char **s, t_format *format, unsigned long arg);

void				print_str(char **s, t_format *format, void *arg);
void				print_st2(char **s, t_format *format, void *arg);

void				print_err(char *s, t_string **str, t_format **format);
void				print_pct(t_string **str, t_format **format);

void				format_dec(char **s, t_format *format, void *arg);
void				format_uns(char **s, t_format *format, void *arg);
void				format_oct(char **s, t_format *format, void *arg);
void				format_hex(char **s, t_format *format, void *arg);

void				format_setup_1(char **s, t_format *format,
					unsigned long arg, char **k);
void				format_setup_2(char *s, t_format *format,
					char **p, char **k);
void				format_chr(char **s, t_format *format, void *arg);
void				format_str(char **s, t_format *format, void *arg);
void				format_bin(char **s, t_format *format, void *arg);

t_string			*create_string(char *str);
void				fill_string(t_format *format, char **s, void *arg);
int					parse_format(char *s, int *b, t_format **format);

char				*wchar_to_char(wchar_t n);
char				*gen_wstr(wchar_t *n, int *len);
char				*gen_nwstr(wchar_t *n, int d);
char				*ft_ltoa_base(long value, int base, char *a);
char				*utoa(long value);

void				append_str(char *s, t_string **str, t_format *format);
int					append_result(char *s, void *arg,
					t_string **str, t_format **format);
int					append_filler(char *s, t_string **str, int i, int c);

int					ft_printf(const char *format, ...);

#endif
