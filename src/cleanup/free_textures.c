/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:58:23 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:42 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	free(map);
}

static void	free_texture_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	free_direction_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->no)
		free(textures->no);
	textures->no = NULL;
	if (textures->so)
		free(textures->so);
	textures->so = NULL;
	if (textures->we)
		free(textures->we);
	textures->we = NULL;
	if (textures->ea)
		free(textures->ea);
	textures->ea = NULL;
}

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	free_direction_textures(textures);
	if (textures->c)
		free_texture_array(textures->c);
	textures->c = NULL;
	if (textures->f)
		free_texture_array(textures->f);
	textures->f = NULL;
	if (textures->keys)
		free(textures->keys);
	textures->keys = NULL;
	if (textures->textures)
		free(textures->textures);
	textures->textures = NULL;
	free(textures);
}
