# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/02 11:10:32 by frcugy            #+#    #+#              #
#    Updated: 2014/12/02 11:17:29 by frcugy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = func1.c main.c func2.c
SRC += get_next_line/get_next_line.c

OBJ = $(patsubst %.c, %.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -L libft -lft -L/usr/X11/lib -lmlx -lXext -lX11 -o $(NAME)
proper: $(NAME) clean

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

%.o: %.c
	gcc -c $(CFLAGS) $< -o $@
	make -C libft/
