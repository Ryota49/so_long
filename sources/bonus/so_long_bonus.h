/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/30 14:39:29 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../../minilibx-linux/mlx.h"

/* struct of ennemies */

typedef struct s_ennemy
{
	int	x;
	int	y;
	int	dir_y;
	int	dir_x;
}	t_ennemy;

/* struct of the game */

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*img_grass;
	void		*img_wall;
	void		*img_collectible;
	void		*img_collectible_starup;
	void		*img_collectible_stardown;
	void		*img_exit;
	void		*img_exit_open;
	void		*img_player;
	void		*img_player_on_exit;
	void		*img_ptr;
	void		*img_ennemy;
	int			height;
	int			width;
	int			collectible;
	char		**map;
	int			player_x;
	int			player_y;
	int			screen_height;
	int			screen_width;
	int			count_movement;
	int			frame;
	int			frame_ennemy;
	t_ennemy	struct_ennemy;
}	t_game;

/* struct of the player position */

typedef struct s_player_pos
{
	int	x;
	int	y;
}	t_player_pos;

/* function that will check the structure of what is inside the .ber file
 * and if the argument is .ber file*/

int					check_structure(char *argv);
void				check_other_line(char *line, int *line_diff);
void				check_first_and_last_line(char *line, int *line_diff);
int					check_format(char *str);

/* utilities functions*/

void				ft_putstr_error(char *error_msg);
int					ft_strlen(char *str);
void				display_count_movement(int nbr);
void				ft_putnbr(int nbr);
void				ft_putchar(char c);

/* error functions */

void				err(char *error_msg);
void				err_free(char *pl, char *l, int fd, char *err);
void				err_free_line(char *line, int fd, char *error_msg);
void				err_free_maps(char **map, char **copy_map, char *error_msg);
void				err_free_map(char **map, char *error_msg);

/* if everything OK complete the map in a **map */

char				**complete_map(char *argv);
int					count_line(char *argv);

/* find and save the position of P so the player in the map*/

t_player_pos		find_p(char **map);
t_player_pos		find_p_while(char **map, t_player_pos p, int x, int y);

/* functions that copy the map to check if every collectible and the exit is 
reachable with the initial position of the Player*/

void				copy_map_and_check(char **map, char *argv, t_player_pos p);
void				check_number_p_e(char **map, char **copy_map, int x, int y);
void				flood_fill(char **copy_map, int y, int x);
void				check_after_c_e(char **map, char **copy_map, int x, int y);

/* Functions about the game now */

void				play_the_map(char **map, t_player_pos p);
void				load_the_map(char **map, t_game *game, int x, int y);
void				load_the_map_two(char **map, t_game *game, int x, int y);
void				load_images(t_game *game);
void				count_collectible(char **map, t_game *game, int x, int y);

/* Functions about key pressed and movements */

int					key_pressed(int key, t_game *game);
void				move_right(t_game *game);
void				move_left(t_game *game);
void				move_down(t_game *game);
void				move_upper(t_game *game);

/* exit the game functions */

int					exit_game(t_game *game);
void				free_structure_of_game(t_game *game);
int					rage_quit_game(t_game *game);
int					map_too_big(t_game *game, char *error_msg);

/* refresh the map when the size of the window changes */

int					call_load_the_map(t_game *game);

/* prototype for bonus new function */

char				*ft_itoa(int n);
void				setup_game_info(t_game *game, char **map, t_player_pos p);
void				check_frame(t_game *game);
void				check_frame_two(t_game *game);
int					reload_the_map(t_game *game);
void				load_animation(t_game *game, int y, int x);

/* for the last bonus add ennemy functions */

void				load_ennemy_position(t_game *game, int y, int x);
void				move_every_frame(t_game *game);
void				load_map_and_ennemy(char **map, t_game *game, int y, int x);
void				ennemy_move_big_map(t_game *game, int y, int x);
void				ennemy_move_tiny_map(t_game *game, int y, int x);
void				initialise_dir(t_game *game, int y, int x);
void				ennemy_move_horizontal_big(t_game *game, int y, int x);
void				ennemy_move_horizontal_tiny(t_game *game, int y, int x);

/* check if there is more than 1 ennemy for the M (monsters) */

void				check_number_m(char **map, char **copy_map, int x, int y);

#endif
