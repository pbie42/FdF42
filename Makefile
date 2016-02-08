# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 11:55:43 by pbie              #+#    #+#              #
#    Updated: 2016/02/08 17:07:02 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = fdf.a

INC_DIR = includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

SOURCES = ft_putstr.c\

SRC = $(addprefix sources/,$(SOURCES))

OBJ = $(SRC:.c=.o)

all : $(NAME) $(LIB)

$(NAME) : $(LIB)
	@$(CC) -o $(NAME) main.c $(LIB) $(CFLAGS)
	@echo "$(NAME) created"

$(LIB) : $(OBJ)
	@ar -r $(LIB) $(OBJ)
	@ranlib $(LIB)
	@echo "$(NAME) indexed"

clean :
	@rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean : clean
	@rm -rf $(NAME) $(LIB)
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
