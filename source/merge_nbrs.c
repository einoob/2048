/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 18:33:17 by elindber          #+#    #+#             */
/*   Updated: 2020/04/26 18:34:12 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/twotoeleven.h"

int			merge_down(t_info *info, int y, int x)
{
	move_empty(info, 2, y, x);
	while (x < 4)
	{
		while (y > 0)
		{
			if (info->grid[y][x] == info->grid[y - 1][x])
			{
				if (info->grid[y][x] != 0)
					info->moves++;
				info->grid[y][x] += info->grid[y - 1][x];
				info->score += info->grid[y][x] / 2;
				info->grid[y - 1][x] = 0;
			}
			y--;
		}
		y = 3;
		x++;
	}
	x = 0;
	move_empty(info, 2, y, x);
	return (info->moves != 0);
}

int			merge_up(t_info *info, int y, int x)
{
	move_empty(info, 2, y, x);
	while (x < 4)
	{
		while (y < 3)
		{
			if (info->grid[y][x] == info->grid[y + 1][x])
			{
				if (info->grid[y][x] != 0)
					info->moves++;
				info->grid[y][x] += info->grid[y + 1][x];
				info->score += info->grid[y][x] / 2;
				info->grid[y + 1][x] = 0;
			}
			y++;
		}
		y = 0;
		x++;
	}
	x = 0;
	move_empty(info, 2, y, x);
	return (info->moves != 0);
}

int			merge_right(t_info *info, int y, int x)
{
	move_empty(info, 1, y, x);
	while (y < 4)
	{
		while (x > 0)
		{
			if (info->grid[y][x] == info->grid[y][x - 1])
			{
				if (info->grid[y][x] != 0)
					info->moves++;
				info->grid[y][x] += info->grid[y][x - 1];
				info->score += info->grid[y][x] / 2;
				info->grid[y][x - 1] = 0;
			}
			x--;
		}
		x = 3;
		y++;
	}
	y = 0;
	move_empty(info, 1, y, x);
	return (info->moves != 0);	
}

int			merge_left(t_info *info, int y, int x)
{
	move_empty(info, 1, y, x);
	while (y < 4)
	{
		while (x < 3)
		{
			if (info->grid[y][x] == info->grid[y][x + 1])
			{
				if (info->grid[y][x] != 0)
					info->moves++;
				info->grid[y][x] += info->grid[y][x + 1];
				info->score += info->grid[y][x] / 2;
				info->grid[y][x + 1] = 0;
			}
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	move_empty(info, 1, y, x);
	return (info->moves != 0);
}

int			merge_grid(t_info *info, char button)
{
	info->moves = 0;
	if (button == 'a')
		return (merge_left(info, 0, 0));
	else if (button == 'w')
		return (merge_up(info, 0, 0));
	else if (button == 's')
		return (merge_down(info, 3, 0));
	else if (button == 'd')
		return (merge_right(info, 0, 3));
	else
		return (0);
}