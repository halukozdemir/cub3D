#include "../../lib/cub3d.h"

static void	f_fill(t_map *map, int y, int x);
static void	flf_check(t_map *map);
static char	**ft_map_dup(char **src);

void	player_pos(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	while (main->map->map[i])
	{
		j = 0;
		while (main->map->map[i][j])
		{
			if (ft_strchr("NSEW", main->map->map[i][j]))
			{
				main->player_pos.x = j;
				main->player_pos.y = i;
                return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_main *game)
{
	game->map->copy_map = ft_map_dup(game->map->map);
	printf("ilk harita: \n");
	print_map(game->map->map);
	player_pos(game);
	f_fill(game->map, game->player_pos.y, game->player_pos.x);
	flf_check(game->map);
	printf("boyalı harita: \n");
	print_map(game->map->copy_map);
	free_map(game->map->copy_map, game->map->map_max_y);
}

static void	f_fill(t_map *map, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (y >= map->map_max_y + 2 || x >= map->map_max_x + 2)
		return ;
	if (map->copy_map[y][x] == 'F' || map->copy_map[y][x] == ' ' || map->copy_map[y][x] == 'B')
		return ;
	map->copy_map[y][x] = 'F';
	f_fill(map, y - 1, x);
	f_fill(map, y + 1, x);
	f_fill(map, y, x - 1);
	f_fill(map, y, x + 1);
}

static void	flf_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->copy_map[i])
	{
		j = 0;
		while (map->copy_map[i][j])
		{
			if (ft_strchr("1", map->copy_map[i][j]))
			{
				write(2, "Error: Invalid map.\n", 21);
				free_map(map->map, map->map_max_y);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static char	**ft_map_dup(char **src)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	while (src[i])
		i++;
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = (char *)malloc(sizeof(char) * (ft_strlen(src[i]) + 1));
		if (!dest[i])
			return (NULL);
		j = -1;
		while (src[i][++j])
			dest[i][j] = src[i][j];
		dest[i][j] = '\0';
		i++;
	}
	dest[i] = NULL;
	return (dest);
}