/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:27:24 by tnicolau          #+#    #+#             */
/*   Updated: 2024/02/07 15:18:58 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	save_floor_wall_player(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/floor.xpm", &i, &j);
	if (!game->floor)
		return (free_images(game), 1);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/wall.xpm", &i, &j);
	if (!game->wall)
		return (free_images(game), 1);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/scientist.xpm", &i, &j);
	if (!game->player)
		return (free_images(game), 1);
	if (save_collectible_door(game))
		return (free_images(game), 1);
	return (0);
}

int	save_collectible_door(t_game *game)
{
	int	i;
	int	j;

	game->collectible = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/collectible.xpm", &i, &j);
	if (!game->collectible)
		return (1);
	game->door_closed = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/door_closed.xpm", &i, &j);
	if (!game->door_closed)
		return (1);
	game->door_open = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/door_open.xpm", &i, &j);
	if (!game->door_open)
		return (1);
	game->player_on_door = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/player_on_door.xpm", &i, &j);
	if (!game->player_on_door)
		return (1);
	return (0);
}

void	place_floor_wall_player(t_game *game, int i, int j)
{
	if ((*game).map[i][j] == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, j * XPM_SIZE, i * XPM_SIZE);
	else if ((*game).map[i][j] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->wall, j * XPM_SIZE, i * XPM_SIZE);
	else if ((*game).map[i][j] == 'P')
	{
		if (game->on_exit)
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->player_on_door,
				j * XPM_SIZE, i * XPM_SIZE);
		else
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->player,
				j * XPM_SIZE, i * XPM_SIZE);
	}
	else
		place_collectible_door(game, i, j);
}

void	place_collectible_door(t_game *game, int i, int j)
{
	if ((*game).map[i][j] == 'C')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->collectible, j * XPM_SIZE, i * XPM_SIZE);
	else if ((*game).map[i][j] == 'E')
	{
		if (game->points > 0 && game->on_exit)
			return ;
		else if (game->points > 0)
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->door_closed,
				j * XPM_SIZE, i * XPM_SIZE);
		else
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->door_open,
				j * XPM_SIZE, i * XPM_SIZE);
	}
}

void	adding_graphics(t_game	*game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			place_floor_wall_player(game, i, j);
			j++;
		}
		i++;
	}
}
