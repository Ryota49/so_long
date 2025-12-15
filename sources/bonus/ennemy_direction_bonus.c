/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_direction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:15:53 by jemonthi          #+#    #+#             */
/*   Updated: 2025/12/08 23:39:32 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ennemy_move_big_map(t_game *game, int y, int x)
{
	if (game->frame_ennemy % 210 != 0)
		return ;
	if (game->map[y + 1][x] == '0' || game->map[y - 1][x] == '0')
	{
		if (game->struct_ennemy.dir_y != -1)
		{
			if (game->struct_ennemy.dir_y == 1 && game->map[y + 1][x] != '0')
				game->struct_ennemy.dir_y = 0;
			if (game->struct_ennemy.dir_y == 0 && game->map[y - 1][x] != '0')
				game->struct_ennemy.dir_y = 1;
			if (game->struct_ennemy.dir_y == 1)
				game->struct_ennemy.y++;
			else
				game->struct_ennemy.y--;
		}
		else
		{
			ennemy_move_horizontal_big(game, y, x);
			return ;
		}
	}
	else
		ennemy_move_horizontal_big(game, y, x);
}

void	ennemy_move_horizontal_big(t_game *game, int y, int x)
{
	if (game->map[y][x + 1] == '0' || game->map[y][x - 1] == '0')
	{
		if (game->struct_ennemy.dir_x == 1 && game->map[y][x + 1] != '0')
			game->struct_ennemy.dir_x = 0;
		if (game->struct_ennemy.dir_x == 0 && game->map[y][x - 1] != '0')
			game->struct_ennemy.dir_x = 1;
		if (game->struct_ennemy.dir_x == 1)
			game->struct_ennemy.x++;
		else
			game->struct_ennemy.x--;
	}
}

void	ennemy_move_tiny_map(t_game *game, int y, int x)
{
	if (game->frame_ennemy % 20000 != 0)
		return ;
	if (game->map[y + 1][x] == '0' || game->map[y - 1][x] == '0')
	{
		if (game->struct_ennemy.dir_y != -1)
		{
			if (game->struct_ennemy.dir_y == 1 && game->map[y + 1][x] != '0')
				game->struct_ennemy.dir_y = 0;
			if (game->struct_ennemy.dir_y == 0 && game->map[y - 1][x] != '0')
				game->struct_ennemy.dir_y = 1;
			if (game->struct_ennemy.dir_y == 1)
				game->struct_ennemy.y++;
			else
				game->struct_ennemy.y--;
		}
		else
		{
			ennemy_move_horizontal_tiny(game, y, x);
			return ;
		}
	}
	else
		ennemy_move_horizontal_tiny(game, y, x);
}

void	ennemy_move_horizontal_tiny(t_game *game, int y, int x)
{
	if (game->map[y][x + 1] == '0' || game->map[y][x - 1] == '0')
	{
		if (game->struct_ennemy.dir_x == 1 && game->map[y][x + 1] != '0')
			game->struct_ennemy.dir_x = 0;
		if (game->struct_ennemy.dir_x == 0 && game->map[y][x - 1] != '0')
			game->struct_ennemy.dir_x = 1;
		if (game->struct_ennemy.dir_x == 1)
			game->struct_ennemy.x++;
		else
			game->struct_ennemy.x--;
	}
}

void	check_number_m(char **map, char **copy_map, int x, int y)
{
	int	count_m;

	count_m = 0;
	while (copy_map[y] != NULL)
	{
		while (copy_map[y][x] != '\0')
		{
			if (copy_map[y][x] == 'M')
				count_m++;
			x++;
		}
		x = 0;
		y++;
	}
	if (count_m > 1)
		err_free_maps(map, copy_map, "Bad nbr of ennemy, max : 1");
}
