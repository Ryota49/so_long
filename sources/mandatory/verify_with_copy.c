/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_with_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/30 14:00:37 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	copy_map_and_check(char **map, char *argv, t_player_pos p)
{
	char		**copy_map;
	int			int_x;
	int			int_y;
	int			x;
	int			y;

	x = 0;
	y = 0;
	int_x = p.x;
	int_y = p.y;
	copy_map = complete_map(argv);
	check_number_p_e(map, copy_map, x, y);
	flood_fill(copy_map, int_y, int_x);
	check_after_c_e(map, copy_map, x, y);
	while (copy_map[y] != NULL)
	{
		free (copy_map[y]);
		y++;
	}
	free (copy_map);
}

char	**complete_map(char *argv)
{
	char	**map;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		err("File can't be open");
	map = malloc(sizeof(char *) * (count_line(argv) + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close (fd);
	return (map);
}

void	check_number_p_e(char **map, char **copy_map, int x, int y)
{
	int	count_p;
	int	count_e;
	int	count_c;

	count_p = 0;
	count_e = 0;
	count_c = 0;
	while (copy_map[y] != NULL)
	{
		while (copy_map[y][x] != '\0')
		{
			if (copy_map[y][x] == 'P')
				count_p++;
			if (copy_map[y][x] == 'E')
				count_e++;
			if (copy_map[y][x] == 'C')
				count_c++;
			x++;
		}
		x = 0;
		y++;
	}
	if (count_p != 1 || count_e != 1 || count_c == 0)
		err_free_maps(map, copy_map, "Bad nbr of player, exit or collectible");
}

void	flood_fill(char **copy_map, int y, int x)
{
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'F')
		return ;
	copy_map[y][x] = 'F';
	flood_fill(copy_map, y + 1, x);
	flood_fill(copy_map, y - 1, x);
	flood_fill(copy_map, y, x + 1);
	flood_fill(copy_map, y, x - 1);
}

void	check_after_c_e(char **map, char **copy_map, int x, int y)
{
	while (copy_map[y] != NULL)
	{
		while (copy_map[y][x] != '\0')
		{
			if (copy_map[y][x] == 'C' || copy_map[y][x] == 'E')
				err_free_maps(map, copy_map, "Can't reach collectible/exit");
			x++;
		}
		x = 0;
		y++;
	}
}
