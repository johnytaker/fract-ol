# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 17:00:43 by iugolin           #+#    #+#              #
#    Updated: 2022/05/20 02:48:57 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

CC = cc

CFLAGS = -O3 -Ofast -Wall -Wextra -Werror

INCLUDES_PATH = ./includes/

INCLUDES = $(INCLUDES_PATH)fractol.h

RM = @rm -rf

SRCS_DIR = ./sources/

OBJS_DIR = ./objects/

SRCS_FILES = 	burning_ship.c	\
				color.c			\
				draw_utils.c	\
				events.c		\
				fractol_utils.c	\
				fractol.c		\
				zoom.c			\
				image_utils.c	\
				mandelbrot.c	\
				move_keyboard.c	\
				julia.c			\
				print_utils.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

all : mlx lib temp $(NAME)

lib :
	make -C ./libft

mlx :
	make -C ./mlx

temp :
	@mkdir -p ./objects/

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES) $(LIBFT) $(MLX) Makefile
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -Imlx -c $< -o $@

.PHONY : all lib mlx temp clean fclean re

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
