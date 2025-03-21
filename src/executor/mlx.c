/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:36:47 by halozdem          #+#    #+#             */
/*   Updated: 2025/03/14 17:42:24 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void    display(t_main *main);

char    init_mlx(t_main *main, t_mlx *mlx)
{
    mlx->mlx = mlx_init();
    if (!mlx->mlx) 
        return (false);
    mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "KANZILETTO CUB3D");
    if (!mlx->win)
        return (mlx_destroy_display(mlx->mlx), false);   
    mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
    if (!mlx->image)
        return (mlx_clear_window(mlx->mlx, mlx->win), mlx_destroy_display(mlx->mlx), false);
    mlx->img_addr = mlx_get_data_addr(mlx->image, &mlx->bpp, &mlx->size_line, &mlx->endian);
    if (!mlx->img_addr)
        return (mlx_clear_window(mlx->mlx, mlx->win), mlx_destroy_display(mlx->mlx), false);
    display(main);
    mlx_loop(mlx->mlx);
    return (true);
}

int	rgbtouint(char **colors)
{
	return (ft_atoi(colors[0]) * 65536 + ft_atoi(colors[1]) * 256 + ft_atoi(colors[0]));
}

void    display(t_main *main)
{
    t_ray   *const  ray = &main->ray;
    int             i;
    
    ray->x = -1;
    while (++ray->x < WIDTH)
    {
        ray->camera_x = 2 * ray->x / (double)WIDTH - 1; 
        ray->raydir_x = main->player_pos->dirx + main->player_pos->planex * ray->camera_x;
        ray->raydir_y = main->player_pos->diry + main->player_pos->planey * ray->camera_x;
        ray->map_x = (int)main->player_pos->x;
        ray->map_y = (int)main->player_pos->y;
        ray->deltadist_x = (ray->raydir_x == 0) ? 1e30 : fabs(1 / ray->raydir_x);
        ray->deltadist_y = (ray->raydir_y == 0) ? 1e30 : fabs(1 / ray->raydir_y);
        ray->hit = 0;
        if (ray->raydir_x < 0)
        {
            ray->step_x = -1;
            ray->sidedist_x = (main->player_pos->x - ray->map_x) * ray->deltadist_x;
        }
        else
        {
            ray->step_x = 1;
            ray->sidedist_x = (ray->map_x + 1.0 - main->player_pos->x) * ray->deltadist_x;
        }
        if (ray->raydir_y < 0)
        {
            ray->step_y = -1;
            ray->sidedist_y = (main->player_pos->y - ray->map_y) * ray->deltadist_y;
        }
        else
        {
            ray->step_y = 1;
            ray->sidedist_y = (ray->map_y + 1.0 - main->player_pos->y) * ray->deltadist_y;
        }
        // printf("%f %f %f %f\n", ray->deltadist_x,  ray->deltadist_y, ray->sidedist_x, ray->sidedist_y);
        while (main->map->map[ray->map_y][ray->map_x] != '1')
        {
            if (ray->sidedist_x < ray->sidedist_y)
            {
                ray->sidedist_x += ray->deltadist_x;
                ray->map_x += ray->step_x;
                ray->side = 0;
            }
            else
            {
                ray->sidedist_y += ray->deltadist_y;
                ray->map_y += ray->step_y;
                ray->side = 1;
            }
        }
        if (ray->side == 0)
            ray->perpwall_dist = (ray->sidedist_x - ray->deltadist_x);
        else
            ray->perpwall_dist = (ray->sidedist_y - ray->deltadist_y);
        ray->line_height = (int)(HEIGHT / ray->perpwall_dist);
        ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
        if(ray->draw_start < 0)
            ray->draw_start = 0;
        ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
        if(ray->draw_end >= HEIGHT)
            ray->draw_end = HEIGHT - 1;
        while (ray->draw_start <= ray->draw_end)
        {
            int pixel_index = (ray->draw_start * main->mlx.size_line / 4) + ray->x;
            ((unsigned int *)main->mlx.img_addr)[pixel_index] = rgbtouint(main->textures->c);

            ray->draw_start++;
        }
    }
    mlx_put_image_to_window(main->mlx.mlx, main->mlx.win, main->mlx.image, 0, 0);
    
}