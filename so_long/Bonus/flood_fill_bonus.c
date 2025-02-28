/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:59:43 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/01/25 23:32:46 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

char	**duplicate_map(char **original_map, int rows, int cols)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = malloc(sizeof(char *) * (rows + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_copy[i] = malloc(sizeof(char) * (cols + 1));
		if (!map_copy[i])
			return (free_map(map_copy, i), NULL);
		j = 0;
		while (j < cols)
		{
			map_copy[i][j] = original_map[i][j];
			j++;
		}
		map_copy[i][j] = '\0';
		i++;
	}
	map_copy[rows] = NULL;
	return (map_copy);
}

static t_point	get_pos(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return ((t_point){j, i});
			j++;
		}
		i++;
	}
	return ((t_point){-1, -1});
}

static void	fill_map(char **map, t_point size, t_point current)
{
	if (current.x < 0 || current.x >= size.x || current.y < 0
		|| current.y >= size.y)
		return ;
	if (map[current.y][current.x] == '1')
		return ;
	map[current.y][current.x] = '1';
	fill_map(map, size, (t_point){current.x, current.y - 1});
	fill_map(map, size, (t_point){current.x, current.y + 1});
	fill_map(map, size, (t_point){current.x - 1, current.y});
	fill_map(map, size, (t_point){current.x + 1, current.y});
}

static int	is_all_reachable(char **map, int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	flood_fill(char **map, int rows, int cols)
{
	t_point	size;
	t_point	start;

	size = (t_point){cols, rows};
	start = get_pos(map);
	fill_map(map, size, start);
	return (is_all_reachable(map, rows, cols));
}
