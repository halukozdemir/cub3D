/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:21:43 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 16:22:36 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	free_copy_map(t_map *map)
{
	if (!map || !map->copy_map)
		return ;
	free_2d_array(map->copy_map);
	map->copy_map = NULL;
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
	}
	free_copy_map(map);
	free(map);
}

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	free_texture_paths(textures);
	free(textures);
}
