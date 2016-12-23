/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:49:15 by vportell          #+#    #+#             */
/*   Updated: 2016/12/22 09:01:39 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flags(char *s, t_format *format, int *i)
{
	long n;

	if (s[*i] != '#' && (s[*i] < '0' || s[*i] > '9') &&
		s[*i] != '-' && s[*i] != '+' && s[*i] != ' ')
		return (0);
	if (s[*i] == '#' && ++(*i))
		format->flag->hash = 1;
	else if (s[*i] >= '0' && s[*i] <= '9')
	{
		n = 0;
		if (s[*i] == '0' && ++(*i))
			format->flag->zero = 1;
		while (s[*i] >= '0' && s[*i] <= '9')
			n = n * 10 + s[(*i)++] - 48;
		format->min_width = n;
	}
	else if (s[*i] == '+' && ++(*i))
		format->flag->plus = 1;
	else if (s[*i] == '-' && ++(*i))
		format->flag->minus = 1;
	else if (s[*i] == ' ' && ++(*i))
		format->flag->space = 1;
	return (1);
}

void	get_precision(char *s, t_format *format, int *i)
{
	long n;

	if (s[*i] == '.' && ++(*i))
	{
		format->period = 1;
		if (s[*i] >= '0' && s[*i] <= '9')
		{
			n = 0;
			while (s[*i] >= '0' && s[*i] <= '9')
				n = n * 10 + s[(*i)++] - 48;
			format->precision = n;
		}
	}
}

void	get_length(char *s, t_format *format, int *i)
{
	if (s[*i] == 'h' && s[*i + 1] == 'h' && ((*i) += 2))
		format->length = 1;
	else if (s[*i] == 'h' && ++(*i))
		format->length = 2;
	else if (s[*i] == 'l' && s[*i + 1] == 'l' && ((*i) += 2))
		format->length = 3;
	else if (s[*i] == 'l' && ++(*i))
		format->length = 4;
	else if (s[*i] == 'j' && ++(*i))
		format->length = 5;
	else if (s[*i] == 'z' && ++(*i))
		format->length = 6;
}

void	get_type_2(char *s, t_format *format, int *i)
{
	if (s[*i] == 'X' && ++(*i) && (format->type = 12))
		return ;
	else if (s[*i] == 'c' && ++(*i) && (format->type = 13))
		return ;
	else if (s[*i] == 'C' && ++(*i) && (format->type = 14))
		return ;
	else if (s[*i] == 'b' && ++(*i) && (format->type = 15))
		return ;
	else if (s[*i] == 'B' && ++(*i) && (format->type = 16))
		return ;
	else if (s[*i] == 'P' && ++(*i) && (format->type = 17))
		return ;
	else if (s[*i] == '%' && ++(*i) && (format->type = 18))
		return ;
}

void	get_type(char *s, t_format *format, int *i)
{
	if (s[*i] == 'p' && ++(*i) && (format->type = 1))
		return ;
	else if (s[*i] == 'i' && ++(*i) && (format->type = 2))
		return ;
	else if (s[*i] == 's' && ++(*i) && (format->type = 3))
		return ;
	else if (s[*i] == 'S' && ++(*i) && (format->type = 4))
		return ;
	else if (s[*i] == 'd' && ++(*i) && (format->type = 5))
		return ;
	else if (s[*i] == 'D' && ++(*i) && (format->type = 6))
		return ;
	else if (s[*i] == 'o' && ++(*i) && (format->type = 7))
		return ;
	else if (s[*i] == 'O' && ++(*i) && (format->type = 8))
		return ;
	else if (s[*i] == 'u' && ++(*i) && (format->type = 9))
		return ;
	else if (s[*i] == 'U' && ++(*i) && (format->type = 10))
		return ;
	else if (s[*i] == 'x' && ++(*i) && (format->type = 11))
		return ;
	else
		get_type_2(s, format, i);
}
