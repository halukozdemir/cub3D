#include "../../lib/cub3d.h"

char **set_b_zone(char **pure_map)
{
    int height, width;
    height = findheight(pure_map);
    width = findWidth(pure_map);

    int newHeight = height + 2;
    int newWidth = width + 2;
    char **b_map = malloc(sizeof(char *) * newHeight);
    for (int i = 0; i < newHeight; i++)
    {
        b_map[i] = malloc(sizeof(char) * newWidth);
    }

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            b_map[i][j] = 'B';
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (pure_map[i][j] == ' ')
                ;
            else
                b_map[i + 1][j + 1] = pure_map[i][j];
        }
    }
    return b_map;
}