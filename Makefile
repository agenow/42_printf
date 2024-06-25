# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agenow <agenow@stdent.42berlin.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 13:00:59 by agenow            #+#    #+#              #
#    Updated: 2024/05/12 13:43:24 by agenow           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(addprefix src/, $(addsuffix .c, ft_printf ft_printstr ft_printhexs ft_printnums))
OBJS		= $(SRCS:%.c=%.o)
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I $(INC_DIR)
NAME		= libftprintf.a
ARNAME		= ar rcs $(NAME)
RANNAME		= ranlib $(NAME)
INC_DIR		= ./inc/

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)
	$(RANNAME)

%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
