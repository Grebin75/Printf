# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 13:16:55 by hcoutinh          #+#    #+#              #
#    Updated: 2022/08/12 18:24:01 by hcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror -fsanitize=address
RM		= /bin/rm -f

NAME	= libftprintf.a

SRCS	= printf.c utils.c

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		@ar -rcs $(NAME) $(OBJS)
		gcc $(CFLAGS) $(OBJS)

clean:
		@$(RM) $(OBJS)
fclean: clean
		@$(RM) $(NAME)
re:		fclean all

.PHONY:	all clean fclean re