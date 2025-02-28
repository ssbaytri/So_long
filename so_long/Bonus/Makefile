CC = cc
CFLAGS = -Wall -Wextra -Werror  #-g -fsanitize=address
MLX_DIR = ../minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = main_bonus.c \
		utils_bonus.c \
		utils2_bonus.c \
		utils3_bonus.c \
		get_next_line.c \
		map_parcer_bonus.c \
		map_parcer2_bonus.c \
		flood_fill_bonus.c \
		draw_bonus.c \
		events_bonus.c \
		game_init_bonus.c \
		movements_bonus.c \
		enemy_bonus.c \
		door_bonus.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_putchar.c \
		./ft_printf/ft_putstr.c \
		./ft_printf/ft_putnbr.c \
		./ft_printf/ft_puthex.c \
		./ft_printf/ft_putp.c \
		./ft_printf/ft_putun.c \

OBJS = $(SRCS:.c=.o)

NAME = ./../so_long_bonus

all: $(NAME)

%o : %c game_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all