/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:13:08 by vportell          #+#    #+#             */
/*   Updated: 2016/12/22 14:31:03 by vportell         ###   ########.fr       */
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

int	g_length;

//*************************************

// REMOVE

# include <stdio.h>

# define c_max 127
# define s_max 32767
# define i_max 2147483647
# define l_max 9223372036854775807

//*************************************

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

int		get_flags(char *s, t_format *format, int *i);
void	get_precision(char *s, t_format *format, int *i);
void	get_length(char *s, t_format *format, int *i);
void	get_type(char *s, t_format *format, int *i);

void	format_precision(char *s, t_format *format, char **p, char **k);
// void	format_precision(t_format *format, int *len, char **temp, char **str);
void	format_sign(char **s, t_format *format, long arg);
// void	format_width(char **s, t_format *format, int *len);
void	format_width(char *s, t_format *format, char **p, char **k);
void	format_space(char **s, t_format *format, char *k);

void	print_ptr(char **s, t_format *format, void *arg);
void	print_chr(char **s, t_format *format, void *arg);
void	print_ch2(char **s, t_format *format, void *arg);
void	print_str(char **s, t_format *format, void *arg);
void	print_st2(char **s, t_format *format, void *arg);

void	print_pct(char **s, t_format **format);

void	print_bin(char **s, t_format *format, unsigned long arg);
void	print_dec(char **s, t_format *format, long arg);
void	print_uns(char **s, t_format *format, unsigned long arg);
void	print_oct(char **s, t_format *format, unsigned long arg);
void	print_hex(char **s, t_format *format, unsigned long arg);

void	format_chr(char **s, t_format *format, void *arg);
void	format_str(char **s, t_format *format, void *arg);

void	format_bin(char **s, t_format *format, void *arg);
void	format_dec(char **s, t_format *format, void *arg);
void	format_uns(char **s, t_format *format, void *arg);
void	format_oct(char **s, t_format *format, void *arg);
void	format_hex(char **s, t_format *format, void *arg);

char	*wchar_to_char(wchar_t const n);
char	*gen_wstr(wchar_t const *n, int *len);
char	*gen_nwstr(wchar_t const *n, int d);
char	*ft_ltoa_base(long value, int base, char *a);
char	*utoa(long value);

int		ft_printf(const char *format, ...);

#endif