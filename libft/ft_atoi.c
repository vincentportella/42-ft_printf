/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:36:08 by vportell          #+#    #+#             */
/*   Updated: 2016/11/05 13:16:05 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_overflow(unsigned long long nbr, int new_digit, int sign)
{
	if (nbr >= 1000000000000000000)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	if (nbr >= 922337203685477580 && sign == 1 && new_digit > 7)
		return (-1);
	if (nbr >= 922337203685477580 && sign == -1 && new_digit > 8)
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int							sign;
	int							overflow;
	unsigned	long	long	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		overflow = ft_overflow(num, *str - '0', sign);
		if (overflow != 1)
			return (overflow);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
