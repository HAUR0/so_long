# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rloos <rloos@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 10:57:52 by rloos             #+#    #+#              #
#    Updated: 2023/02/16 13:47:39 by rloos            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

libft_SRC =	ft_isalpha.c \
    ft_isdigit.c \
    ft_isalnum.c \
    ft_isascii.c \
    ft_isprint.c \
    ft_strlen.c \
    ft_memset.c \
    ft_bzero.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_strlcpy.c \
    ft_strlcat.c \
    ft_toupper.c \
    ft_tolower.c \
    ft_strchr.c \
    ft_strrchr.c \
    ft_strncmp.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_strnstr.c \
    ft_atoi.c \
    ft_calloc.c \
    ft_strdup.c \
    ft_substr.c \
    ft_strjoin.c \
    ft_strtrim.c \
    ft_split.c \
    ft_itoa.c \
    ft_strmapi.c \
    ft_striteri.c \
    ft_putchar_fd.c \
    ft_putstr_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
    ft_int_array_printer.c \
    ft_two_d_array_printer.c \
    

ft_printf_SRC = pr_hexa_lo.c \
		pr_hexa_up.c \
		pr_pointer.c \
		pr_putchar.c \
		pr_putnbr.c \
		pr_putstr.c \
		pr_putunsigned_nbr.c \
		ptr_write.c \
		ft_printf.c \

get_next_line_SRC = get_next_line.c \
        get_next_line_utils.c \


OBJECTS = $(libft_SRC:.c=.o) $(ft_printf_SRC:.c=.o) $(get_next_line_SRC:.c=.o)

#//////////////////////////////////////

.PHONY: all clean fclean re tet

all:	${NAME}

${NAME}:
	cc -c $(CFLAGS) $(libft_SRC) $(ft_printf_SRC) $(get_next_line_SRC)
	ar rcs $(NAME) $(OBJECTS)

clean:	
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

#///////////////////////////////////////
