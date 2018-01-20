# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncella <ncella@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:43:15 by ncella            #+#    #+#              #
#    Updated: 2017/12/12 15:21:35 by ncella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_NAME = main.c ft_key.c mouse.c color.c ft_init.c core.c ft_info.c fractal.c
SRC = $(addprefix srcs/, $(SRC_NAME))
OBJ = $(patsubst srcs/%.c, obj/%.o, $(SRC))
CFLAGS = -Ofast -flto -march=native -Wall -Wextra -Werror -I libft/ -I minilibx_macos/
LIBS = -framework OpenGL -framework AppKit libft/libft.a minilibx_macos/libmlx.a 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean && make -C libft/
	@gcc $(CFLAGS) -o $(NAME) $(LIBS) $(OBJ)
	@echo "\033[32mFdF compiled [ ✔ ]"

obj/%.o: srcs/%.c
	@mkdir -p obj
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf obj/
	@make -C libft/ fclean
	@echo "\033[32mFdF cleaned [ ✔ ]"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mFdF fcleaned [ ✔ ]"

re: fclean all

.PHONY: all clean fclean re
