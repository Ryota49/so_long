/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_and_animation_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/30 14:28:45 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	reload_the_map(t_game *game)
{
	load_the_map(game->map, game, 0, 0);
	return (0);
}

void	load_animation(t_game *game, int y, int x)
{
	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_collectible, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
}

void	load_ennemy_position(t_game *game, int y, int x)
{
	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'M')
			{
				game->struct_ennemy.x = x;
				game->struct_ennemy.y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	game->struct_ennemy.x = -1;
	game->struct_ennemy.y = -1;
}

void	load_map_and_ennemy(char **map, t_game *game, int y, int x)
{
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_grass, x * 32, y * 32);
			if (map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_collectible, x * 32, y * 32);
			if (game->player_x == x && game->player_y == y && map[y][x] != 'E')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_player, x * 32, y * 32);
			if (game->struct_ennemy.x == x && game->struct_ennemy.y == y)
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_ennemy, x * 32, y * 32);
			if (game->player_x == game->struct_ennemy.x
				&& game->player_y == game->struct_ennemy.y)
				rage_quit_game(game);
			x++;
		}
		x = 0;
		y++;
	}
}

int	call_load_the_map(t_game *game)
{
	char	*nbr_movement;

	game->frame++;
	check_frame(game);
	load_animation(game, 0, 0);
	if (game->struct_ennemy.x != -1 && game->struct_ennemy.y != -1)
		move_every_frame(game);
	nbr_movement = ft_itoa(game->count_movement);
	if (game->width < 6)
	{
		mlx_string_put(game->mlx, game->window,
			10, 21, 0x00FF0000, nbr_movement);
		free (nbr_movement);
		return (0);
	}
	mlx_string_put(game->mlx, game->window, 10, 20,
		0x00FF0000, "Number of movements : ");
	mlx_string_put(game->mlx, game->window, 140, 21, 0x00FF0000, nbr_movement);
	free (nbr_movement);
	return (0);
}
