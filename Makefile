# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pragolan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/27 17:11:12 by pragolan          #+#    #+#              #
#    Updated: 2018/09/26 14:34:11 by pragolan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIB = ./libft/libft.a

NAME = lem-in

FLAGS =  -Wall -Wextra -Werror -I.

SRCC = lemin.c ft_assign.c ft_check_valid.c ft_find_path1.c ft_find_room.c\
	   ft_free.c ft_get_rooms.c ft_return_i.c ft_return_ie.c ft_rooms.c\
	   ft_store_link.c ft_strlength.c

all: $(NAME)

$(NAME):
	make -C ./libft
	$(CC) $(FLAGS) -o $(NAME) $(SRCC) $(LIB)

clean:
	rm -fr $(SRCO)
	make clean -C ./libft

fclean: clean
	rm -fr $(NAME)
	make fclean -C ./libft

re: fclean all
