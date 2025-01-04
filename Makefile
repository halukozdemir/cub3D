CC = cc
CFLAGS = -I./lib/libft -I/usr/include -I./lib/minilibx -O3
MLXFLAGS = -L./lib/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = cub3d

SRCS = main.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = lib/minilibx
MLX = $(MLX_DIR)/libmlx.a

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
