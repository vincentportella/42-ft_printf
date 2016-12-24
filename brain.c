/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:20:38 by vportell          #+#    #+#             */
/*   Updated: 2016/12/23 22:54:13 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
