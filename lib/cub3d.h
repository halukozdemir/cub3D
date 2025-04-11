/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:29:14 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/11 15:08:04 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define HEIGHT 720
# define WIDTH 1280
# define BUFFER_SIZE 1

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define MOVE_SPEED  3
# define ROTATION_SPEED 1

#include "minilibx/mlx.h"
#include <sys/time.h>
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h> //kaldırmayı dene
#include <math.h>
#include <stdbool.h> 
#include <unistd.h>

typedef struct s_map
{
	char	**map;
	char	**copy_map;
	int		map_max_x;
	int		map_max_y;

}				t_map;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	double	perpwall_dist;
	double	wall_x;
	double	textpos;
	double	textstep;
	int		texture_x;
	int		draw_start;
	int		draw_end;
	int		line_height;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
	int		hit;
	int		x;
}	t_ray;

typedef struct s_textures
{
	char	*keys;
    char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*textures;
	char	**c;
	char	**f;
}               t_textures;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_image	image;
	t_image	so_text;
	t_image	we_text;
	t_image	no_text;
	t_image	ea_text;
	unsigned long long	last_tick;
}	t_mlx;

typedef struct s_position
{
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			count;
}				t_positon;

typedef struct s_keys
{
	int			w_pressed;
	int			s_pressed;
	int			a_pressed;
	int			d_pressed;
	int			left_pressed;
	int			right_pressed;
	int			esc_pressed;
}	t_keys;

typedef struct s_main
{
	t_mlx		mlx;
	t_ray		ray;
	t_map		*map;
	t_keys		keys;
	t_textures	*textures;
	t_positon	*player_pos;
}				t_main;


//parser_utils.c
char	ft_find_in_str(char *line, char *str);
char	skip_whitespaces(char *str, int *i);
char	check_textures_done(t_textures *textures);
char	check_fill_done(t_textures *textures);


//fill_struct.c
int		fill_textures_struct(t_textures *textures, const char *file_name);
char	get_map_size(t_main *main, int *d, const char *file_name);
char	fill_map_struct(t_main *main, int *fd, const char *file_name);
int has_non_space_or_newline(const char *str);


//init.c
t_textures	*init_textures_struct(void);
t_main		*init_all();
t_map		*init_map_struct(void);

//parser_utils2.c
char    cf_count_checker(t_textures *textures);
char	**ft_realloc(char **array, char *new_element);
char	ft_is_empty_line(char *line);
int count_char(const char *str, char c);

//map_checker.c
void	flood_fill(t_main *main);
char	**ft_map_dup(char **src);

//map_checker_2.c
void	flood_fill_2(t_main *main);



//image_checker.c
char    check_image(t_textures *textures);
char    check_color(t_textures *textures);
char is_any_texture_file_empty(t_textures *tex);



//clean_up.c
void	free_map(t_map *map);
void free_textures(t_textures *textures);
void    free_all(t_main *main);
void free_copy_map(t_map *map);

void print_map(char **map);


//mlx.c
char    init_mlx(t_main *main, t_mlx *mlx);

//player.c
bool get_player_pos(t_main *main);


#endif