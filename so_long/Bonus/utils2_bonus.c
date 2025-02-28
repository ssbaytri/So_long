/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:44:36 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/01/25 23:33:19 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

int	get_map_dimensions(const char *filename, int *rows, int *cols)
{
	int		fd;
	char	*line;
	int		line_length;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = NULL;
	*rows = 0;
	*cols = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_length = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		if (line_length > *cols)
			*cols = line_length;
		(*rows)++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < rows)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

char	**read_map(const char *filename, int rows, int cols)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	while (i < rows)
	{
		map[i] = malloc(sizeof(char) * (cols + 1));
		if (!map[i])
			return (free_map(map, i), close(fd), NULL);
		line = get_next_line(fd);
		if (!line)
			return (free_map(map, i), close(fd), NULL);
		ft_strlcpy(map[i], line, cols + 1);
		free(line);
		i++;
	}
	return (map[i] = NULL, close(fd), map);
}

int	validate_map(char **map, int rows, int cols)
{
	char	**new_map;

	new_map = duplicate_map(map, rows, cols);
	if (!check_chars(map, rows, cols) || !check_rectangle(map, rows, cols)
		|| !check_components(map, rows, cols) || !check_closed_map(map, rows,
			cols) || !flood_fill(new_map, rows, cols) || !check_dims(rows,
			cols))
	{
		free_map(new_map, rows);
		return (0);
	}
	free_map(new_map, rows);
	return (1);
}
