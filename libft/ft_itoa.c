/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:12:11 by vportell          #+#    #+#             */
/*   Updated: 2016/11/05 13:15:39 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		t;
	char	*s;

	if (n == -2147483648 && (s = (char *)malloc(sizeof(char) * 12)) &&
		ft_strcpy(s, "-2147483648"))
		return (s);
	i = 0;
	while (i++ > -1 && n < 0)
		n *= -1;
	t = n;
	while (t /= 10)
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	s[--i] = n % 10 + 48;
	while (n /= 10)
		s[--i] = n % 10 + 48;
	if (i > 0)
		s[0] = '-';
	return (s);
}
