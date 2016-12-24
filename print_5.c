/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 04:31:12 by vportell          #+#    #+#             */
/*   Updated: 2016/12/24 04:31:31 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_err(char *s, t_string **str, t_format **format)
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
	append_str(t, str, *format);
	ft_strdel(&p);
	ft_strdel(&n);
	ft_strdel(&t);
	free((*format)->flag);
	free(*format);
}

void	print_pct(t_string **str, t_format **format)
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
	append_str(s, str, *format);
	free((*format)->flag);
	free(*format);
	ft_strdel(&s);
}
