/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:56:19 by tnicolau          #+#    #+#             */
/*   Updated: 2024/02/12 16:10:53 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (map_reading(&game, av))
		return (1);
	game.mlxpointer = mlx_init();
	if (!game.mlxpointer)
	{
		free_map(game.map_cpy, game.map_height);
		return (free_map(game.map, game.map_height), 1);
	}
	game.winpointer = mlx_new_window(game.mlxpointer, game.map_width * XPM_SIZE,
			game.map_height * XPM_SIZE, "so_long");
	if (!game.winpointer)
		return (free_everything(&game), 1);
	if (save_floor_wall_player(&game))
		return (free_everything(&game), 1);
	adding_graphics(&game);
	mlx_key_hook(game.winpointer, controls_check, &game);
	mlx_hook(game.winpointer, 17, 0, exit_game, &game);
	mlx_loop(game.mlxpointer);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strchr_str(av[1], ".ber"))
		{
			write(2, "Error\nMap is not in .ber format\n", 33);
			return (1);
		}
		if (so_long(av) == 1)
		{
			write(2, "Error\nMap could not be read\n", 29);
			return (1);
		}
	}
	else if (ac >= 3)
	{
		write(2, "Error\nPlease include only one map file\n", 40);
		return (1);
	}
	else
	{
		write(2, "Error\nPlease include one map file\n", 35);
		return (1);
	}
	return (0);
}
