/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:57:11 by vportell          #+#    #+#             */
/*   Updated: 2016/11/03 23:33:14 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *previous;

	if (*alst)
	{
		list = *alst;
		previous = list;
		list = list->next;
		del(previous->content, previous->content_size);
		free(previous);
		*alst = list;
	}
}
