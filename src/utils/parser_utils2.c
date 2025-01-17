#include "../../lib/cub3d.h"

char    cf_checker(t_textures *textures)
{
    int count;

    count = 0;
    while (textures->c[count])
        count++;
    if (count != 3)
        return (EXIT_FAILURE);
    count = 0;
    while (textures->f[count])
        count++;
    if (count != 3)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}