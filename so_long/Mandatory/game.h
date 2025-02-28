/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:28:33 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/15 18:48:22 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <fcntl.h>
# include <limits.h>
# include "../minilibx/mlx.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TILE_SIZE 32
# define MOVE_STEP 32

// some colors
# define RESET "\x1b[0m"
# define BOLD "\x1b[1m"
# define UNDERLINE "\x1b[4m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef enum e_direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}				t_direction;

typedef struct s_components
{
	int			p;
	int			e;
	int			c;
}				t_components;

typedef struct s_player
{
	int			x;
	int			y;
	t_direction	direction;
	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;
	int			moves_count;
}				t_player;

typedef struct s_assets
{
	void		*img_right;
	void		*img_left;
	void		*img_up;
	void		*img_down;
	void		*wall_img;
	void		*tile_img;
	void		*coin_img;
	void		*exit_img;
	int			img_width;
	int			img_height;
}				t_assets;

typedef struct s_map
{
	char		**map;
	int			map_width;
	int			map_height;
	int			total_coins;
	int			coins_collected;
	int			door_open;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_player	player;
	t_assets	assets;
	t_map		map;
}				t_game;

// game init
void			init_game(t_game *game);
int				init_mlx(t_game *game);
int				render_game(t_game *game);
void			advanced_error(char *msg);
void			clean_mlx(t_game *game);

// events
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				close_window(t_game *game);

// movements
void			find_player(t_game *game);
void			update_player(t_game *game);

char			*get_next_line(int fd);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *s, char c);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

int				get_map_dimensions(const char *filename, int *rows, int *cols);
char			**read_map(const char *filename, int rows, int cols);
void			free_map(char **map, int rows);

// map parcing
int				validate_map(char **map, int rows, int cols);
int				check_chars(char **map, int rows, int cols);
int				check_rectangle(char **map, int rows, int cols);
int				check_components(char **map, int rows, int cols);
int				count_remaining_coins(t_game *game);
int				check_closed_map(char **map, int rows, int cols);
int				check_map_exten(char *filename);
int				check_dims(int rows, int cols);
char			**duplicate_map(char **map, int rows, int cols);
int				flood_fill(char **map, int rows, int cols);

// ft_printf
int				ft_printf(const char *format, ...);
int				ft_putchar(char c);
int				ft_putstr(char const *str);
int				ft_putnbr(int n);
int				ft_put_un(unsigned int n);
int				ft_puthex(unsigned int n, int is_upper);
int				ft_put_p(void *p);

#endif
