# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 13:01:41 by jemonthi          #+#    #+#              #
#    Updated: 2025/12/05 13:04:23 by jemonthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

NAME_BONUS = so_long_bonus

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SOURCES	=			sources/mandatory/so_long.c \
					sources/mandatory/play_the_map.c \
					sources/mandatory/controls.c \
					sources/mandatory/exit_game.c \
					sources/mandatory/error_functions.c \
					sources/mandatory/verify_with_copy.c \
					sources/mandatory/count_and_find.c \
					sources/mandatory/utility_function.c \
					sources/mandatory/get_next_line.c \
					sources/mandatory/get_next_line_utils.c 

SOURCES_BONUS =		sources/bonus/so_long_bonus.c \
					sources/bonus/play_the_map_bonus.c \
					sources/bonus/controls_bonus.c \
					sources/bonus/exit_game_bonus.c \
					sources/bonus/error_functions_bonus.c \
					sources/bonus/verify_with_copy_bonus.c \
					sources/bonus/count_and_find_bonus.c \
					sources/bonus/utility_function_bonus.c \
					sources/bonus/get_next_line_bonus.c \
					sources/bonus/get_next_line_utils_bonus.c \
					sources/bonus/ft_itoa_bonus.c \
					sources/bonus/load_map_and_animation_bonus.c \
					sources/bonus/frames_bonus.c \
					sources/bonus/ennemy_direction_bonus.c

OBJECTS	= $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

MLX         = minilibx-linux/libmlx_Linux.a

LIBS        = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm

INCLUDES    = -Iminilibx-linux -Isources

all: $(MLX) $(NAME)

bonus: $(MLX) $(NAME_BONUS)

$(MLX):
	$(MAKE) -C minilibx-linux

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)

$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS_BONUS) $(LIBS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	$(MAKE) -C minilibx-linux fclean

re: fclean all

.PHONY: all clean fclean re bonus

