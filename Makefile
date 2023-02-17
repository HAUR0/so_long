# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rloos <rloos@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 16:23:43 by rloos             #+#    #+#              #
#    Updated: 2023/02/17 15:10:24 by rloos            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c \




OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

#/////////////////////////////////////////////

.PHONY: all clean fclean re

all:	${NAME}

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	@echo "👺 DONE"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

#cleaning-stuff////////////////////////////////

clean: 
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all
	@echo "DELETED AND RECOMPILED"
	
#/////////////////////////////////////////////
	

