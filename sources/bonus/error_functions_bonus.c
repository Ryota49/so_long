/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/12/01 14:06:23 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	err(char *error_msg)
{
	ft_putstr_error(error_msg);
	exit (1);
}

void	err_free(char *pl, char *l, int fd, char *err)
{
	free (pl);
	free (l);
	close (fd);
	ft_putstr_error(err);
	exit (1);
}

void	err_free_line(char *line, int fd, char *error_msg)
{
	free (line);
	close (fd);
	ft_putstr_error(error_msg);
	exit (1);
}

void	err_free_maps(char **map, char **copy_map, char *error_msg)
{
	int	y;

	y = 0;
	while (map[y] != NULL && copy_map[y] != NULL)
	{
		free (map[y]);
		free (copy_map[y]);
		y++;
	}
	free (map);
	free (copy_map);
	ft_putstr_error(error_msg);
	exit (1);
}

void	err_free_map(char **map, char *error_msg)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		free (map[y]);
		y++;
	}
	free (map);
	ft_putstr_error(error_msg);
	exit (1);
}
