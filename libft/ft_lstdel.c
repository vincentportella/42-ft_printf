/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:58:22 by vportell          #+#    #+#             */
/*   Updated: 2016/11/03 23:24:44 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *previous;

	if (*alst)
	{
		list = *alst;
		while (list)
		{
			previous = list;
			list = list->next;
			del(previous->content, previous->content_size);
			free(previous);
		}
	}
	*alst = NULL;
}
