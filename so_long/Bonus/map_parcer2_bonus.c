/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parcer2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:33:00 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/01/25 23:33:11 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

static void	count_components(char **map, int rows, int cols, t_components *comp)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == 'P')
				comp->p++;
			else if (map[y][x] == 'E')
				comp->e++;
			else if (map[y][x] == 'C')
				comp->c++;
			x++;
		}
		y++;
	}
}

int	check_components(char **map, int rows, int cols)
{
	t_components	comp;

	comp.p = 0;
	comp.e = 0;
	comp.c = 0;
	count_components(map, rows, cols, &comp);
	return (comp.p == 1 && comp.e == 1 && comp.c > 0);
}

int	count_remaining_coins(t_game *game)
{
	int	x;
	int	y;
	int	coins;

	coins = 0;
	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			if (game->map.map[y][x] == 'C')
				coins++;
			x++;
		}
		y++;
	}
	return (coins);
}

int	check_dims(int rows, int cols)
{
	if (rows > 44 || cols > 80)
		return (0);
	return (1);
}
