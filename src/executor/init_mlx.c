/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:23:26 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 14:23:26 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	setup_hooks(t_mlx *mlx, t_main *main)
{
	mlx_hook(mlx->win, 2, (1L << 0), key_press, main);
	mlx_hook(mlx->win, 3, (1L << 1), key_release, main);
	mlx_hook(mlx->win, 17, 0, close_window, main);
	mlx_loop_hook(mlx->mlx, render, main);
}

int	init_mlx_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "KANZILETTO CUB3D");
	if (!mlx->win)
	{
		free(mlx->mlx);
		mlx->mlx = NULL;
		return (0);
	}
	return (1);
}

int	init_mlx_image(t_mlx *mlx)
{
	mlx->image.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->image.img)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->mlx);
		mlx->mlx = NULL;
		return (0);
	}
	mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bpp,
			&mlx->image.size_line, &mlx->image.endian);
	return (1);
}

int	init_mlx_textures_and_run(t_main *main, t_mlx *mlx)
{
	if (init_texture(mlx, &mlx->we_text.img,
			main->textures->we, &mlx->we_text)
		|| init_texture(mlx, &mlx->ea_text.img,
			main->textures->ea, &mlx->ea_text)
		|| init_texture(mlx, &mlx->so_text.img,
			main->textures->so, &mlx->so_text)
		|| init_texture(mlx, &mlx->no_text.img,
			main->textures->no, &mlx->no_text))
	{
		clean_mlx(mlx);
		return (0);
	}
	setup_hooks(mlx, main);
	mlx_loop(mlx->mlx);
	clean_mlx(mlx);
	return (1);
}

int	init_mlx(t_main *main, t_mlx *mlx)
{
	if (!init_mlx_window(mlx))
		return (0);
	if (!init_mlx_image(mlx))
		return (0);
	return (init_mlx_textures_and_run(main, mlx));
}
