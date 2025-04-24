/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:12:43 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 16:12:43 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	init_texture(t_mlx *mlx, void **img, char *path, t_image *texture)
{
	*img = mlx_xpm_file_to_image(mlx->mlx, path, &texture->width,
			&texture->height);
	if (!*img)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		return (1);
	}
	texture->addr = mlx_get_data_addr(*img, &texture->bpp, &texture->size_line,
			&texture->endian);
	return (0);
}

int	close_window(void *param)
{
	t_main	*main;

	main = param;
	free_all(main);
	exit(0);
	return (0);
}
