/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:49:47 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/31 12:44:03 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n' && str[i] != 14)
		i++;
	return (i);
}

int	check_error(t_game *game, char *line, int i)
{
	if (i == 0 || i == (game->map_height - 1))
	{
		if (ft_includes(line, '0', strlen_line(line))
			|| ft_includes(line, 'C', strlen_line(line))
			|| ft_includes(line, 'E', strlen_line(line))
			|| ft_includes(line, 'P', strlen_line(line)))
		{
			free_all(game->map, i);
			free(line);
			return (1);
		}
	}
	else if (line[0] != '1' || line[(game->map_width - 1)] != '1')
	{
		free_all(game->map, i);
		free(line);
		return (1);
	}
	return (0);
}

void	free_all(int **map, int i)
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

void	check_map_objects(int location, t_game *game)
{
	if (location == 'C')
		game->collectible_nb++;
	else if (location == 'E')
		game->exit_nb++;
}
