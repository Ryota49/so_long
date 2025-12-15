/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/30 14:01:07 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	check_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 4)
	{
		if (str[i - 1] == 'r' && str[i - 2] == 'e'
			&& str[i - 3] == 'b' && str[i - 4] == '.')
		{
			return (1);
		}
		else
			err("Wrong format of the file");
	}
	return (0);
}

int	count_line(char *argv)
{
	int		fd;
	int		nbr_line;
	char	*line;

	nbr_line = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		err("File can't be open");
	line = get_next_line(fd);
	while (line != NULL)
	{
		nbr_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nbr_line);
}

t_player_pos	find_p_while(char **map, t_player_pos p, int x, int y)
{
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				p.x = x;
				p.y = y;
				return (p);
			}
			x++;
		}
		x = 0;
		y++;
	}
	p.x = -1;
	p.y = -1;
	return (p);
}

t_player_pos	find_p(char **map)
{
	t_player_pos	p;
	int				x;
	int				y;

	p.x = -1;
	p.y = -1;
	x = 0;
	y = 0;
	p = find_p_while(map, p, x, y);
	if (p.x == -1 && p.y == -1)
		err_free_map(map, "No starting position in the map");
	return (p);
}

void	count_collectible(char **map, t_game *game, int x, int y)
{
	game->collectible = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				game->collectible++;
			x++;
		}
		x = 0;
		y++;
	}
}
