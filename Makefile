# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alilin <alilin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 17:47:30 by alilin            #+#    #+#              #
#    Updated: 2023/07/25 17:58:31 by alilin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D
RM      = rm      -rf
CC      = clang
FLAGS   = -Wall -Wextra -Werror 
DIR_INC = -I ./includes/

SRCS 	:= 	cub3D.c \
			parse.c \

DIR_SRCS 	= ./srcs

DIR_OBJ 	= obj

PATH_LIBFT = ./libft
DIR_INC += -I $(PATH_LIBFT)

OBJS        := $(addprefix ${DIR_OBJ}/, ${SRCS:.c=.o})

all: $(NAME)

$(DIR_OBJ)/%.o:	$(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(DIR_INC) -o $@ -c $<

$(NAME): $(OBJS)
	make -C $(PATH_LIBFT)
	@$(CC) $(FLAGS) $(DIR_INC) $(OBJS) -o $(NAME) -L $(PATH_LIBFT) -lft -lm

clean:
	make -C $(PATH_LIBFT) clean
	@$(RM) $(DIR_OBJ)

fclean:		clean
	make -C $(PATH_LIBFT) fclean
	@$(RM) $(NAME)

re:	fclean all