# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpatel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 19:34:42 by bpatel            #+#    #+#              #
#    Updated: 2016/12/15 21:09:30 by bpatel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	ft_fillit.c ft_strctrim.c ft_tet_split.c ft_tit_count.c ft_istwonew.c \
			ft_valid_tets.c ft_tet_coor.c ft_solver.c ft_printsolution.c \

OBJ		=	$(SRC:.c=.o)

HDR		=	-I.
LIB 	=	-L. -lft

.Phony = all clean fclean re

all: $(NAME)

$(NAME): #$(OBJ)
	$(CC) $(CFLAGS) $(HDR) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) $(HDR) $(LIB) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
