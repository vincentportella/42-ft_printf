/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 01:06:08 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 05:32:57 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_assist_1(char **p, char **k, t_format *format)
{
	int len;

	len = ft_strlen(*k) ? ft_strlen(*p) : 0;
	ft_strdel(p);
	*p = ft_strnew(len);
	*p = ft_memset(*p, 32, len);
	*k = format->flag->zero ? ft_memset(*k, 48, ft_strlen(*k)) : *k;
}

void	str_assist_2(char **s, t_format *format, char **t, char **p)
{
	ft_strdel(t);
	if ((int)ft_strlen(*s) < format->min_width)
	{
		*t = ft_strdup(*s);
		*p = ft_strnew(format->min_width - ft_strlen(*s));
		*p = ft_memset(*p, 32, format->min_width - ft_strlen(*s));
		ft_strdel(s);
		*s = format->flag->minus ? ft_strjoin(*t, *p) : ft_strjoin(*p, *t);
		ft_strdel(t);
		ft_strdel(p);
	}
}

void	print_str(char **s, t_format *format, void *arg)
{
	char *t;
	char *p;
	char *k;
	char *str;

	if (arg)
		str = ft_strdup((char *)arg);
	else
		str = ft_strdup("(null)");
	if (format->period && format->precision < 0)
		format->precision = 0;
	if (format->precision > -1 && format->precision < (int)ft_strlen(str))
		*s = ft_strsub(str, 0, format->precision);
	else
		*s = ft_strdup(str);
	ft_strdel(&str);
	format_setup_2(*s, format, &p, &k);
	str_assist_1(&p, &k, format);
	t = ft_strjoin(p, *s);
	ft_strdel(s);
	ft_strdel(&p);
	*s = format->flag->minus ? ft_strjoin(t, k) : ft_strjoin(k, t);
	ft_strdel(&k);
	str_assist_2(s, format, &t, &p);
}

void	st2_assist(char **s, t_format *format, void *arg, int *len)
{
	char *str;

	if (arg)
		str = gen_wstr((wchar_t *)arg, len);
	else
		str = ft_strdup("(null)");
	if (format->period && format->precision < 0)
		format->precision = 0;
	if (format->precision > -1 && format->precision < (int)ft_strlen(str))
		*s = gen_nwstr((wchar_t *)arg, format->precision);
	else
		*s = ft_strdup(str);
	ft_strdel(&str);
}

void	print_st2(char **s, t_format *format, void *arg)
{
	int		len;
	char	*t;
	char	*p;
	char	*k;

	st2_assist(s, format, arg, &len);
	format_setup_2(*s, format, &p, &k);
	len = ft_strlen(k) ? ft_strlen(p) : 0;
	ft_strdel(&p);
	p = ft_strnew(len);
	k = format->flag->zero ? ft_memset(k, 48, ft_strlen(k)) : k;
	p = ft_memset(p, 32, len);
	t = ft_strjoin(p, *s);
	ft_strdel(s);
	ft_strdel(&p);
	*s = format->flag->minus ? ft_strjoin(t, k) : ft_strjoin(k, t);
	ft_strdel(&t);
	ft_strdel(&k);
}
