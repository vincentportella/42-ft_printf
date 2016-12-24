/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_segments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:41:44 by vportell          #+#    #+#             */
/*   Updated: 2016/12/23 22:21:20 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_precision(char *s, t_format *format, char **p, char **k)
{
	*p = 0;
	*k = 0;
	if (format->precision > (int)ft_strlen(s))
	{
		*p = ft_strnew(format->precision - ft_strlen(s));
		*p = ft_memset(*p, 48, format->precision - ft_strlen(s));
	}
}

void	format_sign(char **s, t_format *format, long arg)
{
	char *t;

	if (format->flag->plus)
	{
		t = ft_strdup(*s);
		ft_strdel(s);
		*s = (int)arg >= 0 ? ft_strjoin("+", t) : ft_strjoin("-", t);
		ft_strdel(&t);
	}
	else if (arg < 0)
	{
		t = ft_strdup(*s);
		ft_strdel(s);
		*s = ft_strjoin("-", t);
		ft_strdel(&t);
	}
}

void	format_width(char *s, t_format *format, char **p, char **k)
{
	int		i;
	int		c;

	if (format->min_width > format->precision && format->min_width > 0)
	{
		c = (format->flag->zero && !format->flag->minus &&
			format->precision == -1) ? 48 : 32;
		i = format->min_width - (ft_strlen(s) + ft_strlen(*p));
		if (i > 0)
		{
			*k = ft_strnew(i);
			*k = ft_memset(*k, c, i);
		}
	}
}

void	format_space(char **s, t_format *format, char *k)
{
	char *t;
	char *p;

	if (format->flag->space && !(format->flag->plus) && **s != '-')
	{
		if (ft_strlen(k) == 0)
		{
			p = ft_strdup(" ");
			t = ft_strdup(*s);
			ft_strdel(s);
			*s = ft_strjoin(p, t);
			ft_strdel(&p);
			ft_strdel(&t);
		}
	}
}
