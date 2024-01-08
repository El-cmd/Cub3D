# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eldoctor <eldoctor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 17:47:30 by alilin            #+#    #+#              #
#    Updated: 2023/12/23 14:49:21 by eldoctor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D
RM      = rm      -rf
CC      = clang
FLAGS   = -Wall -Wextra -Werror 
DIR_INC = -I ./includes/

SRCS 	:= 	cub3D.c \
			main_parse.c \
			key_funct.c \
			square.c \
			init_image.c \
			hakai.c \
			utils.c \
			gnl.c \
			parse.c \
			

DIR_SRCS 	= ./srcs

DIR_OBJ 	= obj

PATH_LIBFT = ./libft
PATH_MLX = ./minilibx-linux
DIR_INC += -I $(PATH_LIBFT)

OBJS        := $(addprefix ${DIR_OBJ}/, ${SRCS:.c=.o})

all: $(NAME)

$(DIR_OBJ)/%.o:	$(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -D BUFFER_SIZE=10000 $(DIR_INC) -o $@ -c $< -g

$(NAME): $(OBJS)
	make -C $(PATH_LIBFT)
	make -C $(PATH_MLX)
	@$(CC) $(FLAGS) $(DIR_INC) $(OBJS) -o $(NAME) -L $(PATH_LIBFT) -lft -lm -L $(PATH_MLX) -lXext -lmlx -lX11

clean:
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIBFT) clean
	@$(RM) $(DIR_OBJ)

fclean:		clean
	make -C $(PATH_LIBFT) fclean
	@$(RM) $(NAME)

re:	fclean all