/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:09:22 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/15 20:04:35 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

static void	draw_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.tile_img, x
		* TILE_SIZE, y * TILE_SIZE);
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.wall_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->assets.coin_imgs[game->map.coin_frame], x * TILE_SIZE, y
			* TILE_SIZE);
	else if (game->map.map[y][x] == 'E')
	{
		if (game->map.door_open)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->assets.exit_imgs[game->map.door_frame], x * TILE_SIZE, y
				* TILE_SIZE);
	}
}

static void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_game *game)
{
	if (game->player.direction == RIGHT)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->assets.img_right, game->player.x, game->player.y);
	else if (game->player.direction == LEFT)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.img_left,
			game->player.x, game->player.y);
	else if (game->player.direction == UP)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.img_up,
			game->player.x, game->player.y);
	else if (game->player.direction == DOWN)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.img_down,
			game->player.x, game->player.y);
}

static void	update_coin(t_game *game)
{
	static int	frame_timer;

	frame_timer++;
	if (frame_timer >= 7)
	{
		game->map.coin_frame++;
		if (game->map.coin_frame >= COIN_FRAME_COUNT)
			game->map.coin_frame = 0;
		frame_timer = 0;
	}
}

int	render_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	draw_map(game);
	draw_player(game);
	draw_balls(game);
	draw_enemies(game);
	update_player(game);
	update_coin(game);
	update_door(game);
	update_ball(game);
	draw_moves(game);
	draw_coins(game);
	return (0);
}
