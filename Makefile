# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 17:00:43 by iugolin           #+#    #+#              #
#    Updated: 2022/04/19 16:42:20 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES_PATH = ./includes/

INCLUDES = $(INCLUDES_PATH)fractol.h

RM = @rm -rf

SRCS_DIR = ./sources/

OBJS_DIR = ./objects/

SRCS_FILES = 	color.c			\
				draw_utils.c	\
				fractol_utils.c	\
				fractol.c		\
				image_utils.c	\
				mandelbrot.c	\
				print_utils.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

# $(OBJS_DIR):
# 	@mkdir -p $(OBJS_DIR)

all : lib temp mlx $(NAME)

lib :
	make -C ./libft

temp :
	@mkdir -p ./objects/

mlx :
	make -C mlx

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(OBJS_FILES): $(OBJS_DIR)/%.o: %.c $(INCLUDES) $(LIBFT)
# 	@mkdir -p $(@D)
# 	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES) $(LIBFT) $(MLX) Makefile
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -Imlx -c $< -o $@

.PHONY : all clean fclean re

clean :
	$(RM) $(OBJS_DIR)
	make clean -C libft
	@echo "fract-ol clean done"

fclean :
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
	make fclean -C libft
	@echo "fract-ol fclean done"

re : fclean all
