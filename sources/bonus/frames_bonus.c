/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:52:29 by jemonthi          #+#    #+#             */
/*   Updated: 2025/12/08 19:04:44 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_every_frame(t_game *game)
{
	int		x;
	int		y;

	game->frame_ennemy++;
	x = game->struct_ennemy.x;
	y = game->struct_ennemy.y;
	if (game->width >= 30)
		ennemy_move_big_map(game, y, x);
	else if (game->width < 30)
		ennemy_move_tiny_map(game, y, x);
	load_map_and_ennemy(game->map, game, 0, 0);
}

void	check_frame(t_game *game)
{
	if (game->width < 20)
	{
		if (game->frame == 5000)
			game->img_collectible = game->img_ptr;
		if (game->frame == 70000)
			game->img_collectible = game->img_collectible_starup;
		if (game->frame == 74000)
		{
			game->img_collectible = game->img_collectible_stardown;
			game->frame = 0;
		}
	}
	if (game->width >= 20 && game->width <= 40)
	{
		if (game->frame == 5000)
			game->img_collectible = game->img_ptr;
		if (game->frame == 50000)
			game->img_collectible = game->img_collectible_starup;
		if (game->frame == 54000)
		{
			game->img_collectible = game->img_collectible_stardown;
			game->frame = 0;
		}
	}
	check_frame_two(game);
}

void	check_frame_two(t_game *game)
{
	if (game->width > 40 && game->width <= 50)
	{
		if (game->frame == 5000)
			game->img_collectible = game->img_ptr;
		if (game->frame == 30000)
			game->img_collectible = game->img_collectible_starup;
		if (game->frame == 34000)
		{
			game->img_collectible = game->img_collectible_stardown;
			game->frame = 0;
		}
	}
	if (game->width > 50)
	{
		if (game->frame == 100)
			game->img_collectible = game->img_ptr;
		if (game->frame == 700)
			game->img_collectible = game->img_collectible_starup;
		if (game->frame == 740)
		{
			game->img_collectible = game->img_collectible_stardown;
			game->frame = 0;
		}
	}
}

void	initialise_dir(t_game *game, int y, int x)
{
	if (game->map[y + 1][x] == '0')
		game->struct_ennemy.dir_y = 0;
	else if (game->map[y - 1][x] == '0')
		game->struct_ennemy.dir_y = 1;
	else
		game->struct_ennemy.dir_y = -1;
	if (game->map[y][x + 1] == '0')
		game->struct_ennemy.dir_x = 0;
	else if (game->map[y][x - 1] == '0')
		game->struct_ennemy.dir_x = 1;
	else
		game->struct_ennemy.dir_x = -1;
}
