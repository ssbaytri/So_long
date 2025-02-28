/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:07:32 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/08 21:50:42 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x * TILE_SIZE;
				game->player.y = y * TILE_SIZE;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	int	map_x;
	int	map_y;

	map_x = new_x / TILE_SIZE;
	map_y = new_y / TILE_SIZE;
	if (game->map.map[map_y][map_x] == '1'
		|| game->map.map[map_y][map_x] == 'X')
		return (0);
	if (game->map.map[map_y][map_x] == 'C')
	{
		game->map.map[map_y][map_x] = '0';
		game->map.coins_collected++;
	}
	if (game->map.map[map_y][map_x] == 'E'
		&& game->map.coins_collected == game->map.total_coins)
	{
		ft_printf(BOLD GREEN "Congratulations! " RESET BOLD CYAN "You won in "
			BOLD YELLOW "%d" RESET BOLD CYAN " moves!\n" RESET,
			game->player.moves_count);
		close_window(game);
	}
	return (1);
}

static void	handle_movement(t_game *game, int *new_x, int *new_y)
{
	if (game->player.key_up)
	{
		*new_y = game->player.y - TILE_SIZE;
		game->player.direction = UP;
		game->player.key_up = 0;
	}
	if (game->player.key_down)
	{
		*new_y = game->player.y + TILE_SIZE;
		game->player.direction = DOWN;
		game->player.key_down = 0;
	}
	if (game->player.key_left)
	{
		*new_x = game->player.x - TILE_SIZE;
		game->player.direction = LEFT;
		game->player.key_left = 0;
	}
	if (game->player.key_right)
	{
		*new_x = game->player.x + TILE_SIZE;
		game->player.direction = RIGHT;
		game->player.key_right = 0;
	}
}

void	update_player(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (game->map.total_coins == game->map.coins_collected)
		game->map.door_open = 1;
	handle_movement(game, &new_x, &new_y);
	if (is_valid_move(game, new_x, new_y))
	{
		if (new_x != game->player.x || new_y != game->player.y)
		{
			game->player.x = new_x;
			game->player.y = new_y;
			game->player.moves_count++;
			ft_printf(BOLD CYAN "Moves: " RESET BOLD GREEN "%d\n" RESET,
				game->player.moves_count);
		}
	}
}
