/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:34 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/01/29 23:21:53 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	init_enemies(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			if (game->map.map[y][x] == 'X')
			{
				game->enemies[game->enemy_count].x = x;
				game->enemies[game->enemy_count].y = y;
				game->enemies[game->enemy_count].ball_x = x;
				game->enemies[game->enemy_count].ball_y = y;
				game->enemies[game->enemy_count].ball_dir = -1;
				game->enemies[game->enemy_count].ball_timer = 0;
				game->enemy_count++;
			}
			x++;
		}
		y++;
	}
}

int	check_collisions(t_game *game, t_enemy *enemy)
{
	int	player_x;
	int	player_y;

	if (game->map.map[enemy->ball_y][enemy->ball_x] == '1')
	{
		enemy->ball_x = enemy->x;
		enemy->ball_timer = 0;
		return (0);
	}
	player_x = game->player.x / TILE_SIZE;
	player_y = game->player.y / TILE_SIZE;
	if (enemy->ball_x == player_x && enemy->ball_y == player_y)
	{
		close_window(game);
		return (1);
	}
	return (0);
}

void	update_ball(t_game *game)
{
	int		i;
	t_enemy	*enemy;

	i = 0;
	while (i < game->enemy_count)
	{
		enemy = &game->enemies[i];
		enemy->ball_timer++;
		if (enemy->ball_timer >= 14)
		{
			enemy->ball_x += enemy->ball_dir;
			if (check_collisions(game, enemy))
				break ;
			enemy->ball_timer = 0;
		}
		i++;
	}
}

void	draw_balls(t_game *game)
{
	int		i;
	t_enemy	*enemy;

	i = 0;
	while (i < game->enemy_count)
	{
		enemy = &game->enemies[i];
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.ball,
			enemy->ball_x * TILE_SIZE, enemy->ball_y * TILE_SIZE);
		i++;
	}
}

void	draw_enemies(t_game *game)
{
	int		i;
	t_enemy	*enemy;

	i = 0;
	while (i < game->enemy_count)
	{
		enemy = &game->enemies[i];
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->assets.enemy_img, enemy->x * TILE_SIZE, enemy->y * TILE_SIZE);
		i++;
	}
}
