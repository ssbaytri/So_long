/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:59:25 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/27 16:33:38 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	load_player_assets(t_game *game)
{
	game->assets.img_right = mlx_xpm_file_to_image(game->mlx,
			"./assets/char_right.xpm", &game->assets.img_width,
			&game->assets.img_height);
	game->assets.img_left = mlx_xpm_file_to_image(game->mlx,
			"./assets/char_left.xpm", &game->assets.img_width,
			&game->assets.img_height);
	game->assets.img_up = mlx_xpm_file_to_image(game->mlx,
			"./assets/char_up.xpm", &game->assets.img_width,
			&game->assets.img_height);
	game->assets.img_down = mlx_xpm_file_to_image(game->mlx,
			"./assets/char_down.xpm", &game->assets.img_width,
			&game->assets.img_height);
	if (!game->assets.img_right || !game->assets.img_left
		|| !game->assets.img_up || !game->assets.img_down)
	{
		advanced_error("Could not load player textures");
		return (0);
	}
	return (1);
}

static int	load_map_assets(t_game *game)
{
	game->assets.tile_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/tile.xpm", &game->assets.img_width,
			&game->assets.img_height);
	game->assets.wall_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall.xpm", &game->assets.img_width,
			&game->assets.img_height);
	game->assets.coin_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/coin.xpm", &game->assets.img_width,
			&game->assets.img_height);
	game->assets.exit_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/exit.xpm", &game->assets.img_width,
			&game->assets.img_height);
	if (!game->assets.wall_img || !game->assets.coin_img
		|| !game->assets.exit_img || !game->assets.tile_img)
	{
		advanced_error("Could not load map textures");
		return (0);
	}
	return (1);
}

void	clean_mlx(t_game *game)
{
	mlx_destroy_image(game->mlx, game->assets.img_right);
	mlx_destroy_image(game->mlx, game->assets.img_left);
	mlx_destroy_image(game->mlx, game->assets.img_up);
	mlx_destroy_image(game->mlx, game->assets.img_down);
	mlx_destroy_image(game->mlx, game->assets.wall_img);
	mlx_destroy_image(game->mlx, game->assets.exit_img);
	mlx_destroy_image(game->mlx, game->assets.tile_img);
	mlx_destroy_image(game->mlx, game->assets.coin_img);
	mlx_destroy_window(game->mlx, game->mlx_win);
}

int	init_mlx(t_game *game)
{
	int	width;
	int	height;

	width = game->map.map_width * TILE_SIZE;
	height = game->map.map_height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		advanced_error("Failed to initialize MLX\n");
	game->mlx_win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->mlx_win)
		advanced_error("Failed to create MLX window\n");
	if (!load_player_assets(game) || !load_map_assets(game))
		return (0);
	return (1);
}
