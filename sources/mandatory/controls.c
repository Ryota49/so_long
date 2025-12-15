/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/12/02 14:00:37 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_game *game)
{
	if (key == 'a')
		move_left(game);
	if (key == 'd')
		move_right(game);
	if (key == 's')
		move_down(game);
	if (key == 'w')
		move_upper(game);
	if (key == 65307)
		rage_quit_game(game);
	return (0);
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
		{
			game->collectible--;
			game->map[y][x + 1] = '0';
		}
		if (game->map[y][x + 1] == 'E' && game->collectible == 0)
			exit_game(game);
		game->count_movement++;
		display_count_movement(game->count_movement);
		game->player_x++;
		load_the_map(game->map, game, 0, 0);
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
		{
			game->collectible--;
			game->map[y][x - 1] = '0';
		}
		if (game->map[y][x - 1] == 'E' && game->collectible == 0)
			exit_game(game);
		game->count_movement++;
		display_count_movement(game->count_movement);
		game->player_x--;
		load_the_map(game->map, game, 0, 0);
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
		{
			game->collectible--;
			game->map[y + 1][x] = '0';
		}
		if (game->map[y + 1][x] == 'E' && game->collectible == 0)
			exit_game(game);
		game->count_movement++;
		display_count_movement(game->count_movement);
		game->player_y++;
		load_the_map(game->map, game, 0, 0);
	}
}

void	move_upper(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
		{
			game->collectible--;
			game->map[y - 1][x] = '0';
		}
		if (game->map[y - 1][x] == 'E' && game->collectible == 0)
			exit_game(game);
		game->count_movement++;
		display_count_movement(game->count_movement);
		game->player_y--;
		load_the_map(game->map, game, 0, 0);
	}
}
