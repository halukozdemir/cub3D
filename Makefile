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

# Libft kaynak dosyaları
LIBFT_SRCS = $(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_strdup.c # Tüm dosyaları ekleyin
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFT)

$(MLX):
	make -C $(MLX_DIR)

# Libft hedefi
$(LIBFT): $(LIBFT_OBJS)
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(LIBFT_OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make -C $(MLX_DIR) fclean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
