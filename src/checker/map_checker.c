#include "../../lib/cub3d.h"

static void	f_fill(t_map *map, int y, int x);
static void	flf_check(t_main *main);

void	player_pos(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	main->player_pos->count = 0;
	while (main->map->map[i])
	{
		j = 0;
		while (main->map->map[i][j])
		{
			if (ft_strchr("NSEW", main->map->map[i][j]))
			{
				main->player_pos->x = j;
				main->player_pos->y = i;
				main->player_pos->count++;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_main *game)
{
	game->map->copy_map = ft_map_dup(game->map->map);
	player_pos(game);
	// printf("ilk map: \n");
	// print_map(game->map->copy_map);
	f_fill(game->map, game->player_pos->y, game->player_pos->x);
	// printf("boyalı map: \n");
	// print_map(game->map->copy_map);
	flf_check(game);
	free_copy_map(game->map);
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

static void	flf_check(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	while (main->map->copy_map[i])
	{
		j = 0;
		while (main->map->copy_map[i][j])
		{
			if (ft_strchr("1", main->map->copy_map[i][j]) || ft_strchr("0", main->map->copy_map[i][j]) || main->player_pos->count > 1)
			{
				printf("Error: Invalid map.\n");
				free_copy_map(main->map);
				free_all(main);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

char	**ft_map_dup(char **src)
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