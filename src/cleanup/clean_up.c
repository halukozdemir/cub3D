#include "../../lib/cub3d.h"

void free_copy_map(t_map *map)
{
    int i;

    i = 0;
    while (map->copy_map[i])
    {
        free(map->copy_map[i]);
        i++;
    }
    free(map->copy_map);
    map->copy_map = NULL;
}

void free_map(t_map *map)
{
    int i;

    if (!map)
        return;
    i = 0;
    if ((map->map))
    {
        while (map->map[i])
        {
            free(map->map[i]);
            i++;
        }
    free(map->map);
    map->map = NULL;
    }
    if (map)
    free(map);
    map = NULL;
}

void free_textures(t_textures *textures)
{
    int i;

    if (!textures)
        return;
    if (textures->no)
    {
        free(textures->no);
        textures->no = NULL;
    }
    if (textures->so)
    {
        free(textures->so);
        textures->so = NULL;
    }
    if (textures->we)
    {
        free(textures->we);
        textures->we = NULL;
    }
    if (textures->ea)
    {
        free(textures->ea);
        textures->ea = NULL;
    }

    if (textures->c)
    {
        i = 0;
        while (textures->c[i])
        {
            free(textures->c[i]);
            textures->c[i] = NULL;
            i++;
        }
        free(textures->c);
        textures->c = NULL;
    }

    if (textures->f)
    {
        i = 0;
        while (textures->f[i])
        {
            free(textures->f[i]);
            textures->f[i] = NULL;
            i++;
        }
        free(textures->f[i]);
        free(textures->f);
        textures->f = NULL;
    }
    if (textures->keys)
        free(textures->keys);
    if (textures->textures)
        free(textures->textures);
    if (textures)
        free(textures);
    textures = NULL;
}
void    free_all(t_main *main)
{
    if (!main)
        return;

    if (main->textures)
    {
        free_textures(main->textures);
        main->textures = NULL;
    }

    if (main->map)
    {
        free_map(main->map);
        main->map = NULL;
    }
    if (main->player_pos)
    {
        free(main->player_pos);
        main->player_pos = NULL;
    }
    free(main);
}
