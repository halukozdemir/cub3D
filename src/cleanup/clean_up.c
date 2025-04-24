/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:07:08 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 16:22:49 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	destroy_images(t_mlx *mlx)
{
	if (mlx->image.img)
		mlx_destroy_image(mlx->mlx, mlx->image.img);
	if (mlx->so_text.img)
		mlx_destroy_image(mlx->mlx, mlx->so_text.img);
	if (mlx->we_text.img)
		mlx_destroy_image(mlx->mlx, mlx->we_text.img);
	if (mlx->no_text.img)
		mlx_destroy_image(mlx->mlx, mlx->no_text.img);
	if (mlx->ea_text.img)
		mlx_destroy_image(mlx->mlx, mlx->ea_text.img);
}

void	clean_mlx(t_mlx *mlx)
{
	if (!mlx || !mlx->mlx)
		return ;
	destroy_images(mlx);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
}

void	free_2d_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_texture_paths(t_textures *t)
{
	if (!t)
		return ;
	free(t->no);
	free(t->so);
	free(t->we);
	free(t->ea);
	free_2d_array(t->c);
	free_2d_array(t->f);
	free(t->keys);
	free(t->textures);
}

void	free_all(t_main *main)
{
	if (!main)
		return ;
	free_map(main->map);
	free_textures(main->textures);
	free(main->player_pos);
	clean_mlx(&main->mlx);
	free(main);
}
