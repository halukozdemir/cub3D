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
    while (map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    map->map = NULL;
    free(map);
    map = NULL;
}

void free_textures(t_textures *textures)
{
    int i;

    if (!textures)
        return;

    // if (textures->keys)
    // {
    //     printf("Freeing textures->keys\n");
    //     free(textures->keys);
    //     textures->keys = NULL;
    // }
    if (textures->no)
    {
        printf("Freeing textures->no\n");
        free(textures->no);
        textures->no = NULL;
    }
    if (textures->so)
    {
        printf("Freeing textures->so\n");
        free(textures->so);
        textures->so = NULL;
    }
    if (textures->we)
    {
        printf("Freeing textures->we\n");
        free(textures->we);
        textures->we = NULL;
    }
    if (textures->ea)
    {
        printf("Freeing textures->ea\n");
        free(textures->ea);
        textures->ea = NULL;
    }

    if (textures->c)
    {
        i = 0;
        while (textures->c[i])
        {
            printf("Freeing textures->c[%d]\n", i);
            free(textures->c[i]);
            textures->c[i] = NULL;
            i++;
        }
        printf("Freeing textures->c array\n");
        free(textures->c);
        textures->c = NULL;
    }

    if (textures->f)
    {
        i = 0;
        while (textures->f[i])
        {
            printf("Freeing textures->f[%d]\n", i);
            free(textures->f[i]);
            textures->f[i] = NULL;
            i++;
        }
        printf("Freeing textures->f array\n");
        free(textures->f);
        textures->f = NULL;
    }

    printf("Freeing textures structure\n");
    free(textures);
    textures = NULL;
}


void    free_all(t_main *main)
{
    if (!main)
        return;

    // Eğer textures varsa, textures'u serbest bırak
    if (main->textures)
    {
        free_textures(main->textures);
        main->textures = NULL;
    }

    // Eğer map varsa, map'i serbest bırak
    if (main->map)
    {
        free_map(main->map);
        main->map = NULL;
    }

    // main yapısını serbest bırak
    free(main);
}