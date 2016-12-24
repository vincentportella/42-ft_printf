/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:20:38 by vportell          #+#    #+#             */
/*   Updated: 2016/12/23 20:12:52 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wchar_len(wchar_t const n)
{
	if (n <= 0x7F)
		return (1);
	else if (n <= 0x7FF)
		return (2);
	else if (n <= 0xFFFF)
		return (3);
	else if (n <= 0x10FFFF)
		return (4);
	return (0);
}

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

char	*gen_wstr(wchar_t const *n, int *len)
{
	char *str;
	char *temp;
	char *next;

	*len = 0;
	str = 0;
	if (n == NULL)
		return (ft_strdup("(null)"));
	while (*n)
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
		(*len)++;
	}
	if (!str)
		str = ft_strdup("");
	return (str);
}

char	*gen_nwstr(wchar_t const *n, int d)
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
		if ((int)ft_strlen(str) > d)
			return (s = s ? s : ft_strdup(""));
		s ? ft_strdel(&s) : 0;
		s = ft_strdup(str);
		n++;
	}
	if (!str)
		str = ft_strdup("");
	return (str);
}

char	*ft_ltoa_base(long value, int base, char *a)
{
	int				i;
	unsigned long	t;
	unsigned long	u;
	char			*s;

	i = 1;
	t = value;
	u = value;
	while (u /= base)
		i++;
	s = (char *)malloc(sizeof(char) + (i + 1));
	s[i] = '\0';
	(t == 0 && i--) ? s[0] = '0' : 0;
	while (t && (s[--i] = a[t % base]))
		t /= base;
	return (s);
}

char	*utoa(long value)
{
	int		i;
	long	t;
	char	*a;
	char	*s;

	i = 1;
	if (value < -9223372036854775807)
		return (ft_strdup("9223372036854775808"));
	t = value;
	if (value < 0)
		t = -t;
	a = "0123456789";
	while (value /= 10)
		i++;
	s = (char *)malloc(sizeof(char) + (i + 1));
	s[i] = '\0';
	(t == 0 && i--) ? s[0] = '0' : 0;
	while (t && (s[--i] = a[t % 10]))
		t /= 10;
	return (s);
}
