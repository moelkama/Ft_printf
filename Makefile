# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moelkama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 16:43:18 by moelkama          #+#    #+#              #
#    Updated: 2024/10/18 13:11:25 by moelkama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = ft_printf.o ft_putnbr_base.o ft_putchar.o ft_putstr.o

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	cc $(CFLAGS) main.c $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
