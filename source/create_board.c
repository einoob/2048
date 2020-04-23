/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 17:51:23 by elindber          #+#    #+#             */
/*   Updated: 2020/04/23 22:21:36 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/twotoeleven.h"

void	int_arr_to_char(t_info *info, int y, int slot)
{
	int x;
	int	nbr;
	int count;

	count = 4;
	if (slot < 10)
		x = slot == 4 ? 0 : 1;
	else
		x = slot == 14 ? 2 : 3;
	nbr = info->grid[y][x];
//	ft_printf("grid nbr in [%d %d] = %d\n", y, x, info->grid[y][x]);
	info->board[y][20] = '\n';
	info->board[y][slot] = '|';
	slot--;
	while (count > 0) 
	{	
		info->board[y][slot] = nbr == 0 ? ' ' : nbr % 10 + '0';
		nbr /= 10;
		slot--;
		count--;
	}

}

int		grid_to_string(t_info *info)
{
	int y;

	y = 0;
	if (!(info->board = (char**)malloc(sizeof(char*) * 8)))
		return (0);
	while (y < 4) 
	{
		info->board[y] = ft_strnew(22);
		y++;
	}
	info->board[y] = NULL;
	y = 0;
	while (y < 4) 
	{
		int_arr_to_char(info, y, 4);
		int_arr_to_char(info, y, 9);
		int_arr_to_char(info, y, 14);
		int_arr_to_char(info, y, 19);
		y++;
	}
	return (1);
}

int		new_number_value(void)
{
	int		nbr;

	nbr = arc4random_uniform(5);
	nbr = nbr == 4 ? 4 : 2;
	return (nbr);
}

int		place_nbr(t_info *info, int nbr, int x, int y)
{
	int		count;

	count = 0;
	info->loc_x = arc4random_uniform(4);
	info->loc_y = arc4random_uniform(4);
	x = info->loc_x;
	y = info->loc_y;
	while (count < 16)
	{
		while (info->grid[y][x] != 0 && x < 4)
		{
			x++;
			count++;	
		}
		if (info->grid[y][x] == 0)
			break ;
		y = y == 3 ? 0 : y + 1;
		x = 0;
	}
	if (count != 16)
		info->grid[y][x] = nbr;
	return (count != 16);
}

int		create_board(t_info *info)
{
	int		nb1;
	int		nb2;

	nb1 = new_number_value();
	nb2 = 2;
	place_nbr(info, nb1, 0, 0);
	place_nbr(info, nb2, 0, 0);
	grid_to_string(info);
	int i = 0;
	ft_putstr("GRID\n");
	ft_putstr("---------------------\n");
	while (i < 4)
	{
		ft_putchar('|');
		ft_putstr(info->board[i]);
		ft_putstr("---------------------\n");
		i++;
	}
	ft_printf("GRID\n");
	return (1);
}