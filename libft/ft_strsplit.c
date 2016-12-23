/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:16:29 by vportell          #+#    #+#             */
/*   Updated: 2016/11/05 12:22:41 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**populate_array(char **d, const char *s, char c)
{
	int i;
	int j;
	int k;
	int n;

	i = -1;
	n = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			j = 0;
			while (s[--i] != c && i > -1)
				j++;
			i += (j + 1);
			d[n] = (char *)malloc(sizeof(char) * (j + 2));
			k = i - j;
			d[n][++j] = '\0';
			while (j--)
				d[n][j] = s[j + k];
			n++;
		}
	}
	d[n] = 0;
	return (d);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	char	**d;

	i = -1;
	j = 0;
	n = 0;
	if (!s)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		if (s[i] == c)
			n++;
	}
	if (!(d = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	if (n == i)
		d[0] = 0;
	return (populate_array(d, s, c));
}
