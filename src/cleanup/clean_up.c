/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:07:08 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:35 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	clean_mlx_textures(t_mlx *mlx)
{
	if (mlx->no_text.img)
	{
		mlx_destroy_image(mlx->mlx, mlx->no_text.img);
		mlx->no_text.img = NULL;
	}
	if (mlx->ea_text.img)
	{
		mlx_destroy_image(mlx->mlx, mlx->ea_text.img);
		mlx->ea_text.img = NULL;
	}
}

void	clean_mlx_images(t_mlx *mlx)
{
	if (!mlx || !mlx->mlx)
		return ;
	if (mlx->image.img)
	{
		mlx_destroy_image(mlx->mlx, mlx->image.img);
		mlx->image.img = NULL;
	}
	if (mlx->so_text.img)
	{
		mlx_destroy_image(mlx->mlx, mlx->so_text.img);
		mlx->so_text.img = NULL;
	}
	if (mlx->we_text.img)
	{
		mlx_destroy_image(mlx->mlx, mlx->we_text.img);
		mlx->we_text.img = NULL;
	}
	clean_mlx_textures(mlx);
}

void	clean_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->mlx)
	{
		clean_mlx_images(mlx);
		if (mlx->win)
		{
			mlx_destroy_window(mlx->mlx, mlx->win);
			mlx->win = NULL;
		}
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		mlx->mlx = NULL;
	}
}

void	free_copy_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->copy_map)
		return ;
	while (map->copy_map[i])
	{
		free(map->copy_map[i]);
		i++;
	}
	free(map->copy_map);
	map->copy_map = NULL;
}

void	free_all(t_main *main)
{
	if (!main)
		return ;
	if (main->map)
		free_map(main->map);
	main->map = NULL;
	if (main->textures)
		free_textures(main->textures);
	main->textures = NULL;
	if (main->player_pos)
		free(main->player_pos);
	main->player_pos = NULL;
	clean_mlx(&main->mlx);
	free(main);
}
