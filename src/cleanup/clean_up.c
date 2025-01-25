#include "../../lib/cub3d.h"

void	free_map(char **map, int map_y)
{
	int	y;

	if (map)
	{
		y = 0;
		while (y < map_y)
		{
			if (map[y])
				free(map[y]);
			y++;
		}
		free(map);
	}
}

void free_map_memory(t_map *map, int i)
{
    while (i > 0)
    {
        if (map->map[i - 1]) {
            free(map->map[i - 1]);
        }
        if (map->copy_map[i - 1]) {
            free(map->copy_map[i - 1]);
        }
        i--;
    }
    if (map->map) {
        free(map->map);
    }
    if (map->copy_map) {
        free(map->copy_map);
    }
}
