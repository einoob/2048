/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 14:13:34 by elindber          #+#    #+#             */
/*   Updated: 2020/04/24 17:03:27 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/twotoeleven.h"

void		move_empty(t_info *info, int dir, int y, int x)
{
	int		incre_x;
	int		incre_y;

	incre_x = x == 0 ? 1 : -1;
	incre_y = y == 0 ? 1 : -1;
	if (dir == 1)
	{
		while (y < 4)
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
	}
	else
	{
		while (x < 4)
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
}

int			merge_down(t_info *info, int y, int x)
{
/*	while (x < 4)
	{
		while (y > 0)
		{
			if (info->grid[y][x] == 0 && info->grid[y - 1][x] != 0)
			{
				info->grid[y][x] = info->grid[y - 1][x];
				info->grid[y - 1][x] = 0;
				y = 4;
				action++;
			}
			y--;
		}
		y = 3;
		x++;
	} */
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
/*	while (x < 4)
	{
		while (y < 3)
		{
			if (info->grid[y][x] == 0 && info->grid[y + 1][x] != 0)
			{
				info->grid[y][x] = info->grid[y + 1][x];
				info->grid[y + 1][x] = 0;
				y = -1;
				action++;
			}
			y++;
		}
		y = 0;
		x++;
	}*/
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
/*	while (y < 4)
	{
		while (x > 0)
		{
			if (info->grid[y][x] == 0 && info->grid[y][x - 1] != 0)
			{
				info->grid[y][x] = info->grid[y][x - 1];
				info->grid[y][x - 1] = 0;
				x = 4;
				action++;
			}
			x--;
		}
		x = 3;
		y++;
	}*/
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
/*	while (y < 4)
	{
		while (x < 3)
		{
			if (info->grid[y][x] == 0 && info->grid[y][x + 1] != 0)
			{
				info->grid[y][x] = info->grid[y][x + 1];
				info->grid[y][x + 1] = 0;
				x = -1;
				action++;
			}
			x++;
		}
		x = 0;
		y++;
	}*/
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
	place_nbr(info, merge, 0, 0);
	grid_to_string(info);
	print_board(info, 0);
}
