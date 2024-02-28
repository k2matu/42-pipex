# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 14:30:56 by kmatjuhi          #+#    #+#              #
#    Updated: 2024/02/28 11:53:42 by kmatjuhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	libft/libft.a

NAME	=	pipex

SRCS	=	pipex.c pipex_utils.c ft_sstrjoin.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	-rm -f
CGLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	
$(LIBFT):
	make -C ./libft
	
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	make clean -C libft
	$(RM) $(OBJS)
	
fclean:
	make fclean -C libft
	$(RM) $(NAME) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re