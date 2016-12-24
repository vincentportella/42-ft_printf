/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:23:11 by vportell          #+#    #+#             */
/*   Updated: 2016/12/23 22:55:31 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_dec(char **s, t_format *format, void *arg)
{
	if (format->length == 1 && format->type != 6)
		print_dec(s, format, (char)arg);
	else if (format->length == 2 && format->type != 6)
		print_dec(s, format, (short)arg);
	else if (format->length == 3 || format->length == 4 || format->type == 6)
		print_dec(s, format, (long)arg);
	else if (format->length == 5)
		print_dec(s, format, (long)arg);
	else if (format->length == 6)
		print_dec(s, format, (long)arg);
	else
		print_dec(s, format, (int)arg);
}

void	format_uns(char **s, t_format *format, void *arg)
{
	if (format->length == 1 && format->type != 10)
		print_uns(s, format, (unsigned char)arg);
	else if (format->length == 2 && format->type != 10)
		print_uns(s, format, (unsigned short)arg);
	else if (format->length == 3 || format->length == 4 || format->type == 10)
		print_uns(s, format, (unsigned long)arg);
	else if (format->length == 5)
		print_uns(s, format, (unsigned long)arg);
	else if (format->length == 6)
		print_uns(s, format, (unsigned long)arg);
	else
		print_uns(s, format, (unsigned int)arg);
}

void	format_oct(char **s, t_format *format, void *arg)
{
	if (format->length == 1 && format->type != 8)
		print_oct(s, format, (unsigned char)arg);
	else if (format->length == 2 && format->type != 8)
		print_oct(s, format, (unsigned short)arg);
	else if (format->length == 3 || format->length == 4 || format->type == 8)
		print_oct(s, format, (unsigned long)arg);
	else if (format->length == 5)
		print_oct(s, format, (unsigned long)arg);
	else if (format->length == 6)
		print_oct(s, format, (unsigned long)arg);
	else
		print_oct(s, format, (unsigned int)arg);
}

void	format_hex(char **s, t_format *format, void *arg)
{
	if (format->length == 1)
		print_hex(s, format, (unsigned char)arg);
	else if (format->length == 2)
		print_hex(s, format, (unsigned short)arg);
	else if (format->length == 3 || format->length == 4)
		print_hex(s, format, (unsigned long)arg);
	else if (format->length == 5)
		print_hex(s, format, (unsigned long)arg);
	else if (format->length == 6)
		print_hex(s, format, (unsigned long)arg);
	else
		print_hex(s, format, (unsigned int)arg);
}
