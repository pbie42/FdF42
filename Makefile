# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 11:55:43 by pbie              #+#    #+#              #
#    Updated: 2016/02/11 15:16:39 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Werror -Wextra -Iincludes

SRC = main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C libft re
	@gcc $(CFLAGS) -o $(NAME) $(SRC) -I libft/includes/libft.h -lmlx -framework OpenGl -framework Appkit libft/libft.a
	@echo "$(NAME) created"

clean :
	rm -rf $(OBJ)
	echo "OBJ deleted"

fclean : clean
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
