/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 14:13:34 by elindber          #+#    #+#             */
/*   Updated: 2020/04/26 19:49:48 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/twotoeleven.h"

void		move_empty(t_info *info, int dir, int y, int x)
{
	int		incre_x;
	int		incre_y;

	incre_x = x == 0 ? 1 : -1;
	incre_y = y == 0 ? 1 : -1;
	while (dir == 1 && y < 4)
	{
		while (x + incre_x >= 0 && x + incre_x <= 3)
		{
			if (info->grid[y][x] == 0 && info->grid[y][x + incre_x] != 0)
			{
				info->grid[y][x] = info->grid[y][x + incre_x];
				info->grid[y][x + incre_x] = 0;
				x = incre_x == 1 ? -1 : 4;
				info->moves++;
			}
			x += incre_x;
		}
		x = incre_x == 1 ? 0 : 3;
		y++;
	}
	while (dir != 1 && x < 4)
	{
		while (y + incre_y >= 0 && y + incre_y <= 3)
		{
			if (info->grid[y][x] == 0 && info->grid[y + incre_y][x] != 0)
			{
				info->grid[y][x] = info->grid[y + incre_y][x];
				info->grid[y + incre_y][x] = 0;
				y = incre_y == 1 ? -1 : 4;
				info->moves++;
			}
			y += incre_y;
		}
		y = incre_y == 1 ? 0 : 3;
		x++;
	}
}

void		play_game(t_info *info)
{
	char	key;
	int		merge;

	merge = 0;
	while (merge == 0)
	{
		key = getchar();
		merge = merge_grid(info, key);
	}
	merge = new_number_value();
	place_nbr(info, merge, -1, -1);
	grid_to_string(info);
	print_board(info, 0);
}
