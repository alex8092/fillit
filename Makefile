#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/21 18:35:45 by mdelauna          #+#    #+#              #
#    Updated: 2015/11/27 14:14:26 by mdelauna         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCS = main.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3

LIB = libft/

LIB_A = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	gcc -o $(NAME) $(OBJS) $(LIB_A)

$(LIB):
	make -C $(LIB)

%.o: %.c
	gcc -o $@ -c $^ $(FLAGS)

clean:
	$(MAKE) -C $(LIB) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIB) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: $(LIB) clean fclean re all
