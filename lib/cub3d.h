/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:29:14 by halozdem          #+#    #+#             */
/*   Updated: 2025/01/13 19:17:17 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define HEIGHT 1920
# define WIDTH 1080

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h> //kaldırmayı dene
#include <math.h>
#include <stdbool.h> 

typedef struct s_map
{
	char	**map;
}				t_map;

typedef struct s_textures
{
	char	*keys;
    char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		textures[6];
	char	**c;
	char	**f;
}               t_textures;

typedef struct s_main
{
	t_map		*map;
	t_textures	*textures;
}				t_main;

//parser_utils.c
char	ft_find_in_str(char *line, char *str);
char	skip_whitespaces(char *str, int *i);
char	check_textures_done(t_textures *textures);
char	check_fill_done(t_textures *textures);


//fill_struct.c
int    fill_textures_struct(t_textures *textures, const char *file_name);
char	fill_map_struct(t_textures *textures, int fd, const char *file_name);


//init.c
t_textures	*init_textures_struct(void);
t_main		*init_all();


#endif