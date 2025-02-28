/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:05:36 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/09 20:18:02 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 53)
		close_window(game);
	if (keycode == 13 || keycode == 126)
		game->player.key_up = 1;
	if (keycode == 1 || keycode == 125)
		game->player.key_down = 1;
	if (keycode == 0 || keycode == 123)
		game->player.key_left = 1;
	if (keycode == 2 || keycode == 124)
		game->player.key_right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
		game->player.key_up = 0;
	if (keycode == 1 || keycode == 125)
		game->player.key_down = 0;
	if (keycode == 0 || keycode == 123)
		game->player.key_left = 0;
	if (keycode == 2 || keycode == 124)
		game->player.key_right = 0;
	return (0);
}

void	init_game(t_game *game)
{
	game->player.key_up = 0;
	game->player.key_down = 0;
	game->player.key_left = 0;
	game->player.key_right = 0;
	game->player.direction = RIGHT;
	game->player.moves_count = 0;
	game->map.coins_collected = 0;
	game->map.total_coins = count_remaining_coins(game);
	game->map.door_open = 0;
	game->map.coin_frame = 0;
	game->map.door_frame = 0;
}

int	close_window(t_game *game)
{
	if (game->map.coins_collected != game->map.total_coins)
	{
		ft_printf(BOLD RED "GAME OVER! " RESET BOLD CYAN "You lost in " 
			BOLD YELLOW "%d" RESET BOLD CYAN " moves.\n" RESET,
			game->player.moves_count);
		ft_printf(BOLD CYAN "You collected " BOLD YELLOW "%d" RESET BOLD CYAN 
			" coins out of " BOLD YELLOW "%d\n" RESET, game->map.coins_collected,
			game->map.total_coins);
		ft_printf(UNDERLINE MAGENTA "BETTER LUCK NEXT TIME!\n" RESET);
	}
	clean_mlx(game);
	free_map(game->map.map, game->map.map_height);
	exit(0);
}
