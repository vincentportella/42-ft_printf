/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 22:55:11 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 06:01:20 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_setup_1(char **s, t_format *format, unsigned long arg, char **k)
{
	int len;

	len = ft_strlen(*s);
	if (format->period && format->precision < len && !arg)
	{
		len = format->precision < 0 ? 0 : format->precision;
		*k = ft_strsub(*s, ft_strlen(*s) - len, len);
		ft_strdel(s);
		*s = ft_strdup(*k);
		ft_strdel(k);
	}
}

void	format_setup_2(char *s, t_format *format, char **p, char **k)
{
	format_precision(s, format, p, k);
	!(*p) ? *p = ft_strdup("") : 0;
	format_width(s, format, p, k);
	!(*k) ? *k = ft_strdup("") : 0;
}

void	format_chr(char **s, t_format *format, void *arg)
{
	if (format->length == 3 || format->length == 4 || format->type == 14)
		print_ch2(s, format, arg);
	else
		print_chr(s, format, arg);
}

void	format_str(char **s, t_format *format, void *arg)
{
	if (format->length == 3 || format->length == 4 || format->type == 4)
		print_st2(s, format, arg);
	else
		print_str(s, format, arg);
}

void	format_bin(char **s, t_format *format, void *arg)
{
	if (format->length == 1 && format->type != 16)
		print_bin(s, format, (unsigned char)arg);
	else if (format->length == 2 && format->type != 16)
		print_bin(s, format, (unsigned short)arg);
	else if (format->length == 3 || format->length == 4 || format->type != 16)
		print_bin(s, format, (unsigned long)arg);
	else if (format->length == 5)
		print_bin(s, format, (unsigned long)arg);
	else if (format->length == 6)
		print_bin(s, format, (unsigned long)arg);
	else
		print_bin(s, format, (unsigned int)arg);
}
