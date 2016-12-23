/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:08:14 by vportell          #+#    #+#             */
/*   Updated: 2016/11/02 14:09:46 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	int		j;
	char	*d;
	char	*s;

	i = n;
	j = -1;
	d = (char *)dst;
	s = (char *)src;
	while (i--)
		s[i] == c ? j = i : 0;
	i = -1;
	if (j > -1)
	{
		while (++i <= (size_t)j)
			d[i] = s[i];
		return (d += ++j);
	}
	else
	{
		while (++i < n)
			d[i] = s[i];
		return (NULL);
	}
}
