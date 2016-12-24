/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:12:01 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 06:11:57 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_setup(const char *format, char **s, int *c)
{
	*c = 0;
	g_i = -1;
	*s = ft_strdup(format);
}

int		print_string(char **s, t_string **str, int *c)
{
	t_string *tmp;

	*c = append_filler(*s, str, g_i, *c);
	while (*str)
	{
		if ((*str)->len > 0)
		{
			g_i = -1;
			while (++(g_i) < (*str)->len)
				ft_putchar(((*str)->str)[g_i]);
			*c += (*str)->len;
		}
		else if ((*str)->str)
		{
			ft_putstr((*str)->str);
			*c += ft_strlen((*str)->str);
		}
		tmp = *str;
		*str = (*str)->next;
		ft_strdel(&(tmp->str));
		free(tmp);
	}
	ft_strdel(s);
	return (*c);
}

int		ft_printf(const char *format, ...)
{
	int			c;
	char		*s;
	va_list		ap;
	t_format	*fmt;
	t_string	*str;

	str = 0;
	va_start(ap, format);
	printf_setup(format, &s, &c);
	while (s[++g_i])
	{
		if (s[g_i] == '%' && !(c = append_filler(s, &str, g_i, c)))
		{
			g_i += parse_format(s + g_i + 1, &c, &fmt);
			c ? g_i += append_result(s + g_i + 1, va_arg(ap, void *),
				&str, &fmt) : print_pct(&str, &fmt);
			c = 0;
		}
		else
			c++;
	}
	va_end(ap);
	return (print_string(&s, &str, &c));
}
