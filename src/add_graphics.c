/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:27:24 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/29 13:17:50 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	save_images(t_game	*game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/scientist.xpm", &i, &j);
	game->collectible = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/collectible.xpm", &i, &j);
	game->door_closed = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/door_closed.xpm", &i, &j);
	game->door_open = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/door_open.xpm", &i, &j);
	game->player_on_door = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/player_on_door.xpm", &i, &j);
}

void	place_images(t_game	*game, int i, int j)
{
	if ((*game).map[i][j] == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, j * 40, i * 40);
	else if ((*game).map[i][j] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->wall, j * 40, i * 40);
	else if ((*game).map[i][j] == 'P')
	{
		if (game->on_exit)
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->player_on_door, j * 40, i * 40);
		else
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->player, j * 40, i * 40);
	}
	else
		place_images2(game, i, j);
}

void	place_images2(t_game	*game, int i, int j)
{
	if ((*game).map[i][j] == 'C')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->collectible, j * 40, i * 40);
	else if ((*game).map[i][j] == 'E')
	{
		if (game->points > 0 && game->on_exit)
			return ;
		else if (game->points > 0)
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->door_closed, j * 40, i * 40);
		else
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->door_open, j * 40, i * 40);
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
			place_images(game, i, j);
			j++;
		}
		i++;
	}
}
