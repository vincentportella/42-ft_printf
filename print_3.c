/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 03:26:51 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 03:27:32 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uns(char **s, t_format *format, unsigned long arg)
{
	char *t;
	char *p;
	char *k;

	*s = ft_ltoa_base(arg, 10, "0123456789");
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
		ft_strdel(&p);
	}
	*s = format->flag->minus ? ft_strjoin(t, k) : ft_strjoin(k, t);
	ft_strdel(&t);
	ft_strdel(&k);
}

void	oct_assist_1(char **s, char **t, unsigned long arg)
{
	char *k;

	k = arg ? ft_strjoin("0", *t) : ft_strdup(*t);
	ft_strdel(t);
	*t = ft_strjoin(k, *s);
	ft_strdel(s);
	ft_strdel(&k);
}

int		oct_assist_2(char **s, t_format *format, char **p, unsigned long arg)
{
	char *k;

	if ((size_t)format->precision < ft_strlen(*p) + ft_strlen(*s) + 1
		&& arg > 0)
	{
		k = ft_strsub(*p, 0, ft_strlen(*p) - 1);
		ft_strdel(p);
		*p = ft_strdup(k);
		ft_strdel(&k);
	}
	if (arg > 0 || format->period)
		k = ft_strjoin("0", *p);
	else
		k = ft_strdup(*p);
	ft_strdel(p);
	*p = ft_strjoin(k, *s);
	ft_strdel(s);
	ft_strdel(&k);
	return (1);
}

void	oct_assist_3(char **s, t_format *format, char **p, char **k)
{
	char *t;

	t = ft_strlen(*p) ? ft_strjoin(*p, *s) : ft_strjoin(*s, *p);
	ft_strdel(s);
	*s = format->flag->minus ? ft_strjoin(t, *k) : ft_strjoin(*k, t);
	ft_strdel(k);
	ft_strdel(&t);
}

void	print_oct(char **s, t_format *format, unsigned long arg)
{
	char *t;
	char *p;
	char *k;

	*s = ft_ltoa_base(arg, 8, "01234567");
	format_setup_1(s, format, arg, &k);
	format_setup_2(*s, format, &p, &k);
	if (format->flag->hash)
	{
		t = ft_strlen(k) > 0 ?
		ft_strsub(k, 1, ft_strlen(k) - 1) : ft_strdup("");
		ft_strdel(&k);
		if (format->flag->zero && !format->flag->minus &&
			format->precision == -1)
		{
			oct_assist_1(s, &t, arg);
			*s = ft_strjoin(p, t);
		}
		else if (oct_assist_2(s, format, &p, arg))
			*s = format->flag->minus ? ft_strjoin(p, t) : ft_strjoin(t, p);
		ft_strdel(&t);
	}
	else
		oct_assist_3(s, format, &p, &k);
	ft_strdel(&p);
}
