#include "lib/cub3d.h"

char	skip_whitespaces(char *str, int *i)
{
	while(str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
			*i++;
	return (EXIT_SUCCESS);
}

char	check_fill_done(t_textures *textures)
{
	int	i;

	i = 0;
	while (i < 6) //textures[i] var mı kontrolü eklenebilir
	{
		if (textures->textures[i] == 1)
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
	
}

t_textures *init_textures_struct(void)
{
    t_textures *textures;
    int         i;

    i = 0;
    textures = (t_textures *)malloc(sizeof(t_textures));
    if (!textures)
        return (NULL);
    textures->no = NULL;
    textures->so = NULL;
    textures->we = NULL;
    textures->ea = NULL;
    textures->c = NULL;
    textures->f = NULL;
	textures->keys = "NSWEACF";
    while (i < 6)
        textures->textures[i++] = 0;
    return textures;
}

// char	struct_done_checker(t_textures *textures, char *line)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	while (line[i])
// 	{
// 		if (!ft_strchr(textures->keys, line[i]))
// 			return (EXIT_SUCCESS);
// 		i++;
// 	}
// 	return (EXIT_FAILURE);
// }

void    fill_textures_struct(t_textures *textures, const char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDWR, 0777);
	if (fd < 0)
	{
		perror("Harita dosyası okunamadı.\n");
		return;
	}
	printf("%s",get_next_line(fd));
	while ((line = get_next_line(fd)) != NULL)
	{
		skip_whitespaces(line, &i);
		if (ft_strncmp(line, "NO ", i + 3) == 0)
		{
			if (textures->textures[0] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[0] = 1;
				textures->no = ft_strdup(line + i);
			}
			else
				printf("1'den fazla NO asset'i tanımlanmış. \n");
		}
		else if(ft_strncmp(line, "SO ", i + 3) == 0)
		{
			if (textures->textures[1] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[1] = 1;
				textures->so = ft_strdup(line + i);
			}
			else
				printf("1'den fazla SO  asset'i tanımlanmış. \n");
		}
		else if(ft_strncmp(line, "WE ", i + 3) == 0)
		{
			if (textures->textures[2] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[2] = 1;
				textures->we = ft_strdup(line + i);
			}
			else
				printf("1'den fazla WE asset'i tanımlanmış. \n");
		}
		else if(ft_strncmp(line, "EA ", i + 3) == 0)
		{
			if (textures->textures[3] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[3] = 1;
				textures->ea = ft_strdup(line + i);
			}
			else
				printf("1'den fazla EA asset'i tanımlanmış. \n");
		}
		else if(ft_strncmp(line, "C ", i + 2) == 0)
		{
			if (textures->textures[4] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[4] = 1;
				textures->c = ft_split(line + i, ',');
			}
			else
				printf("1'den fazla C asset'i tanımlanmış. \n");
		}
		else if (ft_strncmp(line, "F ", i + 2) == 0)
		{
			if (textures->textures[5] == 0 && !skip_whitespaces(line, &i))
			{
				textures->textures[5] = 1;
				textures->f = ft_split(line + i, ',');
			}
			else
				printf("1'den fazla F asset'i tanımlanmış. \n");
		}
	}
}


void print_textures(t_textures *textures)
{
    if (!textures) return;

    // keys
    printf("keys: %s\n", textures->keys ? textures->keys : "NULL");

    // texture paths
    printf("NO (North): %s\n", textures->no ? textures->no : "NULL");
    printf("SO (South): %s\n", textures->so ? textures->so : "NULL");
    printf("WE (West): %s\n", textures->we ? textures->we : "NULL");
    printf("EA (East): %s\n", textures->ea ? textures->ea : "NULL");

    // textures array
    printf("Textures array: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", textures->textures[i]);
    }
    printf("\n");

    // colors (c and f)
    if (textures->c)
    {
        printf("c (Ceiling color): ");
        for (int i = 0; textures->c[i]; i++)
        {
            printf("%s ", textures->c[i]);
        }
        printf("\n");
    }
    else
    {
        printf("c (Ceiling color): NULL\n");
    }

    if (textures->f)
    {
        printf("f (Floor color): ");
        for (int i = 0; textures->f[i]; i++)
        {
            printf("%s ", textures->f[i]);
        }
        printf("\n");
    }
    else
    {
        printf("f (Floor color): NULL\n");
    }
}

int main(int argc, char **argv)
{
    // if (argc != 2)
    //     return (0);
    t_textures  *textures;
    textures = init_textures_struct();
	fill_textures_struct(textures, "map.cub");
	if (!textures)
		return (0);
	print_textures(textures);
}
