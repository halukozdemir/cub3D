#include "../../lib/cub3d.h"

bool get_player_pos(t_main *main)
{
    int i = 0;
    int j;
    int found = 0;
    char c;

    while (main->map->map[i])
    {
        j = 0;
        while (main->map->map[i][j])
        {
            c = main->map->map[i][j];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                if (found)
                    return false;

                main->player_pos->x = j + 0.5;
                main->player_pos->y = i + 0.5;

                if (c == 'N')
                {
                    main->player_pos->dirx = 0;
                    main->player_pos->diry = -1;
                    main->player_pos->planex = 0.66;
                    main->player_pos->planey = 0;
                }
                else if (c == 'S')
                {
                    main->player_pos->dirx = 0;
                    main->player_pos->diry = 1;
                    main->player_pos->planex = -0.66;
                    main->player_pos->planey = 0;
                }
                else if (c == 'E')
                {
                    main->player_pos->dirx = 1;
                    main->player_pos->diry = 0;
                    main->player_pos->planex = 0;
                    main->player_pos->planey = 0.66;
                }
                else if (c == 'W')
                {
                    main->player_pos->dirx = -1;
                    main->player_pos->diry = 0;
                    main->player_pos->planex = 0;
                    main->player_pos->planey = -0.66;
                }

                found = 1;
            }
            j++;
        }
        i++;
    }
    return (found == 1);
}
