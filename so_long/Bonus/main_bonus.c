/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:03:13 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/09 20:47:27 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	advanced_error(char *msg)
{
	ft_printf(BOLD RED "ERROR: " RESET YELLOW "%s\n" RESET, msg);
}

static int	init_dimensions(char *filename, t_game *game)
{
	int	rows;
	int	cols;

	if (get_map_dimensions(filename, &rows, &cols) == -1
		|| !check_map_exten(filename))
	{
		advanced_error("Invalid map file!");
		return (0);
	}
	game->map.map_width = cols;
	game->map.map_height = rows;
	return (1);
}

static int	init_map(char *filename, t_game *game)
{
	game->map.map = read_map(filename, game->map.map_height,
			game->map.map_width);
	if (!game->map.map || !validate_map(game->map.map, game->map.map_height,
			game->map.map_width))
	{
		advanced_error("Invalid map!");
		free_map(game->map.map, game->map.map_height);
		return (0);
	}
	return (1);
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 0, close_window, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, render_game, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		advanced_error("map file is missing!");
		return (1);
	}
	if (!init_dimensions(argv[1], &game))
		return (1);
	if (!init_map(argv[1], &game))
		return (1);
	init_game(&game);
	if (!init_mlx(&game))
	{
		free_map(game.map.map, game.map.map_height);
		exit(1);
	}
	find_player(&game);
	init_enemies(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
