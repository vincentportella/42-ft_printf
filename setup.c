/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 04:32:47 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 04:33:48 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	*create_string(char *str)
{
	t_string *string;

	string = (t_string *)malloc(sizeof(t_string));
	string->str = str;
	string->len = 0;
	string->next = NULL;
	return (string);
}

void		fill_string(t_format *format, char **s, void *arg)
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

void		create_format_struct(t_format **format)
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

int			parse_format(char *s, int *b, t_format **format)
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
		*b = 1;
	return (i);
}
