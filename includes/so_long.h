/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:59:10 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/31 11:25:04 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "../ft_printf/libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_game
{
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		player_nb;
	int		exit_nb;
	int		collectible_nb;
	int		points;
	int		fd;
	int		moves_nb;
	int		on_exit;

	int		i;
	int		j;

	int		**map;
	int		**map_cpy;

	void	*floor;
	void	*wall;
	void	*player;
	void	*door_closed;
	void	*door_open;
	void	*collectible;
	void	*player_on_door;
	void	*mlxpointer;
	void	*winpointer;
}	t_game;

int		so_long(char **av);

int		map_reading(t_game *game, char **av);
int		map_conversion(t_game *game, int line_count, char **av);
int		map_conversion2(t_game *game);
int		map_conversion3(t_game *game, char *line);

void	save_images(t_game	*game);
void	place_images(t_game	*game, int i, int j);
void	place_images2(t_game	*game, int i, int j);
void	adding_graphics(t_game	*game);

int		controls_check(int command, t_game *game);
int		map_checker(int command, t_game *game);
int		updater1(t_game *game, int x, int y);
void	updater2(t_game *game, int x, int y);
int		update_map_up(t_game *game);
int		update_map_down(t_game *game);
int		update_map_left(t_game *game);
int		update_map_right(t_game *game);
int		exit_game(t_game *game, int game_completed);

int		strlen_line(char *str);
int		check_error(t_game *game, char *line, int i);
void	free_all(int **map, int i);
void	check_map_objects(int location, t_game *game);

int		check_valid_path(t_game *game);
void	check_valid_path2(t_game *game);
void	check_valid_path3(t_game *game);
void	check_valid_path4(t_game *game);
int		copy_map(t_game *game);

#endif
