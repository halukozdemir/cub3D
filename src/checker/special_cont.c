/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/04/24 16:23:42 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 16:23:42 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
#include <ctype.h>

static void	check_color_values(const char *buffer, int *i)
{
	int		color_value;
	int		color_count;
	int		j;

	color_value = 0;
	color_count = 0;
	j = *i + 1;
	while (buffer[j] && buffer[j] != '\n')
	{
		process_color_char(buffer, j, &color_value, &color_count);
		j++;
	}
	validate_color_value(color_value, color_count);
	*i = j;
}

static int	count_walls(const char *buffer, int i)
{
	int	wall_count;
	int	j;

	wall_count = 0;
	j = i;
	while (buffer[j] && buffer[j] != '\n')
	{
		if (buffer[j] == '1')
			wall_count++;
		j++;
	}
	return (wall_count);
}

static int	check_map_start(const char *buffer, int i)
{
	int		wall_count;

	wall_count = count_walls(buffer, i);
	if (wall_count > 3)
		return (1);
	return (0);
}

static void	validate_map_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
	{
		printf("Error: Invalid map.\n");
		exit(1);
	}
}

void	process_buffer(char *buffer, int *map_section_started)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if ((buffer[i] == 'C' || buffer[i] == 'F') && !*map_section_started)
			check_color_values(buffer, &i);
		else if (!*map_section_started && buffer[i] == '1')
			*map_section_started = check_map_start(buffer, i);
		else if (*map_section_started && buffer[i] != '\n'
			&& !isspace(buffer[i]))
			validate_map_char(buffer[i]);
		i++;
	}
}
