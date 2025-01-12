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

int main(int argc, char **argv)
{
    // if (argc != 2)
    //     return (0);
    t_textures  *textures;
	int			fd;
    textures = init_textures_struct();
	fd = fill_textures_struct(textures, "maps/map.cub");
	if (!textures)
		return (0);
		
	print_textures(textures);
	if (fill_map_struct(textures, fd, "maps/map.cub"))
		return (0);
}
