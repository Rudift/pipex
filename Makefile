# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 15:00:24 by vdeliere          #+#    #+#              #
#    Updated: 2024/12/30 16:18:44 by vdeliere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
SRC_DIR = srcs/
#SANITIZE = -fsanitize=address -g3

SRC= ${SRC_DIR}main.c ${SRC_DIR}process.c ${SRC_DIR}files.c ${SRC_DIR}pipex.c

#BONUS = 
#BONUS_OBJS = ${BONUS:.c=.o}

OBJ = ${SRC:.c=.o}

all: subsystems ${NAME}
.c.o:
	${CC} -c $< -o ${<:.c=.o}

subsystems :
	@make -C $(LIBFT_DIR) all

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} ${LIBFT_LIB} -o ${NAME}

all:${NAME}

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f ${OBJ}
	
fclean : clean
	rm -f ${NAME}
	@make -C $(LIBFT_DIR) fclean

re : clean all

.PHONY: all clean fclean re bonus