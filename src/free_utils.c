/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:47:19 by tnicolau          #+#    #+#             */
/*   Updated: 2024/02/07 15:15:04 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(int **map, int i)
{
	if (!map)
		return ;
	while (i >= 0)
	{
		free(map[i]);
		map[i] = NULL;
		i--;
	}
	free(map);
}

void	free_images(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlxpointer, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlxpointer, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlxpointer, game->player);
	if (game->collectible)
		mlx_destroy_image(game->mlxpointer, game->collectible);
	if (game->door_closed)
		mlx_destroy_image(game->mlxpointer, game->door_closed);
	if (game->door_open)
		mlx_destroy_image(game->mlxpointer, game->door_open);
	if (game->player_on_door)
		mlx_destroy_image(game->mlxpointer, game->player_on_door);
	mlx_destroy_window(game->mlxpointer, game->winpointer);
}

void	free_everything(t_game *game)
{
	mlx_destroy_display(game->mlxpointer);
	free(game->mlxpointer);
	free_map(game->map, game->map_height - 1);
	free_map(game->map_cpy, game->map_height - 1);
}
