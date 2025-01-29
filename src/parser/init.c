/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:09 by halozdem          #+#    #+#             */
/*   Updated: 2025/01/28 17:01:00 by halozdem         ###   ########.fr       */
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
    textures->keys = "NSWEACF";
    return textures;
}

t_map   *init_map_struct(void)
{
    t_map   *map;

    map = (t_map *)ft_calloc(sizeof(t_map),1);
    if (!map)
        return (NULL);
    return (map);
}

t_main    *init_all()
{
    t_main  *main;

    main = malloc(sizeof(t_main));
    if (!main)
        return (NULL);
    main->textures = init_textures_struct();
    if (!main->textures)
        return (NULL);
    main->map = init_map_struct();
    if (!main->map)
        return (NULL);
    return (main);
}