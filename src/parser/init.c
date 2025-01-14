/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:09 by halozdem          #+#    #+#             */
/*   Updated: 2025/01/13 19:17:46 by halozdem         ###   ########.fr       */
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

t_main    *init_all()
{
    t_main  *main;

    main = malloc((t_main *)sizeof(t_main));
    if (!main)
        return (NULL);
    main->textures = init_textures_struct();
    if (!main->textures)
        return (NULL);
    return (main);
}