/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:36:47 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/08 18:54:04 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void    display(t_main *main);

unsigned long long get_timestamp(void)
{
	struct timeval	time;
	
	if (gettimeofday(&time, NULL) == -1)
	return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	render(void *param)
{	
	t_main						*main;
	main = param;
	unsigned long long const	current = get_timestamp();
	const double				delta_time = (current - main->mlx.last_tick) / 1000.0;
	const double				speed = delta_time * MOVE_SPEED;
	const double				angle = delta_time * 180 * ROTATION_SPEED * 3.14 / 180.0;
	
	main->mlx.last_tick = current;
	if (main->keys.w_pressed)
    {
      	if(main->map->map[(int)(main->player_pos->y + (main->player_pos->diry * speed))][(int)main->player_pos->x] != '1') main->player_pos->y += main->player_pos->diry * speed;
      	if(main->map->map[(int) main->player_pos->y][(int)(main->player_pos->x + (main->player_pos->dirx * speed))] != '1') main->player_pos->x += (main->player_pos->dirx * speed);
    }
	if (main->keys.s_pressed)
	{
		if(main->map->map[(int)(main->player_pos->y - (main->player_pos->diry * speed))][(int)main->player_pos->x] != '1') 
			main->player_pos->y -= main->player_pos->diry * speed;
		if(main->map->map[(int) main->player_pos->y][(int)(main->player_pos->x - (main->player_pos->dirx * speed))] != '1') 
			main->player_pos->x -= main->player_pos->dirx * speed;
	}
	if (main->keys.a_pressed)
	{
		if(main->map->map[(int)main->player_pos->y][(int)(main->player_pos->x - (main->player_pos->diry * speed))] != '1') 
			main->player_pos->x -= main->player_pos->diry * speed;
		if(main->map->map[(int)(main->player_pos->y + (main->player_pos->dirx * speed))][(int)main->player_pos->x] != '1') 
			main->player_pos->y += main->player_pos->dirx * speed;
	}
	if (main->keys.d_pressed)
	{
		if(main->map->map[(int)main->player_pos->y][(int)(main->player_pos->x + (main->player_pos->diry * speed))] != '1') 
			main->player_pos->x += main->player_pos->diry * speed;
		if(main->map->map[(int)(main->player_pos->y - (main->player_pos->dirx * speed))][(int)main->player_pos->x] != '1') 
			main->player_pos->y -= main->player_pos->dirx * speed;
	}
	if (main->keys.left_pressed)
	{
		double		olddirx = main->player_pos->dirx;
		double		oldplanex = main->player_pos->planex; 
		main->player_pos->dirx = olddirx * cos(angle) - main->player_pos->diry * sin(angle);
		main->player_pos->diry = olddirx * sin(angle) + main->player_pos->diry * cos(angle);
		main->player_pos->planex = oldplanex * cos(angle) - main->player_pos->planey * sin(angle);
		main->player_pos->planey = oldplanex * sin(angle) + main->player_pos->planey * cos(angle);
	}
	if (main->keys.right_pressed)
	{
		double		olddirx = main->player_pos->dirx;
		double		oldplanex = main->player_pos->planex; 
		main->player_pos->dirx = olddirx * cos(-angle) - main->player_pos->diry * sin(-angle);
		main->player_pos->diry = olddirx * sin(-angle) + main->player_pos->diry * cos(-angle);
		main->player_pos->planex = oldplanex * cos(-angle) - main->player_pos->planey * sin(-angle);
		main->player_pos->planey = oldplanex * sin(-angle) + main->player_pos->planey * cos(-angle);
	}
	display(main);
	return (1);
}

int	key_press(int keycode, void *main)
{
	t_keys	*keys;

	keys = &((t_main *)main)->keys;
	if (keycode == KEY_W)
		keys->w_pressed = 1;
	else if (keycode == KEY_S)
		keys->s_pressed = 1;
	else if (keycode == KEY_A)
		keys->a_pressed = 1;
	else if (keycode == KEY_D)
		keys->d_pressed = 1;
	else if (keycode == KEY_LEFT)
		keys->left_pressed = 1;
	else if (keycode == KEY_RIGHT)
		keys->right_pressed = 1;
	else if (keycode == KEY_ESC)
		keys->esc_pressed = 1;
}

int	key_release(int keycode, void *main)
{
	t_keys	*keys;

	keys = &((t_main *)main)->keys;
	if (keycode == KEY_W)
		keys->w_pressed = 0;
	else if (keycode == KEY_S)
		keys->s_pressed = 0;
	else if (keycode == KEY_A)
		keys->a_pressed = 0;
	else if (keycode == KEY_D)
		keys->d_pressed = 0;
	else if (keycode == KEY_LEFT)
		keys->left_pressed = 0;
	else if (keycode == KEY_RIGHT)
		keys->right_pressed = 0;
	else if (keycode == KEY_ESC)
		keys->esc_pressed = 0;
}

char    init_mlx(t_main *main, t_mlx *mlx)
{
    mlx->mlx = mlx_init();
    if (!mlx->mlx) 
        return (false);
    mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "KANZILETTO CUB3D");
    if (!mlx->win)
        return (mlx_destroy_display(mlx->mlx), false);   
    mlx->image.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
    if (!mlx->image.img)
        return (mlx_clear_window(mlx->mlx, mlx->win), mlx_destroy_display(mlx->mlx), false);
    mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bpp, &mlx->image.size_line, &mlx->image.endian);
    if (!mlx->image.addr)
        return (mlx_clear_window(mlx->mlx, mlx->win), mlx_destroy_display(mlx->mlx), false);
	mlx->we_text.img = mlx_xpm_file_to_image(mlx->mlx, main->textures->we, &mlx->we_text.width, &mlx->we_text.height);
	if (!mlx->we_text.img)
		return (mlx_clear_window(mlx->mlx, mlx->win), mlx_destroy_display(mlx->mlx), false);
	mlx->we_text.addr = mlx_get_data_addr(mlx->we_text.img, &mlx->we_text.bpp, &mlx->we_text.size_line, &mlx->we_text.endian);
	mlx->ea_text.img = mlx_xpm_file_to_image(mlx->mlx, main->textures->ea, &mlx->ea_text.width, &mlx->ea_text.height);
	if (!mlx->ea_text.img)
		return (mlx_clear_window(mlx->mlx, mlx->win), mlx_destroy_display(mlx->mlx), false);
	mlx->ea_text.addr = mlx_get_data_addr(mlx->ea_text.img, &mlx->ea_text.bpp, &mlx->ea_text.size_line, &mlx->ea_text.endian);
	mlx->so_text.img = mlx_xpm_file_to_image(mlx->mlx, main->textures->so, &mlx->so_text.width, &mlx->so_text.height);
	if (!mlx->so_text.img)
		return (mlx_clear_window(mlx->mlx, mlx->win), mlx_destroy_display(mlx->mlx), false);
	mlx->so_text.addr = mlx_get_data_addr(mlx->so_text.img, &mlx->so_text.bpp, &mlx->so_text.size_line, &mlx->so_text.endian);
	mlx->no_text.img = mlx_xpm_file_to_image(mlx->mlx, main->textures->no, &mlx->no_text.width, &mlx->no_text.height);
	if (!mlx->no_text.img)
		return (mlx_clear_window(mlx->mlx, mlx->win), mlx_destroy_display(mlx->mlx), false);
	mlx->no_text.addr = mlx_get_data_addr(mlx->no_text.img, &mlx->no_text.bpp, &mlx->no_text.size_line, &mlx->no_text.endian);
	mlx_hook(mlx->win, 2, (1L << 0), key_press, main);
	mlx_hook(mlx->win, 3, (1L << 1), key_release, main);
	mlx_loop_hook(mlx->mlx, render, main);
    mlx_loop(mlx->mlx);
    return (true);
}

int	rgbtouint(char **colors)
{
	return (ft_atoi(colors[0]) * 65536 + ft_atoi(colors[1]) * 256 + ft_atoi(colors[2]));
}

t_image	*get_texture(t_mlx *mlx, t_ray *ray)
{
	if (ray->side == 0 && ray->raydir_x > 0)
		return (&mlx->ea_text);
	else if (ray->side == 0 && ray->raydir_x < 0)
		return (&mlx->we_text);
	else if (ray->side == 1 && ray->raydir_y > 0)
		return (&mlx->no_text);
	else
		return (&mlx->so_text);
}

void    display(t_main *main)
{
    t_ray   *const  ray = &main->ray;
    int             i;
	int				x;
	int				y;

	/* BACKGROUND BOYAMA İŞİ */
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			int pixel_index = (y * main->mlx.image.size_line + x * (main->mlx.image.bpp / 8)) / 4;
			if (y < HEIGHT / 2)
				((unsigned int *)main->mlx.image.addr)[pixel_index] = rgbtouint(main->textures->c);
			else 
				((unsigned int *)main->mlx.image.addr)[pixel_index] = rgbtouint(main->textures->f);
		}
	}
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
		if (ray->side == 0)
			ray->wall_x = main->player_pos->y + ray->perpwall_dist * ray->raydir_y;
		else
			ray->wall_x = main->player_pos->x + ray->perpwall_dist * ray->raydir_x;
		ray->wall_x -= floor(ray->wall_x);
		t_image	*texture = get_texture(&main->mlx, &main->ray);
		ray->texture_x = (int)(ray->wall_x * (double)(texture->width));
		if ((ray->side == 1 && ray->raydir_y < 0)|| (ray->side == 0 && ray->raydir_x > 0))
			ray->texture_x = texture->width - ray->texture_x - 1;
		ray->textstep =  (double)texture->height / ray->line_height;
		ray->textpos = (ray->draw_start - (HEIGHT / 2) + (ray->line_height / 2)) * ray->textstep;

        while (ray->draw_start < ray->draw_end)
        {
			int texture_pixel_index = ((((int)ray->textpos & (texture->height - 1)) * texture->size_line) + ray->texture_x * (texture->bpp / 8)) / 4;
            int img_pixel_index = (ray->draw_start * main->mlx.image.size_line + ray->x * (main->mlx.image.bpp / 8)) / 4;
            ((unsigned int *)main->mlx.image.addr)[img_pixel_index] = ((unsigned int *)texture->addr)[texture_pixel_index];
			ray->textpos += ray->textstep;
            ray->draw_start++;
        }
    }
    mlx_put_image_to_window(main->mlx.mlx, main->mlx.win, main->mlx.image.img, 0, 0);
}