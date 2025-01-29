/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:45 by halozdem          #+#    #+#             */
/*   Updated: 2025/01/28 17:19:08 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
int fill_textures_struct(t_textures *textures, const char *file_name)
{
    int     fd;
    char    *line;
    int     i;

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
        if (ft_strncmp(line, "NO ", 3) == 0)
        {
            if (textures->textures[0] == 0)
            {
                textures->textures[0] = 1;
                textures->no = ft_strdup(line + i + 3);
            }
            else
            {
                printf("1'den fazla NO asset'i tanımlanmış. \n");
                free(line);
                close(fd);
                return (-1);
            }
        }
        else if(ft_strncmp(line, "SO ", 3) == 0)
        {
            if (textures->textures[1] == 0)
            {
                textures->textures[1] = 1;
                textures->so = ft_strdup(line + i + 3);
            }
            else
            {
                printf("1'den fazla SO asset'i tanımlanmış. \n");
                free(line);
                close(fd);
                return (-1);
            }
        }
        else if(ft_strncmp(line, "WE ", 3) == 0)
        {
            if (textures->textures[2] == 0)
            {
                textures->textures[2] = 1;
                textures->we = ft_strdup(line + i + 3);
            }
            else
            {
                printf("1'den fazla WE asset'i tanımlanmış. \n");
                free(line);
                close(fd);
                return (-1);
            }
        }
        else if(ft_strncmp(line, "EA ", 3) == 0)
        {
            if (textures->textures[3] == 0)
            {
                textures->textures[3] = 1;
                textures->ea = ft_strdup(line + i + 3);
            }
            else
            {
                printf("1'den fazla EA asset'i tanımlanmış. \n");
                free(line);
                close(fd);
                return (-1);
            }
        }
        else if(ft_strncmp(line, "C ", 2) == 0)
        {
            if (textures->textures[4] == 0)
            {
                textures->textures[4] = 1;
                textures->c = ft_split(line + i + 2, ',');
            }
            else
            {
                printf("1'den fazla C asset'i tanımlanmış. \n");
                free(line);
                close(fd);
                return (-1);
            }
        }
        else if (ft_strncmp(line, "F ", 2) == 0)
        {
            if (textures->textures[5] == 0)
            {
                textures->textures[5] = 1;
                textures->f = ft_split(line + i + 2, ',');
            }
            else
            {
                printf("1'den fazla F asset'i tanımlanmış. \n");
                free(line);
                close(fd);
                return (-1);
            }
        }
        else if (!ft_find_in_str(line, textures->keys))
        {
            free(line);
            break;
        }
        free(line);
    }
    close(fd);

    return (0);
}

char get_map_size(t_main *main, int *fd, const char *file_name)
{
    char    *line;
    int     i;

    i = 1;
    if (!check_textures_done(main->textures)) // Bu kontrolün doğru olduğundan emin olun
    {
        printf("Hatalı map dosyası girdiniz.\n");
        return (EXIT_FAILURE);
    }
    while ((line = get_next_line(*fd)))
    {
        if (*line != '\n')
            break;
        free(line);
    }
    while(line)
    {
        if (ft_strchr(line, '\n'))
        {
            if (main->map->map_max_x < ft_strlen(line) - 1)
                main->map->map_max_x = ft_strlen(line) - 1;
            i++;
        }
        free(line);
        line = get_next_line(*fd);
    }
    main->map->map_max_y = i;
    printf("en uzun satır: %d, en uzun sütun: %d\n", main->map->map_max_x, main->map->map_max_y);
    close(*fd);
    return (EXIT_SUCCESS);
}

char init_map(t_map *map)
{
    int i, j;
    
    map->map = ft_calloc((map->map_max_y + 3) * sizeof(char *), 1);
    if (!map->map)
        return (EXIT_FAILURE);
    i = 0;
    while (i < map->map_max_y + 2)
    {
        map->map[i] = ft_calloc((map->map_max_x + 3) * sizeof(char), 1);
        if (!map->map[i])
        {
            while (i > 0)
                free(map->map[--i]);
            free(map->map);
            return (EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    while (i < map->map_max_y + 2)
    {
        j = 0;
        while (j < map->map_max_x + 2)
        {
            map->map[i][j] = 'B';
            j++;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

char fill_map_struct(t_main *main, int *fd, const char *file_name)
{
    char    *line;
    int     i;
    *fd = open(file_name, O_RDWR);
    if (fd < 0)
        return (EXIT_FAILURE);
    if (init_map(main->map) == EXIT_FAILURE)
    {
        close(*fd);
        return (EXIT_FAILURE);
    }
    while ((line = get_next_line(*fd)) != NULL)
    {
        if (ft_find_in_str(line, "1 0SNWE\n") || *line == '\n')
        {
            free(line);
            break;
        }
        free(line);
    }
    while ((line = get_next_line(*fd)))
    {
        if (!ft_find_in_str(line, " \n"))
            break;
        free(line);
    }
    
    i = 0;
    while (i < main->map->map_max_y && line != NULL)
    {
        int j = 0;
        while (line[j] && line[j] != '\n')
        {
            main->map->map[i + 1][j + 1] = line[j];
            j++;
        }
        free(line);
        line = get_next_line(*fd);
        i++;
    }
    close(*fd);
    return (EXIT_SUCCESS);
}
