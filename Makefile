# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 19:54:58 by evila-ro          #+#    #+#              #
#    Updated: 2020/12/12 20:55:57 by evila-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
HEADER		=	-I libft/ -I mlx -I.
SRCS		=	src/gocube.c		\
				src/maper.c			\
				src/process.c		\
				src/incube.c		\
				src/screenshot.c	\
				src/exceed.c		\
				src/postmap.c		\
				src/sprites.c		\
				src/main.c			\
				src/precube.c
LIB_DIR		=	libft
LIB_SRC		=	$(shell find libft | fgrep ".c")
SOBJ		=	$(SRCS:.c=.o)
LIBS		=	libft/libft.a
CC			=	@gcc
FLAGS		=	-lmlx -framework OpenGL -framework AppKit
CFLAGS		=	-Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME):	$(SOBJ)
		@$(MAKE) -C libft/
	$(CC) $(SOBJ) $(LIBS) -o $(NAME) $(CFLAGS) $(FLAGS)

bonus:
		@$(MAKE) -C libft/
		-$(CC) $(SOBJ) $(LIBS) -o $(NAME) $(CFLAGS) $(FLAGS)

clean:
		@$(MAKE) fclean -C libft/
		@rm -f $(SOBJ)

fclean: clean
		@$(MAKE) fclean -C libft/
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
