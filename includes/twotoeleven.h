/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twotoeleven.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 17:40:38 by elindber          #+#    #+#             */
/*   Updated: 2020/04/30 13:56:19 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWOTOELEVEN_H
# define TWOTOELEVEN_H

# include <math.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/libft/libft.h"

typedef struct	s_info
{	
	int			grid[4][4];
	int			newnbr;
	char		**board;
	int			score;
	int			full;
	int			moves;
}				t_info;

int				create_board(t_info *info);
int				new_number_value(void);
int				grid_to_string(t_info *info);
int				merge_grid(t_info *info, char button);
void			place_nbr(t_info *info, int nbr, int y, int x);
void			move_empty(t_info *info, int dir, int y, int x);
void			play_game(t_info *info);
void			print_board(t_info *info, int y);


#endif