/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 17:44:37 by elindber          #+#    #+#             */
/*   Updated: 2020/04/24 16:34:38 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/twotoeleven.h"

void	initialize_info(t_info *info)
{
	info->newnbr = 0;
	info->score = 0;
	info->loc_x = 0;
	info->loc_y = 0;
	info->full = 0;
	info->moves = 0;
}

void	print_board(t_info *info, int y)
{
	ft_printf("\nScore: %d\n", info->score);
	ft_putstr("---------------------\n");
	while (y < 4)
	{
		ft_putchar('|');
		ft_putstr(info->board[y]);
		ft_putstr("---------------------\n");
		y++;
	}
	ft_putendl("Use w-a-s-d + enter to merge numbers.");
	while (y > -1)
	{
		ft_strdel(&(info->board[y]));
		y--;
	}
}

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
	initialize_info(info);
	create_board(info);
	while (!info->full)
	{
		play_game(info);
	}
}