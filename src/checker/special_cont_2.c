/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cont_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:36:47 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:26:27 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	validate_color_value(int color_value, int color_count)
{
	if (color_value < 0 || color_value > 255 || color_count != 2)
	{
		fprintf(stderr, "Error: Invalid color value.\n");
		exit(1);
	}
}

void	process_color_char(const char *buffer, int j, int *color_value,
		int *color_count)
{
	if (ft_isdigit(buffer[j]))
		*color_value = *color_value * 10 + (buffer[j] - '0');
	else if (buffer[j] == ',')
	{
		if (*color_value < 0 || *color_value > 255)
		{
			printf("Error: Invalid color value.\n");
			exit(1);
		}
		(*color_count)++;
		*color_value = 0;
	}
	else if (!ft_isspace(buffer[j]))
	{
		printf("Error: Invalid color value.\n");
		exit(1);
	}
}

void	special_cont(const char *file_name)
{
	int		fd;
	char	buffer[1024];
	int		bytes_read;
	int		map_section_started;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	map_section_started = 0;
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		process_buffer(buffer, &map_section_started);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	close(fd);
}
