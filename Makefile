# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpatel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 19:34:42 by bpatel            #+#    #+#              #
#    Updated: 2016/12/02 19:35:09 by bpatel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libfillit.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	ft_fillit.c ft_strctrim.c ft_tet_split.c ft_tit_count.c ft_istwonew.c \
			ft_valid_tets.c ft_tet_coor.c ft_issafe.c

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
