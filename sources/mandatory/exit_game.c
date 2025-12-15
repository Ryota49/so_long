/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/12/03 21:57:14 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rage_quit_game(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		free (game->map[y]);
		y++;
	}
	free (game->map);
	free_structure_of_game(game);
	write (1, "You Lost !\n", 11);
	exit (0);
	return (0);
}

int	exit_game(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		free (game->map[y]);
		y++;
	}
	free (game->map);
	free_structure_of_game(game);
	write (1, "Victory !\n", 10);
	exit (0);
	return (0);
}

void	free_structure_of_game(t_game *game)
{
	if (game->img_grass)
		mlx_destroy_image(game->mlx, game->img_grass);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_player_on_exit)
		mlx_destroy_image(game->mlx, game->img_player_on_exit);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_exit_open)
		mlx_destroy_image(game->mlx, game->img_exit_open);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free (game->mlx);
}

int	map_too_big(t_game *game, char *error_msg)
{
	int	y;

	y = 0;
	mlx_destroy_display(game->mlx);
	free (game->mlx);
	while (game->map[y] != NULL)
	{
		free (game->map[y]);
		y++;
	}
	free (game->map);
	ft_putstr_error(error_msg);
	exit (1);
	return (0);
}

int	call_load_the_map(t_game *game)
{
	load_the_map(game->map, game, 0, 0);
	return (0);
}
