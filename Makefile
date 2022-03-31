# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 15:00:23 by alefranc          #+#    #+#              #
#    Updated: 2022/03/31 23:46:09 by alefranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                                                              #
#                               DECLARATIONS                                   #
#                                                                              #
#------------------------------------------------------------------------------#

#------------------------------------#
#             COMPILATION            #
#------------------------------------#

NAME = so_long

CC = clang
FLAGS = -Wall -Wextra -Werror -g3
INC_FLAG = -Iinclude

#------------------------------------#
#                LIBFT               #
#------------------------------------#

LIBFTDIR = libft/
LIBFT_A = $(LIBFTDIR)libft.a

LIBFTINC_FLAG = -I$(LIBFTDIR)include

#------------------------------------#
#               SOURCES              #
#------------------------------------#

SRCDIR = src/
SRCFILES =	check_map.c \
			error.c \
			main.c \
			parsing.c

SRC = $(addprefix $(SRCDIR), $(SRCFILES))

#------------------------------------#
#               OBJECTS              #
#------------------------------------#

OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))

#------------------------------------#
#              INCLUDES              #
#------------------------------------#

HEADER = include/so_long.h

#------------------------------------#
#              MINILIBX              #
#------------------------------------#

GMLX = ~/minilibx/libmlx_Linux.a -lXext -lX11 -I ~/minilibx/include/
INC_MLX = -I ~/minilibx/include/

#------------------------------------------------------------------------------#
#                                                                              #
#                                   RULES                                      #
#                                                                              #
#------------------------------------------------------------------------------#

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC_FLAG) $(LIBFTINC_FLAG) $(OBJ) $(LIBFT_A) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(INC_FLAG) $(LIBFTINC_FLAG) -c $< -o $@ $(INC_MLX)

$(LIBFT_A):
	make -C $(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
