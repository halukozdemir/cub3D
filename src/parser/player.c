/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:49:55 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:21:10 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	set_player_direction(t_main *main, char c)
{
	float	dir[2];
	float	plane[2];

	if (c == 'N')
		set_north_direction(dir, plane);
	else if (c == 'S')
		set_south_direction(dir, plane);
	else if (c == 'E')
		set_east_direction(dir, plane);
	else if (c == 'W')
		set_west_direction(dir, plane);
	set_dir_values(main->player_pos, dir, plane);
}

static bool	scan_map_row(t_main *main, int i, bool *found_player)
{
	int		j;
	char	c;

	j = 0;
	while (main->map->map[i][j])
	{
		c = main->map->map[i][j];
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			if (*found_player)
				return (false);
			main->player_pos->x = j + 0.5;
			main->player_pos->y = i + 0.5;
			set_player_direction(main, c);
			*found_player = true;
		}
		j++;
	}
	return (true);
}

bool	get_player_pos(t_main *main)
{
	int		i;
	bool	found_player;

	found_player = false;
	i = 0;
	while (main->map->map[i])
	{
		if (!scan_map_row(main, i, &found_player))
			return (false);
		i++;
	}
	return (found_player);
}
