/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:59:25 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/08 21:01:52 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

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
	game->assets.enemy_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/enemy.xpm", &game->assets.img_width,
			&game->assets.img_height);
	if (!game->assets.img_right || !game->assets.img_left
		|| !game->assets.img_up || !game->assets.img_down
		|| !game->assets.enemy_img)
	{
		advanced_error("Could not load player textures");
		return (0);
	}
	return (1);
}

static int	load_coin_assets(t_game *game)
{
	char	*coin_paths[COIN_FRAME_COUNT];
	int		i;

	coin_paths[0] = "./assets/an_coin/coin0.xpm";
	coin_paths[1] = "./assets/an_coin/coin1.xpm";
	coin_paths[2] = "./assets/an_coin/coin2.xpm";
	coin_paths[3] = "./assets/an_coin/coin3.xpm";
	coin_paths[4] = "./assets/an_coin/coin4.xpm";
	coin_paths[5] = "./assets/an_coin/coin5.xpm";
	i = 0;
	while (i < COIN_FRAME_COUNT)
	{
		game->assets.coin_imgs[i] = mlx_xpm_file_to_image(game->mlx,
				coin_paths[i], &game->assets.img_width,
				&game->assets.img_height);
		if (!game->assets.coin_imgs[i])
		{
			advanced_error("Could not load coin textures");
			return (0);
		}
		i++;
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
	game->assets.ball = mlx_xpm_file_to_image(game->mlx, "./assets/ball.xpm",
			&game->assets.img_width, &game->assets.img_height);
	if (!game->assets.wall_img || !game->assets.tile_img
		|| !load_coin_assets(game) || !game->assets.ball
		|| !load_door_assets(game))
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
	mlx_destroy_image(game->mlx, game->assets.tile_img);
	mlx_destroy_image(game->mlx, game->assets.coin_imgs[0]);
	mlx_destroy_image(game->mlx, game->assets.coin_imgs[1]);
	mlx_destroy_image(game->mlx, game->assets.coin_imgs[2]);
	mlx_destroy_image(game->mlx, game->assets.coin_imgs[3]);
	mlx_destroy_image(game->mlx, game->assets.coin_imgs[4]);
	mlx_destroy_image(game->mlx, game->assets.coin_imgs[5]);
	mlx_destroy_image(game->mlx, game->assets.enemy_img);
	mlx_destroy_image(game->mlx, game->assets.ball);
	clear_door(game);
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
		return (advanced_error("Failed to initialize MLX\n"), 0);
	game->mlx_win = mlx_new_window(game->mlx, width, height, "so_long_bonus");
	if (!game->mlx_win)
		return (advanced_error("Failed to create MLX window\n"), 0);
	if (!load_player_assets(game) || !load_map_assets(game))
		return (0);
	return (1);
}
