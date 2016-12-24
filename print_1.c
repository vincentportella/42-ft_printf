/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:41:51 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 03:30:54 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_assist(char **t, char **p, char **k, t_format *format)
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
}

void	print_ptr(char **s, t_format *format, void *arg)
{
	char *t;
	char *p;
	char *k;

	if (format->type == 1)
		*s = ft_ltoa_base((unsigned long)arg, 16, "0123456789abcdef");
	else
		*s = ft_ltoa_base((unsigned long)arg, 16, "0123456789ABCDEF");
	format_setup_1(s, format, (unsigned long)arg, &k);
	format_setup_2(*s, format, &p, &k);
	ptr_assist(&t, &p, &k, format);
	k = format->type == 1 ? ft_strjoin("0x", p) : ft_strjoin("0X", p);
	ft_strdel(&p);
	p = ft_strjoin(k, *s);
	ft_strdel(s);
	*s = format->flag->minus ? ft_strjoin(p, t) : ft_strjoin(t, p);
	ft_strdel(&p);
	ft_strdel(&t);
	ft_strdel(&k);
}

void	print_chr(char **s, t_format *format, void *arg)
{
	int i;

	*s = ft_strnew(1);
	*s[0] = (char)arg;
	if (format->min_width > 0)
	{
		ft_strdel(s);
		*s = ft_strnew(format->min_width);
		if ((i = -1) && !format->flag->minus)
		{
			while (++i < format->min_width - 1)
				(*s)[i] = format->flag->zero ? 48 : 32;
			(*s)[i] = (char)arg;
		}
		else
		{
			(*s)[++i] = (char)arg;
			while (++i < format->min_width)
				(*s)[i] = format->flag->zero ? 48 : 32;
		}
	}
}

void	ch2_assist(char **s, void *arg, int *d)
{
	if ((int)arg < 256)
	{
		*s = ft_strnew(1);
		(*s)[0] = (int)arg - 256;
	}
	else
		*s = wchar_to_char((wchar_t)arg);
	*d = ft_strlen(*s);
}

void	print_ch2(char **s, t_format *format, void *arg)
{
	int		i;
	int		d;
	int		h;
	char	*t;

	ch2_assist(s, arg, &d);
	if (format->min_width > 0 && (h = -1))
	{
		ft_strdel(s);
		t = wchar_to_char((wchar_t)arg);
		*s = ft_strnew(format->min_width + d - 1);
		if ((i = -1) && !format->flag->minus)
		{
			while (++i < format->min_width - 1)
				(*s)[i] = format->flag->zero ? 48 : 32;
			while (++h < d)
				(*s)[i + h] = t[h];
		}
		else
		{
			(*s)[++i] = (char)arg;
			while (++i < format->min_width)
				(*s)[i] = format->flag->zero ? 48 : 32;
		}
	}
}
