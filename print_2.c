/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:15:19 by vportell          #+#    #+#             */
/*   Updated: 2016/12/22 20:16:52 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_bin(char **s, t_format *format, unsigned long arg)
{
	int len;
	char *t;
	char *p;
	char *k;

	*s = ft_ltoa_base(arg, 2, "01");
	len = ft_strlen(*s);
	if (format->period && format->precision < len && !arg)
	{
		len = format->precision < 0 ? 0 : format->precision;
		k = ft_strsub(*s, ft_strlen(*s) - len, len);
		ft_strdel(s);
		*s = ft_strdup(k);
		ft_strdel(&k);
	}
	format_precision(*s, format, &p, &k);
	!p ? p = ft_strdup("") : 0;
	format_width(*s, format, &p, &k);
	!k ? k = ft_strdup("") : 0;
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

void	print_dec(char **s, t_format *format, long arg)
{
	int i;
	int len;
	char *t;
	char *p;
	char *k;

	*s = utoa(arg);
	len = ft_strlen(*s);
	if (format->period && format->precision < len && !arg)
	{
		len = format->precision < 0 ? 0 : format->precision;
		k = ft_strsub(*s, ft_strlen(*s) - len, len);
		ft_strdel(s);
		*s = ft_strdup(k);
		ft_strdel(&k);
	}
	format_precision(*s, format, &p, &k);
	!p ? p = ft_strdup("") : 0;
	format_width(*s, format, &p, &k);
	!k ? k = ft_strdup("") : 0;
	t = ft_strlen(p) ? ft_strjoin(p, *s) : ft_strjoin(*s, p);
	i = k[0] == '0' ? 0 : 1;
	if (i == 1)
		format_sign(&t, format, arg);
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
	if (i == 0)
		format_sign(s, format, arg);
	ft_strdel(&p);
	ft_strdel(&t);
	ft_strdel(&k);

	if (format->flag->space && !format->flag->plus &&
		(int)ft_strlen(*s) == format->min_width && format->precision == -1)
	{
		p = ft_strsub(*s, 0, ft_strlen(*s) - 1);
		ft_strdel(s);
		*s = ft_strjoin(" ", p);
		ft_strdel(&p);
	}
}

void	print_uns(char **s, t_format *format, unsigned long arg)
{
	int len;
	char *t;
	char *p;
	char *k;

	*s = ft_ltoa_base(arg, 10, "0123456789");
	len = ft_strlen(*s);
	if (format->period && format->precision < len && !arg)
	{
		len = format->precision < 0 ? 0 : format->precision;
		k = ft_strsub(*s, ft_strlen(*s) - len, len);
		ft_strdel(s);
		*s = ft_strdup(k);
		ft_strdel(&k);
	}
	format_precision(*s, format, &p, &k);
	!p ? p = ft_strdup("") : 0;
	format_width(*s, format, &p, &k);
	!k ? k = ft_strdup("") : 0;
	t = ft_strlen(p) ? ft_strjoin(p, *s) : ft_strjoin(*s, p);
	ft_strdel(&p);
	ft_strdel(s);
	if (format->flag->plus && ft_strlen(k) > 0)
	{
		p = ft_strsub(k, 1, ft_strlen(k) - 1);
		ft_strdel(&k);
		k = ft_strdup(p);
		ft_strdel(&p);
	}
	*s = format->flag->minus ? ft_strjoin(t, k) : ft_strjoin(k, t);
	ft_strdel(&t);
	ft_strdel(&k);
}

void	print_oct(char **s, t_format *format, unsigned long arg)
{
	int len;
	char *t;
	char *p;
	char *k;

	*s = ft_ltoa_base(arg, 8, "01234567");
	len = ft_strlen(*s);
	if (format->period && format->precision < len && !arg)
	{
		len = format->precision < 0 ? 0 : format->precision;
		k = ft_strsub(*s, ft_strlen(*s) - len, len);
		ft_strdel(s);
		*s = ft_strdup(k);
		ft_strdel(&k);
	}
	format_precision(*s, format, &p, &k);
	!p ? p = ft_strdup("") : 0;
	format_width(*s, format, &p, &k);
	!k ? k = ft_strdup("") : 0;
	if (format->flag->hash)
	{
		t = ft_strlen(k) > 0 ?
		ft_strsub(k, 1, ft_strlen(k) - 1) : ft_strdup("");
		ft_strdel(&k);
		if (format->flag->zero && !format->flag->minus &&
			format->precision == -1)
		{
			k = arg ? ft_strjoin("0", t) : ft_strdup(t);
			ft_strdel(&t);
			t = ft_strjoin(k, *s);
			ft_strdel(s);
			*s = format->flag->minus ? ft_strjoin(t, p) : ft_strjoin(p, t);
		}
		else
		{
			if ((size_t)format->precision < ft_strlen(p) + ft_strlen(*s) + 1 && arg > 0)
			{
				k = ft_strsub(p, 0, ft_strlen(p) - 1);
				ft_strdel(&p);
				p = ft_strdup(k);
				ft_strdel(&k);
			}
			if (arg > 0 || format->period)
				k = ft_strjoin("0", p);
			else
				k = ft_strdup(p);
			ft_strdel(&p);
			p = ft_strjoin(k, *s);
			ft_strdel(s);
			*s = format->flag->minus ? ft_strjoin(p, t) : ft_strjoin(t, p);
		}
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

void	print_hex(char **s, t_format *format, unsigned long arg)
{
	int len;
	char *t;
	char *p;
	char *k;

	if (format->type == 11)
		*s = ft_ltoa_base(arg, 16, "0123456789abcdef");
	else
		*s = ft_ltoa_base(arg, 16, "0123456789ABCDEF");
	len = ft_strlen(*s);
	if (format->period && format->precision < len && !arg)
	{
		len = format->precision < 0 ? 0 : format->precision;
		k = ft_strsub(*s, ft_strlen(*s) - len, len);
		ft_strdel(s);
		*s = ft_strdup(k);
		ft_strdel(&k);
	}
	format_precision(*s, format, &p, &k);
	!p ? p = ft_strdup("") : 0;
	format_width(*s, format, &p, &k);
	!k ? k = ft_strdup("") : 0;
	if (format->flag->hash && arg)
	{
		t = ft_strlen(k) > 1 ?
		ft_strsub(k, 2, ft_strlen(k) - 2) : ft_strdup("");
		ft_strdel(&k);
		if (format->flag->zero && !format->flag->minus &&
			format->precision == -1)
		{
			k = format->type == 11 ? ft_strjoin("0x", t) : ft_strjoin("0X", t);
			ft_strdel(&t);
			t = ft_strjoin(k, *s);
			ft_strdel(s);
			*s = format->flag->minus ? ft_strjoin(t, p) : ft_strjoin(p, t);
		}
		else
		{
			k = format->type == 11 ? ft_strjoin("0x", p) : ft_strjoin("0X", p);
			ft_strdel(&p);
			p = ft_strjoin(k, *s);
			ft_strdel(s);
			*s = format->flag->minus ? ft_strjoin(p, t) : ft_strjoin(t, p);
		}
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
















































