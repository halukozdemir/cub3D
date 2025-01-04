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

#endif