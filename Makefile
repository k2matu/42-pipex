# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 14:30:56 by kmatjuhi          #+#    #+#              #
#    Updated: 2024/03/07 15:24:31 by kmatjuhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	libft/libft.a

NAME	=	pipex

SRCS	=	pipex.c parsing_args.c parsing_path.c error_msg.c fopen.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	-rm -f
CGLAGS	=	-Wall -Werror -Wextra -g

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
