/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:09 by halozdem          #+#    #+#             */
/*   Updated: 2025/01/19 15:45:20 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

t_textures *init_textures_struct(void)
{
    t_textures *textures;
    int         i;

    i = 0;
    textures = (t_textures *)malloc(sizeof(t_textures));
    if (!textures)
        return (NULL);
    textures->no = NULL;
    textures->so = NULL;
    textures->we = NULL;
    textures->ea = NULL;
    textures->c = NULL;
    textures->f = NULL;
	textures->keys = "NSWEACF";
    while (i < 6)
        textures->textures[i++] = 0;
    return textures;
}

t_map   *init_map_struct(void)
{
    t_map   *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    return (map);
}

t_main    *init_all()
{
    t_main  *main;

    main = malloc((t_main *)sizeof(t_main));
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