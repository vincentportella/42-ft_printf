/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 04:31:47 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 04:32:26 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	append_assist(char *s, t_format *format, t_string **temp)
{
	while ((*temp)->next)
		*temp = (*temp)->next;
	(*temp)->next = create_string(ft_strdup(s));
	if (format->type == 13 && format->length < 3)
		(*temp)->next->len = format->min_width ? format->min_width : 1;
	else if (format->type == 14)
	{
		if (format->min_width)
			(*temp)->next->len = format->min_width + ft_strlen(s) - 1;
		else
		{
			if (ft_strlen(s) == 0)
				(*temp)->next->len = 1;
			else
				(*temp)->next->len = ft_strlen(s);
		}
	}
}

void	append_str(char *s, t_string **str, t_format *format)
{
	t_string *temp;

	temp = *str;
	if (*str)
		append_assist(s, format, &temp);
	else
	{
		*str = create_string(ft_strdup(s));
		if (format->type == 13 && format->length < 3)
			temp->len = format->min_width ? format->min_width : 1;
		else if (format->type == 14)
		{
			if (format->min_width)
				temp->len = format->min_width + ft_strlen(s) - 1;
			else
			{
				if (ft_strlen(s) == 0)
					temp->len = 1;
				else
					temp->len = ft_strlen(s);
			}
		}
	}
}

int		append_result(char *s, void *arg, t_string **str, t_format **format)
{
	char *tmp;

	if ((*format)->type > 0)
		fill_string(*format, &tmp, arg);
	else
	{
		print_err(s, str, format);
		return (1);
	}
	append_str(tmp, str, *format);
	free((*format)->flag);
	free(*format);
	free(tmp);
	return (0);
}

int		append_filler(char *s, t_string **str, int i, int c)
{
	t_string *temp;

	temp = *str;
	if (*str)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = create_string(ft_strsub(s, i - c, c));
	}
	else
		*str = create_string(ft_strsub(s, i - c, c));
	return (0);
}
