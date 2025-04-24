/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:10:36 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 16:13:54 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	init_mlx_components(t_main *main, t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "KANZILETTO CUB3D");
	if (!mlx->win)
	{
		free(mlx->mlx);
		return (0);
	}
	mlx->image.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->image.img)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->mlx);
		return (0);
	}
	mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bpp,
			&mlx->image.size_line, &mlx->image.endian);
	if (init_texture(mlx, &mlx->we_text.img, main->textures->we, &mlx->we_text)
		|| init_texture(mlx, &mlx->ea_text.img, main->textures->ea,
			&mlx->ea_text) || init_texture(mlx, &mlx->so_text.img,
			main->textures->so, &mlx->so_text) || init_texture(mlx,
			&mlx->no_text.img, main->textures->no, &mlx->no_text))
		return (clean_mlx(mlx), 0);
	return (1);
}

static void	setup_hooks(t_mlx *mlx, t_main *main)
{
	mlx_hook(mlx->win, 2, (1L << 0), key_press, main);
	mlx_hook(mlx->win, 3, (1L << 1), key_release, main);
	mlx_hook(mlx->win, 17, 0, close_window, main);
	mlx_loop_hook(mlx->mlx, render, main);
}

int	init_mlx(t_main *main, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	if (!init_mlx_components(main, mlx))
		return (0);
	setup_hooks(mlx, main);
	mlx_loop(mlx->mlx);
	clean_mlx(mlx);
	return (1);
}
