/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:51:21 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/01/20 21:17:57 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	ft_put_un(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_put_un(n / 10);
		i += ft_put_un(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}
