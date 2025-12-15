/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/12/02 14:00:37 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_the_map(char **map, t_game *game, int x, int y)
{
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_wall, x * 32, y * 32);
			}
			if (map[y][x] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_grass, x * 32, y * 32);
			}
			if (map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_collectible, x * 32, y * 32);
			}
			load_the_map_two(map, game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	load_the_map_two(char **map, t_game *game, int x, int y)
{
	if (map[y][x] == 'E')
	{
		if (game->player_x == x && game->player_y == y)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->img_player_on_exit, x * 32, y * 32);
		}
		else if (game->collectible == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->img_exit_open, x * 32, y * 32);
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->img_exit, x * 32, y * 32);
		}
	}
	if (game->player_x == x && game->player_y == y && map[y][x] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->img_player, x * 32, y * 32);
	}
}

void	load_images(t_game *game)
{
	int	x;
	int	y;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/Wall.xpm", &x, &y);
	game->img_grass = mlx_xpm_file_to_image(game->mlx,
			"assets/Grass.xpm", &x, &y);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/Collectible.xpm", &x, &y);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/Exit.xpm", &x, &y);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/Player.xpm", &x, &y);
	game->img_player_on_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/Player_on_exit.xpm", &x, &y);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"assets/Exit_open.xpm", &x, &y);
}

void	play_the_map(char **map, t_player_pos p)
{
	t_game	game;

	game.width = ft_strlen(map[0]);
	game.height = 0;
	while (map[game.height] != NULL)
		game.height++;
	game.map = map;
	game.map[p.y][p.x] = '0';
	game.player_x = p.x;
	game.player_y = p.y;
	game.count_movement = 0;
	count_collectible(game.map, &game, 0, 0);
	game.mlx = mlx_init();
	mlx_get_screen_size(game.mlx, &game.screen_width, &game.screen_height);
	if (game.width * 32 > game.screen_width
		|| game.height * 32 > game.screen_height)
		map_too_big(&game, "Map is too big for the screen");
	load_images(&game);
	game.window = mlx_new_window(game.mlx, game.width * 32,
			game.height * 32, "My Game");
	load_the_map(game.map, &game, 0, 0);
	mlx_hook(game.window, 2, 1, key_pressed, &game);
	mlx_hook(game.window, 17, 0, rage_quit_game, &game);
	mlx_expose_hook(game.window, call_load_the_map, &game);
	mlx_loop(game.mlx);
}
