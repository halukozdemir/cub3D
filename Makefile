CC = cc
CFLAGS = -I/usr/include -I./lib/minilibx -O3
MLXFLAGS = -L./lib/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
NAME = cub3d

SRCS = main.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = lib/minilibx
MLX = $(MLX_DIR)/libmlx.a

all: $(MLX) $(NAME)

# MinilibX kütüphanesini derler
$(MLX):
	make -C $(MLX_DIR)

# Ana programı derler
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS)

# C dosyalarını .o'ya dönüştürür
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
