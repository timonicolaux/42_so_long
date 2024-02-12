/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:50:22 by tnicolau          #+#    #+#             */
/*   Updated: 2024/02/07 15:24:12 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	controls_check(int command, t_game *game)
{
	int	check;

	check = 0;
	if (command == 'w' || command == 's' || command == 'a' || command == 'd')
	{
		check = map_checker(command, game);
		if (!check)
		{
			adding_graphics(game);
			game->moves_nb++;
			ft_printf("Number of moves : %d\r", game->moves_nb);
		}
	}
	if (command == 65307)
		exit_game(game);
	return (0);
}

int	map_checker(int command, t_game *game)
{
	if (command == 'w')
	{
		if (update_map_up(game))
			return (1);
	}
	else if (command == 's')
	{
		if (update_map_down(game))
			return (1);
	}
	else if (command == 'a')
	{
		if (update_map_left(game))
			return (1);
	}
	else if (command == 'd')
	{
		if (update_map_right(game))
			return (1);
	}
	return (0);
}

int	updater(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (1);
	if (game->map[y][x] == 'C')
		game->points--;
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->on_exit)
			game->on_exit = 2;
		game->map[y][x] = 'P';
	}
	if (game->map[y][x] == 'E')
	{
		if (game->points > 0)
		{
			game->map[y][x] = 'P';
			game->on_exit = 1;
		}
		else
		{
			game->moves_nb++;
			game->game_completed = 1;
			return (exit_game(game));
		}
	}
	return (0);
}

void	updater_player_on_door(t_game *game, int x, int y)
{
	if (game->on_exit == 2)
	{
		game->map[y][x] = 'E';
		game->on_exit = 0;
	}
	else
		game->map[y][x] = '0';
}

int	exit_game(t_game *game)
{
	if (game->game_completed)
	{
		ft_printf("Number of moves : %d\r", game->moves_nb);
		ft_printf("Congratulations, you won in %d moves !\n", game->moves_nb);
	}
	free_images(game);
	free_everything(game);
	exit(0);
}
