# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 17:00:43 by iugolin           #+#    #+#              #
#    Updated: 2022/03/29 20:43:59 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = ./libft/libft.a

# MLX = ./mlx/libmlx.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = fractol.h

RM = @rm -rf

SRCS_DIR = sources/

SRCS_FILES = fractol.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_FILES = $(SRCS:%.c=%.o)

# $(OBJS_DIR):
# 	@mkdir -p $(OBJS_DIR)

all : lib $(NAME)

lib :
	make -C libft

# mlx :
# 	make -C mlx

$(NAME) : $(OBJS_FILES)
	$(CC) $(CFLAGS) $(OBJS_FILES) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(OBJS_FILES): $(OBJS_DIR)/%.o: %.c $(INCLUDES) $(LIBFT)
# 	@mkdir -p $(@D)
# 	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

%.o: %.c $(HEADER) $(LIBFT) Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


clean :
	$(RM) $(OBJS_FILES)
	make clean -C libft
# make clean -C mlx
	@echo "fract-ol clean done"

fclean :
	$(RM) $(OBJS_FILES)
	$(RM) $(NAME)
	make fclean -C libft
# make clean -C mlx
	@echo "fract-ol fclean done"

re : fclean all

.PHONY : all clean fclean re