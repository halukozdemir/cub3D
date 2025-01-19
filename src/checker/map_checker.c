#include "../../lib/cub3d.h"

static void	f_fill(t_map *map, int y, int x);
static void	flf_check(t_map *map);
static char	**ft_map_dup(char **src);
static void	player_pos(t_main *main);
static void	free_map(char **map, int map_y);
static void print_map(char **map, int map_y, int map_x);

void print_map(char **map, int map_y, int map_x)
{
    int i, j;

    for (i = 0; i < map_y; i++)  // Harita satırlarını gez
    {
        for (j = 0; j < map_x; j++)  // Her satırdaki sütunları gez
        {
            putchar(map[i][j]);  // Haritadaki her karakteri yazdır
        }
        putchar('\n');  // Her satır sonunda yeni satıra geç
    }
}


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

void	flood_fill(t_main *main)
{
	main->map->copy_map = ft_map_dup(main->map->map); // Haritayı kopyala
	player_pos(main);  // Oyuncunun başlangıç konumunu bul
	f_fill(main->map, main->player_pos.y, main->player_pos.x);  // Flood fill işlemi

	// Boyalı haritayı yazdır
	printf("Boyalı Harita:\n");  
	print_map(main->map->copy_map, main->map->map_y, main->map->map_x);

	// Harita kontrolü
	flf_check(main->map);
	
	// Hafızayı serbest bırak
	free_map(main->map->copy_map, main->map->map_y);
}


static void	f_fill(t_map *map, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (y >= map->map_y || x >= map->map_x)
		return ;
	if (map->copy_map[y][x] == '1' || map->copy_map[y][x] == 'F' || map->copy_map[y][x] == ' ') // Boşlukları işaretleme
		return ;

	// İşaretleme
	map->copy_map[y][x] = 'F'; 

	// Rekürsif olarak dört yöne işaretleme yap
	f_fill(map, y - 1, x);  // Yukarı
	f_fill(map, y + 1, x);  // Aşağı
	f_fill(map, y, x - 1);  // Sol
	f_fill(map, y, x + 1);  // Sağ
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
			// Eğer haritada hala 1 kalmışsa, bu geçersiz bir harita demektir
			if (map->copy_map[i][j] == '1')
			{
				printf("Error: Invalid map.\n");
				free_map(map->map, map->map_y);
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
