/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 17:51:23 by elindber          #+#    #+#             */
/*   Updated: 2020/04/30 14:21:12 by elindber         ###   ########.fr       */
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
	if (!(info->board = (char**)malloc(sizeof(char*) * 5)))
		return (0);
	while (y < 4)
	{
		info->board[y] = ft_strnew(21);
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

	nbr = rand() % 5;
	nbr = nbr == 4 ? 4 : 2;
	return (nbr);
}

int		zero_count(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (info->grid[y][x] == 0)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

void	place_nbr(t_info *info, int nbr, int y, int x)
{
	int		emptys;
	int		count;

	emptys = zero_count(info, 0, 0);
	count = rand() % emptys;
	while (count != -1 && y < 3)
	{
		x = -1;
		y++;
		while (count != -1 && x < 3)
		{
			x++;
			if (info->grid[y][x] == 0)
				count--;
		}
	}
	info->grid[y][x] = nbr;
}

int		create_board(t_info *info)
{
	int		nb1;

	nb1 = new_number_value();
	place_nbr(info, nb1, -1, -1);
	place_nbr(info, 2, -1, -1);
	grid_to_string(info);
	print_board(info, 0);
	return (1);
}
