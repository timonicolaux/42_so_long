/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:50:29 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/30 09:12:58 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_path(t_game *game)
{
	int	k;

	game->i = 0;
	game->j = 0;
	k = 0;
	if (copy_map(game))
		return (1);
	game->collectible_nb = 0;
	game->exit_nb = 0;
	while (k < 500)
	{
		check_valid_path2(game);
		game->i = 0;
		k++;
	}
	game->i = game->map_height;
	if (game->collectible_nb != game->points || game->exit_nb == 0)
	{
		free_all(game->map_cpy, game->i - 1);
		return (1);
	}
	return (0);
}

void	check_valid_path2(t_game *game)
{
	while (game->i < game->map_height)
	{
		check_valid_path3(game);
		game->j = 0;
		game->i++;
	}
}

void	check_valid_path3(t_game *game)
{
	while (game->j < game->map_width)
	{
		check_valid_path4(game);
		game->j++;
	}
}

void	check_valid_path4(t_game *game)
{
	if (game->map_cpy[game->i][game->j] == 'P')
	{
		if (game->i > 0 && game->map_cpy[game->i - 1][game->j] != '1')
		{
			check_map_objects(game->map_cpy[game->i - 1][game->j], game);
			game->map_cpy[game->i - 1][game->j] = 'P';
		}
		if (game->i < game->map_width
			&& game->map_cpy[game->i][game->j + 1] != '1')
		{
			check_map_objects(game->map_cpy[game->i][game->j + 1], game);
			game->map_cpy[game->i][game->j + 1] = 'P';
		}
		if (game->i < game->map_height
			&& game->map_cpy[game->i + 1][game->j] != '1')
		{
			check_map_objects(game->map_cpy[game->i + 1][game->j], game);
			game->map_cpy[game->i + 1][game->j] = 'P';
		}
		if (game->i > 0 && game->map_cpy[game->i][game->j - 1] != '1')
		{
			check_map_objects(game->map_cpy[game->i][game->j - 1], game);
			game->map_cpy[game->i][game->j - 1] = 'P';
		}
	}
}

int	copy_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->map_cpy = malloc(sizeof(int *) * game->map_height);
	if (!game->map_cpy)
		return (1);
	while (y < game->map_height)
	{
		game->map_cpy[y] = malloc(sizeof(int) * game->map_width);
		if (!game->map_cpy[y])
		{
			free_all(game->map_cpy, y);
			return (1);
		}
		while (x < game->map_width)
		{
			game->map_cpy[y][x] = game->map[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
