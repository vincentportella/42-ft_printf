/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:08:14 by vportell          #+#    #+#             */
/*   Updated: 2016/11/03 00:27:30 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int t;
	int i;

	t = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0 && (n = -n) > 0)
		ft_putchar_fd('-', fd);
	i = n % 10;
	while (n /= 10)
		t = t * 10 + n % 10;
	while (t > 1)
	{
		ft_putchar_fd(t % 10 + '0', fd);
		t /= 10;
	}
	ft_putchar_fd(i + '0', fd);
}
