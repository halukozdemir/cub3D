CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Iminilibx -O3
MLXFLAGS = -L./lib/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
NAME = cub3d

SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re