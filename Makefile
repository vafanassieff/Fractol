#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 17:44:48 by vafanass          #+#    #+#              #
#*   Updated: 2016/12/21 00:43:39 by vafanass         ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

NAME = fractol
HEADER = fractol.h
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC_NAME = main.c \
		   utility.c \
		   fractal.c \
		   key_event.c \
		   display_tools.c \
		   mandelbrot_tools.c \
		   julia_tools.c \
		   burningship_tools.c \
		   mouse_event.c \
		   fractol_ui.c

SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(SRC_NAME:.c=.o)
INCLUDE = -Iinclude -I libft/includes -I /minilibx_el_capitan
LINCLUDE = -I libft/includes -L libft/ -lft -I minilibx_el_capitan \
	-g -L minilibx_el_capitan  -l mlx -framework OpenGL -framework AppKit

MAKELIB= make -C libft/ && make -s -C minilibx_el_capitan
CLEANLIB= make fclean -C libft/ && make clean -C minilibx_el_capitan

all: $(NAME)

$(NAME):
	@$(CLEANLIB)
	@$(MAKELIB)
	@$(CC) -c $(CFLAG) $(INCLUDE) $(SRC) 
	@$(CC) $(CFLAG) -o $(NAME) $(LINCLUDE) $(OBJS)

clean:
	@$(CLEANLIB)
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@$(CLEANLIB)

re: fclean all
