# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 17:31:10 by elindber          #+#    #+#              #
#    Updated: 2020/04/26 19:46:38 by elindber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 2048-game

SRC = source/*.c

LIBFT = libftprintf/libftprintf.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@ make -C libftprintf/ fclean && make -C libftprintf/
	@ gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)
	@ echo "Your goal is to create a 2048 -block."

clean:
	@ make -C libftprintf/ clean
	@ echo "Object files cleaned."
	
fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C libftprintf/ fclean
	@ echo "Executable removed."

re: fclean all
