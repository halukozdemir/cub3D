/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_texture_cont.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:56:49 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 21:56:49 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	check_texture_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Unable to open texture file '%s'.\n", path);
		exit(1);
	}
	close(fd);
}

char	*get_texture_path(char *buffer, int *index)
{
	char	*start;
	char	*texture_path;

	start = &buffer[*index + 3];
	texture_path = start;
	while (*start && isspace(*start))
		start++;
	while (*start && !isspace(*start))
		start++;
	*start = '\0';
	*index += 3;
	return (texture_path);
}

void	check_texture_in_map(char *buffer, int bytes_read)
{
	char	*texture_path;

	for (int i = 0; i < bytes_read; i++)
	{
		if (ft_strncmp(&buffer[i], "NO ", 3) == 0 || ft_strncmp(&buffer[i],
				"SO ", 3) == 0 || ft_strncmp(&buffer[i], "WE ", 3) == 0
			|| ft_strncmp(&buffer[i], "EA ", 3) == 0)
		{
			texture_path = get_texture_path(buffer, &i);
			check_texture_file(texture_path);
		}
	}
}

void	check_textures_in_map(const char *map_file)
{
	char	buffer[1024];
	int		fd;
	int		bytes_read;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(1);
	}
	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		check_texture_in_map(buffer, bytes_read);
	}
	close(fd);
}
