/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:56:19 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/31 13:03:16 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char **av)
{
	t_game	game;

	game.points = 0;
	game.player_nb = 0;
	game.exit_nb = 0;
	game.moves_nb = 0;
	game.map = NULL;
	game.map_cpy = NULL;
	game.map_width = 0;
	game.on_exit = 0;
	if (map_reading(&game, av))
		return (1);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, game.map_width * 40,
			game.map_height * 40, "so_long");
	save_images(&game);
	adding_graphics(&game);
	mlx_key_hook(game.winpointer, controls_check, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
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
