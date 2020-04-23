/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:22:14 by elindber          #+#    #+#             */
/*   Updated: 2019/11/05 15:02:23 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	k;

	k = n;
	if (n < 0)
	{
		ft_putchar('-');
		k = k * -1;
	}
	if (k / 10 > 0)
	{
		ft_putnbr(k / 10);
	}
	ft_putchar('0' + k % 10);
}
