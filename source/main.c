/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 17:44:37 by elindber          #+#    #+#             */
/*   Updated: 2020/04/23 21:46:03 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/twotoeleven.h"

int		main(void) {

	t_info	*info;
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (-1);
	while (y < 4)
	{
		while (x < 4)
		{
			info->grid[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	create_board(info);
}