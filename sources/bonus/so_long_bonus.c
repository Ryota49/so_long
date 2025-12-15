/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/30 14:28:45 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "so_long_bonus.h"

void	check_first_and_last_line(char *line, int *line_diff)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			(*line_diff)++;
			i++;
		}
		i++;
	}
}

void	check_other_line(char *line, int *line_diff)
{
	int	i;
	int	len_line;

	i = 0;
	len_line = ft_strlen(line);
	if (line[i] == '1' && line[len_line - 1] == '1')
	{
		while (line[i])
		{
			if (line[i] == '1' || line[i] == '0' || line[i] == 'P'
				|| line[i] == 'C' || line[i] == 'E' || line[i] == 'M')
				i++;
			else
			{
				(*line_diff)++;
				i++;
			}
		}
	}
	else
		(*line_diff)++;
}

void	check_structure_while(char *line, int fd, int n_line, int *line_diff)
{
	char	*last_line;
	int		len_line;

	len_line = ft_strlen(line);
	while (line != NULL)
	{
		if (n_line == 0)
			check_first_and_last_line(line, line_diff);
		else if (len_line != ft_strlen(line))
			(*line_diff)++;
		else
			check_other_line(line, line_diff);
		n_line++;
		if (n_line > 1)
			free (last_line);
		last_line = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
	}
	if (line == NULL && n_line > 2 && len_line > 2)
		check_first_and_last_line(last_line, line_diff);
	else
		err_free_line(last_line, fd, "The size of the map is not big enough");
	free (last_line);
}

int	check_structure(char *argv)
{
	int		n_line;
	int		fd;
	char	*line;
	int		line_diff;

	n_line = 0;
	line_diff = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		err("File can't be open");
	line = get_next_line(fd);
	if (line == NULL && n_line == 0)
		err_free_line(line, fd, "The file is empty");
	check_structure_while(line, fd, n_line, &line_diff);
	close (fd);
	if (line_diff > 0)
		err("Structure of lines is incorrect");
	return (1);
}

int	main(int argc, char **argv)
{
	char			**map;
	t_player_pos	p;

	if (argc != 2)
		err("Number of arguments invalid");
	if (check_format(argv[1]) == 1)
	{
		if (check_structure(argv[1]) == 1)
		{
			map = complete_map(argv[1]);
			p = find_p(map);
			copy_map_and_check(map, argv[1], p);
			play_the_map(map, p);
		}
	}
	return (0);
}
