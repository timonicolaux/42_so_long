/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:43:49 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/30 15:18:22 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_reading(t_game *game, char **av)
{
	char	*line;
	int		line_count;

	line_count = 0;
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		if (game->map_width > 0 && game->map_width != strlen_line(line))
			return (free(line), 1);
		game->map_width = strlen_line(line);
		free(line);
		line_count++;
	}
	game->map_height = line_count;
	if (game->map_height == game->map_width || !line_count)
		return (1);
	if (map_conversion(game, line_count, av))
		return (1);
	return (0);
}

int	map_conversion(t_game *game, int line_count, char **av)
{
	int		res;
	int		i;

	game->i = 0;
	game->j = 0;
	game->map = malloc(sizeof(int *) * line_count + 1);
	if (!game->map)
		return (1);
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (1);
	while (1)
	{
		res = map_conversion2(game);
		if (res == 1)
			return (1);
		if (res == 2)
			break ;
	}
	if (game->player_nb != 1 || game->exit_nb != 1 || game->points == 0)
		return (free_all(game->map, game->i - 1), 1);
	i = game->i;
	if (check_valid_path(game))
		return (free_all(game->map, i - 1), 1);
	return (0);
}

int	map_conversion2(t_game *game)
{
	char	*line;
	int		res;

	line = get_next_line(game->fd);
	res = 0;
	if (!line)
		return (2);
	game->map[game->i] = malloc(sizeof(int) * strlen_line(line));
	if (!game->map[game->i])
		return (free_all(game->map, game->i), 1);
	if (check_error(game, line, game->i))
		return (1);
	while (game->j < strlen_line(line))
	{
		res = map_conversion3(game, line);
		if (res == 1)
			return (1);
	}
	game->j = 0;
	free(line);
	game->i++;
	return (0);
}

int	map_conversion3(t_game *game, char *line)
{
	game->map[game->i][game->j] = line[game->j];
	if (line[game->j] != '0' && line[game->j] != '1' && line[game->j] != 'P'
		&& line[game->j] != 'E' && line[game->j] != 'C')
	{
		free_all(game->map, game->i);
		free(line);
		return (1);
	}
	if (line[game->j] == 'P')
	{
		game->player_nb++;
		game->player_y = game->i;
		game->player_x = game->j;
	}
	if (line[game->j] == 'C')
		game->points++;
	if (line[game->j] == 'E')
		game->exit_nb++;
	game->j++;
	return (0);
}
