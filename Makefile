# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 11:55:43 by pbie              #+#    #+#              #
#    Updated: 2016/02/10 17:43:22 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Werror -Wextra -Iincludes

SRC = main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C libft
	@make -C minilibx_macros
	gcc $(CFLAGS) -o $(NAME) $(SRC) -lmlx -framework OpenGl -framework Appkit
	echo "$(NAME) created"

clean :
	rm -rf $(OBJ)
	echo "OBJ deleted"

fclean : clean
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
