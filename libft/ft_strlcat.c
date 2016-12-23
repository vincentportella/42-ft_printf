/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:58:10 by vportell          #+#    #+#             */
/*   Updated: 2016/11/03 13:42:15 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int dst_size;
	int src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	i = -1;
	if (dst_size > (int)size)
		return (size + src_size);
	while (src[++i] && i < (int)size - dst_size - 1)
		dst[i + dst_size] = src[i];
	dst[i + dst_size] = '\0';
	return (src_size + dst_size);
}
