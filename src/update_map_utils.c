/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:29:09 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/30 09:13:28 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_map_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (!updater1(game, x, y - 1))
	{
		updater2(game, x, y);
		game->player_y--;
		return (0);
	}
	else
		return (1);
}

int	update_map_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (!updater1(game, x, y + 1))
	{
		updater2(game, x, y);
		game->player_y++;
		return (0);
	}
	else
		return (1);
}

int	update_map_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (!updater1(game, x - 1, y))
	{
		updater2(game, x, y);
		game->player_x--;
		return (0);
	}
	else
		return (1);
}

int	update_map_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (!updater1(game, x + 1, y))
	{
		updater2(game, x, y);
		game->player_x++;
		return (0);
	}
	else
		return (1);
}
