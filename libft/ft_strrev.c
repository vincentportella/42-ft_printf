/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:54:40 by vportell          #+#    #+#             */
/*   Updated: 2016/11/05 13:10:59 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (j < i)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		j++;
		i--;
	}
	return (str);
}
