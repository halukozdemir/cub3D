/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:09 by halozdem          #+#    #+#             */
/*   Updated: 2025/02/08 15:18:22 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

t_textures *init_textures_struct(void)
{
    t_textures *textures;
    int         i;

    textures = (t_textures *)malloc(sizeof(t_textures));
    if (!textures)
        return (NULL);
    textures->no = NULL;
    textures->so = NULL;
    textures->we = NULL;
    textures->ea = NULL;
    textures->c = NULL;
    textures->f = NULL;
    textures->textures = malloc(sizeof(int) * 6);
    if (!textures->textures)
    {
        free(textures);
        return (NULL);
    }
    i = -1;
    while (++i < 6)
        textures->textures[i] = 0;
    textures->keys = ft_strdup("NSWEACF");
    if (!textures->keys)
        return (free(textures->textures), free(textures), NULL);
    return textures;
}

t_map   *init_map_struct(void)
{
    t_map   *map;

    map = (t_map *)ft_calloc(sizeof(t_map),1);
    if (!map)
        return (NULL);
    map->map_max_x = 0;
    map->map_max_y = 0;
    map->map = NULL; 
    return (map);
}
t_main *init_all(void)
{
    t_main *main;

    main = malloc(sizeof(t_main));
    if (!main)
        return (NULL);
    main->textures = init_textures_struct();
    if (!main->textures)
        return (free(main), NULL);
    main->map = init_map_struct();
    if (!main->map)
        return (free(main->textures->textures), free(main->textures), free(main), NULL);
    return (main);
}
