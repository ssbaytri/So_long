/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:09:22 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/08 17:58:20 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	draw_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.wall_img,
		x * TILE_SIZE, y * TILE_SIZE);
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.tile_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.coin_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.map[y][x] == 'E')
	{
		if (game->map.door_open)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->assets.exit_img, x * TILE_SIZE, y * TILE_SIZE);
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

int	render_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	draw_map(game);
	draw_player(game);
	update_player(game);
	return (0);
}
