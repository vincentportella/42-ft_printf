/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 22:53:45 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 05:54:13 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*wchar_to_char(wchar_t const n)
{
	char *c;

	c = ft_strnew(4);
	if (n <= 0x7F)
		c[0] = n;
	else if (n <= 0x7FF)
	{
		c[0] = (n >> 6) + 0xC0;
		c[1] = (n & 0x3F) + 0x80;
	}
	else if (n <= 0xFFFF)
	{
		c[0] = (n >> 12) + 0xE0;
		c[1] = ((n >> 6) & 0x3F) + 0x80;
		c[2] = (n & 0x3F) + 0x80;
	}
	else if (n <= 0x10FFFF)
	{
		c[0] = (n >> 18) + 0xF0;
		c[1] = ((n >> 12) & 0x3F) + 0x80;
		c[2] = ((n >> 6) & 0x3F) + 0x80;
		c[3] = (n & 0x3F) + 0x80;
	}
	return (c);
}

char	*gen_wstr(wchar_t *n, int *len)
{
	char *str;
	char *temp;
	char *next;

	*len = 0;
	str = 0;
	if (n == NULL)
		return (ft_strdup("(null)"));
	while (*n && ++(*len))
	{
		next = wchar_to_char(*n);
		if (str)
		{
			temp = ft_strdup(str);
			ft_strdel(&str);
			str = ft_strjoin(temp, next);
			ft_strdel(&temp);
		}
		else
			str = ft_strdup(next);
		ft_strdel(&next);
		n++;
	}
	!str ? str = ft_strdup("") : 0;
	return (str);
}

void	gen_nwstr_assist(wchar_t **n, char **next, char **temp, char **str)
{
	*next = wchar_to_char(**n);
	if (*str)
	{
		*temp = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(*temp, *next);
		ft_strdel(temp);
	}
	else
		*str = ft_strdup(*next);
	ft_strdel(next);
}

char	*gen_nwstr(wchar_t *n, int d)
{
	char *s;
	char *str;
	char *temp;
	char *next;

	s = 0;
	str = 0;
	if (n == NULL)
		return (ft_strdup("(null)"));
	while (*n)
	{
		gen_nwstr_assist(&n, &next, &temp, &str);
		if ((int)ft_strlen(str) > d)
		{
			ft_strdel(&str);
			return (s = s ? s : ft_strdup(""));
		}
		s ? ft_strdel(&s) : 0;
		s = ft_strdup(str);
		n++;
	}
	if (!str)
		str = ft_strdup("");
	return (str);
}
