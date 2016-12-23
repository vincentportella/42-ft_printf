/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 09:55:24 by vportell          #+#    #+#             */
/*   Updated: 2016/11/05 15:05:53 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(little);
	if (l == 0)
		return ((char *)big);
	while (ft_strlen(big) > 0)
	{
		if (big[0] == little[i])
			i++;
		else
		{
			big -= i;
			i = 0;
		}
		if (i == l)
			return ((char *)big - i + 1);
		big++;
	}
	return (NULL);
}
