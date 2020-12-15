# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 21:57:47 by evila-ro          #+#    #+#              #
#    Updated: 2020/12/10 18:25:08 by evila-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a


SRC	=	ft_strchr.c			ft_strrchr.c		ft_strlen.c				\
		ft_strncmp.c		ft_strlcat.c		ft_strlcpy.c			\
		ft_isalpha.c		ft_isdigit.c		ft_isascii.c			\
		ft_isalnum.c		ft_isprint.c		ft_toupper.c			\
		ft_tolower.c		ft_memset.c			ft_bzero.c				\
		ft_memcpy.c			ft_memccpy.c		ft_memmove.c			\
		ft_memchr.c			ft_memcmp.c			ft_strnstr.c			\
		ft_atoi.c			ft_calloc.c			ft_strdup.c				\
		ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c			\
		ft_putnbr_fd.c		ft_substr.c			ft_strjoin.c			\
		ft_strtrim.c		ft_split.c			ft_itoa.c				\
		ft_strmapi.c		get_next_line.c		get_next_line_utils.c	\
		ft_printf.c			ft_printf_utils.c	ft_string.c				\
		ft_stringb.c		ft_intera.c			ft_interb.c				\
		ft_unsign.c			ft_hex.c			ft_hexx.c				\
		ft_pointer.c		ft_per.c			ft_char.c				\
		ft_itoas.c			ft_lens.c

BONUS =	ft_lstsize_bonus.c			ft_lstadd_front_bonus.c			\
		ft_lstadd_front_bonus.c		ft_lstlast_bonus.c				\
		ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c			\
		ft_lstclear_bonus.c			ft_lstiter_bonus.c				\
		ft_lstnew_bonus.c			ft_lstmap_bonus.c

CFLAGS	= -Wall -Werror -Wextra -I

OBJ	= $(SRC:.c=.o)

OBJO = $(BONUS:.c=.o)

all: $(NAME)
$(NAME): $(SRC) libft.h
	@gcc $(CFLAGS)./ -c $(SRC)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -c $< -o $@

bonus:
	@gcc $(CFLAGS)./ -c $(SRC) $(BONUS)
	@ar -rc $(NAME) $(OBJ) $(OBJO)
	@ranlib $(NAME)

clean:
	@rm -f *.o
	@rm -f *.out

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all bonus clean fclean re
