/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:46:21 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/15 20:04:30 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

static int	num_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	fill_res(int n, char *res, int len)
{
	if (n == INT_MIN)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
	}
	else if (n == 0)
	{
		res[0] = '0';
		return ;
	}
	else if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = num_len(n);
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	res[i--] = '\0';
	fill_res(n, res, i);
	return (res);
}

void	draw_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->player.moves_count);
	mlx_string_put(game->mlx, game->mlx_win, 10, 3, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->mlx_win, 70, 3, 0x00FFFFFF, moves);
	free(moves);
}

void	draw_coins(t_game *game)
{
	char	*coins;
	char	*total_coins;
	int		color;

	if (game->map.coins_collected == game->map.total_coins)
		color = 0X0000FF00;
	else
		color = 0x00FF0000;
	total_coins = ft_itoa(game->map.total_coins);
	coins = ft_itoa(game->map.coins_collected);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->assets.coin_imgs[0],
		120, 0);
	mlx_string_put(game->mlx, game->mlx_win, 150, 3, 0x00FFFFFF, ": ");
	mlx_string_put(game->mlx, game->mlx_win, 170, 3, color, coins);
	mlx_string_put(game->mlx, game->mlx_win, 180, 3, 0x00FFFFFF, " / ");
	mlx_string_put(game->mlx, game->mlx_win, 210, 3, 0x00FFFFFF, total_coins);
	free(coins);
	free(total_coins);
}
