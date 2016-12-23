/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:27:10 by vportell          #+#    #+#             */
/*   Updated: 2016/11/04 15:30:10 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*m;

	i = -1;
	if (!s)
		return (NULL);
	m = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!m)
		return (NULL);
	while (s[++i])
		m[i] = f(s[i]);
	m[i] = '\0';
	return (m);
}
