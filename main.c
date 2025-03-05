#include "lib/cub3d.h"

void print_textures(t_textures *textures)
{
    if (!textures) return;

    // keys
    printf("keys: %s\n", textures->keys ? textures->keys : "NULL");

    // texture paths
    printf("NO (North):%s\n", textures->no ? textures->no : "NULL");
    printf("SO (South):%s\n", textures->so ? textures->so : "NULL");
    printf("WE (West):%s\n", textures->we ? textures->we : "NULL");
    printf("EA (East):%s\n", textures->ea ? textures->ea : "NULL");

    // textures array
    printf("Textures array: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", textures->textures[i]);
    }
    printf("\n");

    // colors (c and f)
    if (textures->c)
    {
        printf("c (Ceiling color): ");
        for (int i = 0; textures->c[i]; i++)
        {
            printf("%s ", textures->c[i]);
        }
        printf("\n");
    }
    else
    {
        printf("c (Ceiling color): NULL\n");
    }

    if (textures->f)
    {
        printf("f (Floor color): ");
        for (int i = 0; textures->f[i]; i++)
        {
            printf("%s ", textures->f[i]);
        }
        printf("\n");
    }
    else
    {
        printf("f (Floor color): NULL\n");
    }
}

void print_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    // if (argc != 2)
    //     return (0);
    t_main      *main;
	int			fd;

    main = init_all();
	if (!main->textures)
		return (0);
    fd = fill_textures_struct(main->textures, "maps/map.cub");
    if (fd == -1)
    {
        printf("Invalid map. \n");
        free_all(main);
        return (0);
    }
    if (check_image(main->textures) || check_color(main->textures))
    {
        free_all(main);
        return (0);
    }
	// print_textures(main->textures);//yazdırma fonksiyonu
	if (get_map_size(main, &fd, "maps/map.cub"))
    {
        free_all(main);
		return (0);
    }
    if (fill_map_struct(main, &fd, "maps/map.cub"))
    {
        free_all(main);
        return (0);
    }
    // print_map(main->map->map);//yazdırma fonksiyonu
    flood_fill(main);
    flood_fill_2(main); 
    if (!init_mlx(&main->mlx))
        return (0);
    printf("sa\n");
    free_all(main);
}
