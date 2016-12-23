/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:12:01 by vportell          #+#    #+#             */
/*   Updated: 2016/12/22 20:01:10 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	append_str(char *s, char **str)
{
	char *t;

	if (*str)
	{
		t = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(t, s);
		ft_strdel(&t);
	}
	else
		*str = ft_strdup(s);
}

void	print_err(char *s, char **str, t_format **format)
{
	char *p;
	char *t;
	char *n;
	
	if ((*format)->min_width > 0)
	{
		p = ft_strnew((*format)->min_width - 1);
		if ((*format)->flag->zero)
			p = ft_memset(p, 48, (*format)->min_width - 1);
		else
			p = ft_memset(p, 32, (*format)->min_width - 1);
	}
	else
		p = ft_strdup("");
	n = ft_strnew(2);
	n[0] = s[0];
	t = (*format)->flag->minus ? ft_strjoin(n, p) : ft_strjoin(p, n);
	append_str(t, str);
	ft_strdel(&p);
	ft_strdel(&n);
	ft_strdel(&t);
	free((*format)->flag);
	free(*format);
}

void	print_pct(char **str, t_format **format)
{
	char *t;
	char *p;
	char *s;

	s = ft_strnew(2);
	s[0] = '%';
	if ((*format)->min_width > 0)
	{
		p = ft_strnew((*format)->min_width - 1);
		if ((*format)->flag->zero)
			p = ft_memset(p, 48, (*format)->min_width - 1);
		else
			p = ft_memset(p, 32, (*format)->min_width - 1);
		t = ft_strdup(s);
		ft_strdel(&s);
		s = (*format)->flag->minus ? ft_strjoin(t, p) : ft_strjoin(p, t);
		ft_strdel(&t);
		ft_strdel(&p);
	}
	append_str(s, str);
	free((*format)->flag);
	free(*format);
	ft_strdel(&s);
}

void	fill_string(t_format *format, char **s, void *arg)
{
	format->type == 1 ? print_ptr(s, format, arg) : 0;
	format->type == 2 ? format_dec(s, format, arg) : 0;
	format->type == 3 ? format_str(s, format, arg) : 0;
	format->type == 4 ? format_str(s, format, arg) : 0;
	format->type == 5 ? format_dec(s, format, arg) : 0;
	format->type == 6 ? format_dec(s, format, arg) : 0;
	format->type == 7 ? format_oct(s, format, arg) : 0;
	format->type == 8 ? format_oct(s, format, arg) : 0;
	format->type == 9 ? format_uns(s, format, arg) : 0;
	format->type == 10 ? format_uns(s, format, arg) : 0;
	format->type == 11 ? format_hex(s, format, arg) : 0;
	format->type == 12 ? format_hex(s, format, arg) : 0;
	format->type == 13 ? format_chr(s, format, arg) : 0;
	format->type == 14 ? format_chr(s, format, arg) : 0;
	format->type == 15 ? format_bin(s, format, arg) : 0;
	format->type == 16 ? format_bin(s, format, arg) : 0;
	format->type == 17 ? print_ptr(s, format, arg) : 0;
}

void	create_format_struct(t_format **format)
{
	*format = (t_format *)malloc(sizeof(t_format));
	(*format)->min_width = 0;
	(*format)->period = 0;
	(*format)->precision = -1;
	(*format)->length = 0;
	(*format)->type = 0;
	(*format)->flag = (t_flag *)malloc(sizeof(t_flag));
	(*format)->flag->hash = 0;
	(*format)->flag->zero = 0;
	(*format)->flag->plus = 0;
	(*format)->flag->minus = 0;
	(*format)->flag->space = 0;
}

int		parse_format(char *s, int *b, t_format **format)
{
	int	i;

	i = 0;
	create_format_struct(format);
	while (get_flags(s, *format, &i))
		;
	get_precision(s, *format, &i);
	get_length(s, *format, &i);
	get_type(s, *format, &i);
	if ((*format)->type != 18)
		*b  = 1;
	return (i);
}

int		append_result(char *s, void *arg, char **str, t_format **format)
{
	char *tmp;

	if ((*format)->type > 0)
		fill_string(*format, &tmp, arg);
	else
	{
		print_err(s, str, format);
		return (1);
	}
	append_str(tmp, str);
	free((*format)->flag);
	free(*format);
	free(tmp);
	return (0);
}

int		append_filler(char *s, char **str, int i, int c)
{
	char *d;

	if (c)
	{
		d = ft_strsub(s, i - c, c);
		append_str(d, str);
		ft_strdel(&d);
	}
	return (0);
}

// void	read_print(char *s, char **str, va_list *args, int *c)
// {
// 	int		i;
// 	int		b;
	
// 	i = -1;
// 	while (s[++i])
// 	{
// 		if (s[i] == '%')
// 			parse_format(s, str, );
// 	}

// 	// while (s[++i])
// 	// {
// 	// 	if (s[i] == '%' && (*c = append_filler(s, str, i, *c)))
// 	// 		i += parse_format(s + i + 1, va_arg(ap, void *), str);
// 	// 	else
// 	// 		(*c)++;
// 	// }
	
// 	*c = append_filler(s, &str, i, *c);
// }

int		ft_printf(const char *format, ...)
{
	int			i;
	int			c;
	int			b;
	char		*s;
	char		*str;
	t_format	*fmt;
	
	b = 0;
	c = 0;
	i = -1;
	str = 0;
	va_list ap;
	g_length = 0;
	va_start(ap, format);
	s = ft_strdup(format);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			c = append_filler(s, &str, i, c);
			i += parse_format(s + i + 1, &b, &fmt);
			if (b)
				i += append_result(s + i + 1, va_arg(ap, void *), &str, &fmt);
			else
				print_pct(&str, &fmt);
		}
		else
			c++;
		b = 0;
	}
	c = append_filler(s, &str, i, c);
	va_end(ap);
	if (str)
	{
		c = ft_strlen(str);
		ft_putstr(str);
		ft_strdel(&str);
		ft_strdel(&s);
	}
	return (c += g_length);
}

// int		ft_printf(const char *format, ...)
// {
// 	int		i;
// 	int		c;
// 	char	*s;
// 	char	*str;
	
// 	c = 0;
// 	i = -1;
// 	str = 0;
// 	va_list ap;
// 	va_start(ap, format);
// 	s = ft_strdup(format);
// 	while (s[++i])
// 	{
 
// 		if (s[i] == '%')
// 		{
// 			c = append_filler(s, &str, i, c);
// 			i += parse_format(s + i + 1, va_arg(ap, void *), &str);
// 		}
// 		else
// 			c++;


// 		// if (s[i] == '%' && s[i + 1] == '%' && ++i)
// 		// 	c = append_filler(s, &str, i, c + 1);
// 		// else if (s[i] == '%' && s[i + 1] != '%')
// 		// {
// 		// 	c = append_filler(s, &str, i, c);
// 		// 	i += parse_format(s + i + 1, va_arg(ap, void *), &str);
// 		// }
// 		// else
// 		// 	c++;

// 	}
// 	va_end(ap);
// 	c = append_filler(s, &str, i, c);
// 	if (str)
// 	{
// 		c = ft_strlen(str);
// 		ft_putstr(str);
// 		ft_strdel(&str);
// 		ft_strdel(&s);
// 	}
// 	return (c);
// }
