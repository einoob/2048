# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 17:31:10 by elindber          #+#    #+#              #
#    Updated: 2020/04/23 17:40:17 by elindber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 2048

SRC = source/*.c

LIBFT = libftprintf/libftprintf.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@ make -C libftprintf/ fclean && make -C libftprintf/
	@ gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)
	@ echo "Your goal is to create a 2048 -block"

clean:
	@ make -C libftprintf/ clean
	@ echo "Object files cleaned."
	
fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C libftprintf/ fclean
	@ echo "Game removed"

re: fclean all