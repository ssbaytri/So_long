/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:43:09 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/08 21:23:57 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

int	load_door_assets(t_game *game)
{
	char	*door_paths[DOOR_FRAME_COUNT];
	int		i;

	door_paths[0] = "./assets/an_door/0.xpm";
	door_paths[1] = "./assets/an_door/1.xpm";
	door_paths[2] = "./assets/an_door/2.xpm";
	door_paths[3] = "./assets/an_door/3.xpm";
	door_paths[4] = "./assets/an_door/4.xpm";
	i = 0;
	while (i < DOOR_FRAME_COUNT)
	{
		game->assets.exit_imgs[i] = mlx_xpm_file_to_image(game->mlx,
				door_paths[i], &game->assets.img_width,
				&game->assets.img_height);
		if (!game->assets.exit_imgs[i])
		{
			advanced_error("Could not load door textures");
			return (0);
		}
		i++;
	}
	return (1);
}

void	clear_door(t_game *game)
{
	int	i;

	i = 0;
	while (i < DOOR_FRAME_COUNT)
	{
		mlx_destroy_image(game->mlx, game->assets.exit_imgs[i]);
		i++;
	}
}

void	update_door(t_game *game)
{
	static int	frame_timer;

	frame_timer++;
	if (frame_timer >= 5)
	{
		game->map.door_frame++;
		if (game->map.door_frame >= DOOR_FRAME_COUNT)
			game->map.door_frame = 0;
		frame_timer = 0;
	}
}
