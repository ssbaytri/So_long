CC = cc
CFLAGS = -Wall -Wextra -Werror  #-g -fsanitize=address
MLX_DIR = ../minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c \
		utils.c \
		utils2.c \
		get_next_line.c \
		map_parcer.c \
		map_parcer2.c \
		flood_fill.c \
		draw.c \
		events.c \
		game_init.c \
		movements.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_putchar.c \
		./ft_printf/ft_putstr.c \
		./ft_printf/ft_putnbr.c \
		./ft_printf/ft_puthex.c \
		./ft_printf/ft_putp.c \
		./ft_printf/ft_putun.c \

OBJS = $(SRCS:.c=.o)

NAME = ./../so_long

all: $(NAME)

%o : %c game.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all