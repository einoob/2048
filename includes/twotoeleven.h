/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twotoeleven.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 17:40:38 by elindber          #+#    #+#             */
/*   Updated: 2020/04/23 21:45:15 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWOTOELEVEN_H
# define TWOTOELEVEN_H

# include <math.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/libft/libft.h"

typedef struct	s_info
{	
	int			grid[4][4];
	int			newnbr;
	char		**board;
	int			score;
	int			loc_x;
	int			loc_y;
}				t_info;

int				create_board(t_info *info);

#endif