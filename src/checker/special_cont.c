#include "../../lib/cub3d.h"
#include <ctype.h>

void	special_cont(const char *file_name)
{
	int		fd;
	char	buffer[1024];
	int		bytes_read;
	int		i;
	int		j;
	int		color_value;
	int		color_count;
	int		map_section_started;
	int		wall_count;

	map_section_started = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perror("Error opening file");
	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		for (i = 0; buffer[i]; i++)
		{
			if ((buffer[i] == 'C' || buffer[i] == 'F') && !map_section_started)
			{
				color_value = 0;
				color_count = 0;
				for (j = i + 1; buffer[j] && buffer[j] != '\n'; j++)
				{
					if (isdigit(buffer[j]))
						color_value = color_value * 10 + (buffer[j] - '0');
					else if (buffer[j] == ',')
					{
						if (color_value < 0 || color_value > 255)
						{
							printf("Error: Invalid color value.\n");
							close(fd);
							exit(1);
						}
						color_count++;
						color_value = 0;
					}
					else if (!isspace(buffer[j]))
					{
						printf("Error: Invalid character in color.\n");
						close(fd);
						exit(1);
					}
				}
				if (color_value < 0 || color_value > 255 || color_count != 2)
				{
					printf("Error: Invalid color value.\n");
					close(fd);
					exit(1);
				}
			}
			else if (!map_section_started && buffer[i] == '1')
			{
				wall_count = 0;
				for (j = i; buffer[j] && buffer[j] != '\n'; j++)
				{
					if (buffer[j] == '1')
						wall_count++;
				}
				if (wall_count > 3)
					map_section_started = 1;
			}
			else if (map_section_started)
			{
				if (buffer[i] == '\n' || isspace(buffer[i]))
					continue ;
				if (buffer[i] != '0' && buffer[i] != '1' && buffer[i] != 'N'
					&& buffer[i] != 'S' && buffer[i] != 'E'
					&& buffer[i] != 'W')
				{
					printf("Error: Invalid character in map.\n");
					close(fd);
					exit(1);
				}
			}
		}
	}
	close(fd);
}
