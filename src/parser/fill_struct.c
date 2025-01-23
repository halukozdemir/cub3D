/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:45 by halozdem          #+#    #+#             */
/*   Updated: 2025/01/23 17:46:15 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int    fill_textures_struct(t_textures *textures, const char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDWR, 0777);
	if (fd < 0)
	{
		perror("Harita dosyası okunamadı.\n");
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL && check_textures_done(textures))
	{
		i = 0;
		skip_whitespaces(line, &i);
		if (ft_strncmp(line, "NO ", i + 3) == 0)
		{
			if (textures->textures[0] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[0] = 1;
				textures->no = ft_strdup(line + i + 3);
			}
			else
				printf("1'den fazla NO asset'i tanımlanmış. \n");
		}
		else if(ft_strncmp(line, "SO ", i + 3) == 0)
		{
			if (textures->textures[1] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[1] = 1;
				textures->so = ft_strdup(line + i + 3);
			}
			else
				printf("1'den fazla SO  asset'i tanımlanmış. \n");
		}
		else if(ft_strncmp(line, "WE ", i + 3) == 0)
		{
			if (textures->textures[2] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[2] = 1;
				textures->we = ft_strdup(line + i + 3);
			}
			else
				printf("1'den fazla WE asset'i tanımlanmış. \n");
		}
		else if(ft_strncmp(line, "EA ", i + 3) == 0)
		{
			if (textures->textures[3] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[3] = 1;
				textures->ea = ft_strdup(line + i + 3);
			}
			else
				printf("1'den fazla EA asset'i tanımlanmış. \n");
		}
		else if(ft_strncmp(line, "C ", i + 2) == 0)
		{
			if (textures->textures[4] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[4] = 1;
				textures->c = ft_split(line + i + 2, ',');
			}
			else
				printf("1'den fazla C asset'i tanımlanmış. \n");
		}
		else if (ft_strncmp(line, "F ", i + 2) == 0)
		{
			if (textures->textures[5] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[5] = 1;
				textures->f = ft_split(line + i + 2, ',');
			}
			else
				printf("1'den fazla F asset'i tanımlanmış. \n");
		}
		else if (!ft_find_in_str(line, textures->keys)) //hatalı //değilmiş
			break;
		free(line);
	}
	return (fd);
}

char	fill_map_struct(t_main *main, int fd, const char *file_name)
{
	char	*line;
	int		i;

	i = 0;
	if (check_textures_done(main->textures))
	{
		printf("Hatalı map dosyası girdiniz.\n");
		return (EXIT_FAILURE);
	}
	while (line = get_next_line(fd))
		if (*line != '\n')
			break;
	// printf("line: %s\n", line);
	while(line)
	{
		if (!ft_is_empty_line(line))
			break;
		if (ft_find_in_str(line, "1 0SNWE\n"))
		{
			if (main->map->map_max_x < ft_strlen(line))
				main->map->map_max_x = ft_strlen(line) - 1;
			main->map->map = ft_realloc(main->map->map, line);
			i++;
		}
		else
		{
			printf("HATA VAR \n");
			break;
		}
		free(line);
		line = get_next_line(fd);
		// if (*line != '\n')
		// 	break;
	}
	// main->map->map_max_y = i;
	// printf("en uzun satır: %d, en uzun sütun: %d\n", main->map->map_max_x, main->map->map_max_y);
	return (EXIT_SUCCESS);
}
