/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:15:19 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 03:27:58 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_bin(char **s, t_format *format, unsigned long arg)
{
	char *t;
	char *p;
	char *k;

	*s = ft_ltoa_base(arg, 2, "01");
	format_setup_1(s, format, arg, &k);
	format_setup_2(*s, format, &p, &k);
	t = ft_strlen(p) ? ft_strjoin(p, *s) : ft_strjoin(*s, p);
	ft_strdel(&p);
	ft_strdel(s);
	if (format->flag->plus && ft_strlen(k) > 0)
	{
		p = ft_strsub(k, 1, ft_strlen(k) - 1);
		ft_strdel(&k);
		k = ft_strdup(p);
	}
	*s = format->flag->minus ? ft_strjoin(t, k) : ft_strjoin(k, t);
	ft_strdel(&p);
	ft_strdel(&t);
	ft_strdel(&k);
}

void	dec_assist(char **s, t_format *format, char **p, char **k)
{
	ft_strdel(p);
	ft_strdel(k);
	if (format->flag->space && !format->flag->plus &&
		(int)ft_strlen(*s) == format->min_width && format->precision == -1)
	{
		*p = ft_strsub(*s, 1, ft_strlen(*s) - 1);
		ft_strdel(s);
		*s = ft_strjoin(" ", *p);
		ft_strdel(p);
	}
}

void	print_dec(char **s, t_format *format, long arg)
{
	int		i;
	char	*t;
	char	*p;
	char	*k;

	*s = utoa(arg);
	format_setup_1(s, format, arg, &k);
	format_setup_2(*s, format, &p, &k);
	t = ft_strlen(p) ? ft_strjoin(p, *s) : ft_strjoin(*s, p);
	i = k[0] == '0' ? 0 : 1;
	i == 1 ? format_sign(&t, format, arg) : 0;
	format_space(&t, format, k);
	ft_strdel(&p);
	ft_strdel(s);
	if ((format->flag->plus || arg < 0) && ft_strlen(k) > 0)
	{
		p = ft_strsub(k, 1, ft_strlen(k) - 1);
		ft_strdel(&k);
		k = ft_strdup(p);
	}
	*s = format->flag->minus ? ft_strjoin(t, k) : ft_strjoin(k, t);
	i == 0 ? format_sign(s, format, arg) : 0;
	ft_strdel(&t);
	dec_assist(s, format, &p, &k);
}

int		hex_assist(char **t, char **p, char **k, t_format *format)
{
	*t = ft_strlen(*k) > 1 ?
	ft_strsub(*k, 2, ft_strlen(*k) - 2) : ft_strdup("");
	ft_strdel(k);
	if (format->flag->zero && !format->flag->minus &&
		format->precision == -1)
	{
		*k = ft_strdup(*p);
		ft_strdel(p);
		*p = ft_strdup(*t);
		ft_strdel(t);
		*t = ft_strdup(*k);
		ft_strdel(k);
	}
	*k = format->type == 11 ? ft_strjoin("0x", *p) : ft_strjoin("0X", *p);
	ft_strdel(p);
	return (1);
}

void	print_hex(char **s, t_format *format, unsigned long arg)
{
	char *t;
	char *p;
	char *k;

	if (format->type == 11)
		*s = ft_ltoa_base(arg, 16, "0123456789abcdef");
	else
		*s = ft_ltoa_base(arg, 16, "0123456789ABCDEF");
	format_setup_1(s, format, arg, &k);
	format_setup_2(*s, format, &p, &k);
	if (format->flag->hash && arg && hex_assist(&t, &p, &k, format))
	{
		p = ft_strjoin(k, *s);
		ft_strdel(s);
		*s = format->flag->minus ? ft_strjoin(p, t) : ft_strjoin(t, p);
	}
	else
	{
		t = ft_strlen(p) ? ft_strjoin(p, *s) : ft_strjoin(*s, p);
		ft_strdel(s);
		*s = format->flag->minus ? ft_strjoin(t, k) : ft_strjoin(k, t);
	}
	ft_strdel(&p);
	ft_strdel(&t);
	ft_strdel(&k);
}
