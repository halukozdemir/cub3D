/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:36:47 by halozdem          #+#    #+#             */
/*   Updated: 2025/03/05 18:53:12 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

char    init_mlx(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
    if (!mlx->mlx) 
        return (false);
    mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "KANZILETTO CUB3D");
    if (!mlx->win)
        return (mlx_destroy_display(mlx->mlx), false);   
    mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
    if (!mlx->image)
        return (mlx_destroy_display(mlx->mlx), mlx_destroy_window(mlx->win), false);
    mlx->img_addr = mlx_get_data_addr(mlx->image, &mlx->bpp, &mlx->size_line, &mlx->endian);
    if (!mlx->img_addr)
        return (mlx_destroy_display(mlx->mlx), mlx_destroy_window(mlx->win), 
        \ mlx_destroy_window(mlx->image), false);
    mlx_loop(mlx->mlx);
    return (true);
}

void    display(t_main *main)
{
    t_ray   *const ray = &main->ray;
    
    ray->x = -1;
    while (++ray->x < WIDTH)
    {
        ray->cameraX = 2 * x / double(w) - 1; 
        ray->raydir_x = main->player_pos->dirx + main->player_pos->planex * ray->camera_x;
        ray->raydir_y = main->player_pos->diry + main->player_pos->planey * ray->camera_x;
        ray->map_x = (int)main->player_pos.x;
        ray->map_y = (int)main->player_pos.y;
        ray->deltadist_x = 1e30;
        if (ray->deltadist_x != 0)
            ray->deltadist_x = fabs(1 / ray->raydir_x);
        ray->deltadist_y = 1e30;
        if (ray->deltadist_y != 0)
            ray->deltadist_y = fabs(1 / ray->raydir_y);
        ray->hit = 0;
        if (ray->raydir_x < 0)
        {
            ray->step_x = -1;
            ray->sidedist_x = (main->player_pos.x - ray->map_x) * ray->deltadist_x;
        }
        else
        {
            ray->step_x = 1;
            ray->sidedist_x = (ray->map_x + 1.0 - main->player_pos.x) * ray->deltadist_x;
        }
        if (ray->raydir_y < 0)
        {
            ray->step_y = -1;
            ray->sidedist_x = (main->player_pos.y - ray->map_y) * ray->deltadist_y;
        }
        else
        {
            ray->step_y = 1;
            ray->sidedist_x = (ray->map_y + 1.0 - main->player_pos.y) * ray->deltadist_y;
        }
    }
    
}