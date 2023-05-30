# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 06:16:05 by msaidi            #+#    #+#              #
#    Updated: 2023/05/20 00:51:24 by msaidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fract-ol

CC = cc

CFLAGS = -Ofast -lmlx -framework OpenGL -framework AppKit

CFLAGSO = -Wall -Wextra -Werror -Imlx

RM = rm -rf

HEADER = fractol.h

FILES = fractol.c utils.c utils2.c utils3.c fractals.c

OBJECTS = $(FILES:.c=.o)

%.o : %.c $(HEADER)
		$(CC) $(CFLAGSO) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

clean : 
		$(RM) $(OBJECTS)
fclean : clean
		$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re