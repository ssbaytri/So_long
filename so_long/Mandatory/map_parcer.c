/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parcer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:28:16 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/01/20 22:34:11 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check_chars(char **map, int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_rectangle(char **map, int rows, int cols)
{
	int	y;

	y = 0;
	while (y < rows)
	{
		if ((int)ft_strlen(map[y]) != cols)
			return (0);
		y++;
	}
	return (1);
}

int	check_closed_map(char **map, int rows, int cols)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < cols)
	{
		if (map[0][x] != '1' || map[rows - 1][x] != '1')
			return (0);
		x++;
	}
	while (y < rows)
	{
		if (map[y][0] != '1' || map[y][cols - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_map_exten(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len >= 5)
	{
		if (ft_strncmp(&filename[len - 4], ".ber", 4) == 0)
			return (1);
	}
	return (0);
}
