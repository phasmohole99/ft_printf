# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrital- <mrital-@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 10:53:45 by mrital-           #+#    #+#              #
#    Updated: 2022/11/08 22:40:29 by mrital-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc 
FLAGS = -Wextra -Wall -Werror

SRC = ft_printf.c \
	 ft_utils.c \
	 ft_hexaptr.c \
	
OBJS = ${SRC:.c=.o}

#for protectet any file inputing to run so this command say not compile any file or variable !{...}
.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
	
