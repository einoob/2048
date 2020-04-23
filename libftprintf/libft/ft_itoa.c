/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:59:16 by elindber          #+#    #+#             */
/*   Updated: 2020/03/11 19:22:46 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	uintmax_t	count;
	long		nbr;
	char		*str;

	nbr = (long)n;
	count = ft_nbrcount((intmax_t)n);
	if (!(str = ft_strnew(count)))
		return (NULL);
	count--;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[count] = nbr % 10 + '0';
		nbr /= 10;
		count--;
	}
	return (str);
}
