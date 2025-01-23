#include "../../lib/cub3d.h"

static void	f_fill(t_map *map, int y, int x);
static void	flf_check(t_map *map);
static char	**ft_map_dup(char **src);
static void	player_pos(t_main *main);
static void	free_map(char **map, int map_y);
void print_map(t_map *map);


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
	print_map(main->map->copy_map);

	// Boyalı haritayı yazdır
	player_pos(main);  // Oyuncunun başlangıç konumunu bul
	f_fill(main->map, main->player_pos.y, main->player_pos.x);  // Flood fill işlemi

	printf("Boyalı Harita:\n");  
	print_map(main->map->copy_map);
	// printf("sdjhgısd\n");
	// Harita kontrolü
	flf_check(main->map);
	
	// Hafızayı serbest bırak
	free_map(main->map->copy_map, main->map->map_y);
}


static void	f_fill(t_map *map, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	// printf("x: %d, y: %d\n", x, y);
	// // printf("%d\n", map->row);
	// printf("copy_map[x] : %d\n",ft_strlen(map->copy_map[x]));
	// printf("y: %d, copy_map[y]: %d\n", x, ft_strlen(map->copy_map[y]));
	if (x > (int)ft_strlen(map->copy_map[x]) || y > map->row)
	{
		return ;
	}
	if (map->copy_map[x][y] == 'F' || map->copy_map[x][y] == ' ') // Boşlukları işaretleme
		return ;
	// İşaretleme
	map->copy_map[x][y] = 'F'; 
	print_map(map->copy_map);
	// printf("sdgfsdf\n");
	// Rekürsif olarak dört yöne işaretleme yap
	f_fill(map, y - 1, x);  // Yukarı
	// printf("dsjkdbskjbdkljdbs\n");
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
