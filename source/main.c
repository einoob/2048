/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 17:44:37 by elindber          #+#    #+#             */
/*   Updated: 2020/04/30 14:29:04 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/twotoeleven.h"

int		grid_lock(t_info *info, int y, int x)
{
	while (y < 4)
	{
		while (x < 4)
		{
			if (info->grid[y][x] == 0)
				return (0);
			if (x < 3 && info->grid[y][x] == info->grid[y][x + 1])
				return (0);
			if (y < 3 && info->grid[y][x] == info->grid[y + 1][x])
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	initialize_info(t_info *info, int y, int x)
{
	info->newnbr = 0;
	info->score = 0;
	info->full = 0;
	info->moves = 0;
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
}

void	print_board(t_info *info, int y)
{
	ft_printf("\nScore: %d\n", info->score);
	ft_putendl("---------------------");
	while (y < 4)
	{
		ft_putchar('|');
		ft_putstr(info->board[y]);
		ft_putendl("---------------------");
		y++;
	}
	if (grid_lock(info, 0, 0))
	{
		ft_putendl("======GAME OVER======");
		ft_printf("Your score:\t%d\n", info->score);
		info->full = 1;
		return ;
	}
	ft_putendl("Use w-a-s-d + enter to merge numbers.");
	while (y > -1)
	{
		ft_strdel(&(info->board[y]));
		y--;
	}
	free(info->board);
}

int		main(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (-1);
	initialize_info(info, 0, 0);
	create_board(info);
	while (!info->full)
		play_game(info);
	return (0);
}
