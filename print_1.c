/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:41:51 by vportell          #+#    #+#             */
/*   Updated: 2016/12/22 20:03:14 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(char **s, t_format *format, void *arg)
{
	int len;
	char *t;
	char *p;
	char *k;

	if (format->type == 1)
		*s = ft_ltoa_base((unsigned long)arg, 16, "0123456789abcdef");
	else
		*s = ft_ltoa_base((unsigned long)arg, 16, "0123456789ABCDEF");
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
	t = ft_strlen(k) > 1 ?
	ft_strsub(k, 2, ft_strlen(k) - 2) : ft_strdup("");
	ft_strdel(&k);
	if (format->flag->zero && !format->flag->minus &&
		format->precision == -1)
	{
		k = format->type == 1 ? ft_strjoin("0x", t) : ft_strjoin("0X", t);
		ft_strdel(&t);
		t = ft_strjoin(k, *s);
		ft_strdel(s);
		*s = format->flag->minus ? ft_strjoin(t, p) : ft_strjoin(p, t);
	}
	else
	{
		k = format->type == 1 ? ft_strjoin("0x", p) : ft_strjoin("0X", p);
		ft_strdel(&p);
		p = ft_strjoin(k, *s);
		ft_strdel(s);
		*s = format->flag->minus ? ft_strjoin(p, t) : ft_strjoin(t, p);
	}
	ft_strdel(&p);
	ft_strdel(&t);
	ft_strdel(&k);
}

void	print_chr(char **s, t_format *format, void *arg)
{
	char *t;
	char *p;

	*s = ft_strnew(2);
	*s[0] = (char)arg;
	if (arg == NULL || (char)arg == '\0')
		g_length++;
	if (format->min_width > 0)
	{
		p = ft_strnew(format->min_width - 1);
		if (format->flag->zero)
			p = ft_memset(p, 48, format->min_width - 1);
		else
			p = ft_memset(p, 32, format->min_width - 1);
		t = ft_strdup(*s);
		ft_strdel(s);
		*s = format->flag->minus ? ft_strjoin(t, p) : ft_strjoin(p, t);
		ft_strdel(&t);
		ft_strdel(&p);
	}
}

void	print_ch2(char **s, t_format *format, void *arg)
{
	char *t;
	char *p;

	if (*s)
		*s = wchar_to_char((wchar_t)arg);
	else
		*s = ft_strdup("");
	if (arg == NULL || !ft_strcmp("", *s))
		g_length++;
	if (format->min_width > 0)
	{
		p = ft_strnew(format->min_width - 1);
		p = ft_memset(p, 32, format->min_width - 1);
		t = ft_strdup(*s);
		ft_strdel(s);
		*s = format->flag->minus ? ft_strjoin(t, p) : ft_strjoin(p, t);
		ft_strdel(&t);
		ft_strdel(&p);
	}
}

void	print_str(char **s, t_format *format, void *arg)
{
	int len;
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
	format_precision(*s, format, &p, &k);
	!p ? p = ft_strdup("") : 0;
	format_width(*s, format, &p, &k);
	!k ? k = ft_strdup("") : 0;
	len = ft_strlen(k) ? ft_strlen(p) : 0;
	ft_strdel(&p);
	p = ft_strnew(len);
	p = ft_memset(p, 32, len);
	k = format->flag->zero ? ft_memset(k, 48, ft_strlen(k)) : k;
	t = ft_strjoin(p, *s);
	ft_strdel(s);
	ft_strdel(&p);
	*s = format->flag->minus ? ft_strjoin(t, k) : ft_strjoin(k, t);
	ft_strdel(&t);
	if ((int)ft_strlen(*s) < format->min_width)
	{
		t = ft_strdup(*s);
		p = ft_strnew(format->min_width - ft_strlen(*s));
		p = ft_memset(p, 32, format->min_width - ft_strlen(*s));
		ft_strdel(s);
		*s = format->flag->minus ? ft_strjoin(t, p) : ft_strjoin(p, t);
	}
	ft_strdel(&p);
	ft_strdel(&t);
	ft_strdel(&k);
}

void	print_st2(char **s, t_format *format, void *arg)
{
	int len;
	char *t;
	char *p;
	char *k;
	char *str;

	if (arg)
		str = gen_wstr((wchar_t *)arg, &len);
	else
		str = ft_strdup("(null)");
	if (format->period && format->precision < 0)
		format->precision = 0;
	if (format->precision > -1 && format->precision < (int)ft_strlen(str))
		*s = gen_nwstr((wchar_t *)arg, format->precision);
	else
		*s = ft_strdup(str);
	ft_strdel(&str);
	format_precision(*s, format, &p, &k);
	!p ? p = ft_strdup("") : 0;
	format_width(*s, format, &p, &k);
	!k ? k = ft_strdup("") : 0;
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













































































