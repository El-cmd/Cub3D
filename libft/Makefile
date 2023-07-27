# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alilin <alilin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 16:49:44 by alilin            #+#    #+#              #
#    Updated: 2023/07/27 17:35:11 by alilin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	clang
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

SRCS	:=	ft_bzero.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isprint.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_isdigit.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_isascii.c \
			ft_strlen.c \
			ft_tablen.c \
			ft_setopt.c \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_memmove.c \
			ft_strnstr.c \
			ft_toupper.c \
			ft_strlcat.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_substr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strjoin.c \
			ft_strmapi.c \
			ft_split.c \
			ft_strtrim.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strsrchend.c \

DIR_OBJ	= obj
OBJS	= $(addprefix $(DIR_OBJ)/, $(SRCS:.c=.o))

HEADER	= -I libft/libft.h

all:	$(NAME)

$(DIR_OBJ)/%.o: ./%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

$(NAME): $(OBJS)
	@ar rcs ${NAME} ${OBJS}

clean:
	@${RM} $(DIR_OBJ)

fclean:	clean
	@${RM} ${NAME}

re:	fclean all
