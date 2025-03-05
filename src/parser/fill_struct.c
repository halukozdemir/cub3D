/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:25:45 by halozdem          #+#    #+#             */
/*   Updated: 2025/03/05 15:51:41 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
int fill_textures_struct(t_textures *textures, const char *file_name)
{
    int     fd;
    char    *line;
    int     i;
    char    *trimmed;

    i = 0;
    fd = open(file_name, O_RDWR, 0777);
    if (fd < 0)
    {
        perror("Harita dosyası okunamadı.\n");
        return (-1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        i = 0;
        skip_whitespaces(line, &i);
        if (ft_strncmp(line, "NO ", 3) == 0)
        {
            if (textures->textures[0] == 0)
            {
                textures->textures[0] = 1;
                trimmed = ft_strdup(line + i + 3);
                textures->no = ft_strtrim(trimmed, " \n");
                free(trimmed); // trimmed serbest bırakıldı
            }
            else
            {
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
                trimmed = ft_strdup(line + i + 3);
                textures->so = ft_strtrim(trimmed, "\n ");
                free(trimmed); // trimmed serbest bırakıldı
            }
            else
            {
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
                trimmed = ft_strdup(line + i + 3);
                textures->we = ft_strtrim(trimmed, " \n");
                free(trimmed); // trimmed serbest bırakıldı
            }
            else
            {
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
                trimmed = ft_strdup(line + i + 3);
                textures->ea = ft_strtrim(trimmed, " \n");
                free(trimmed); // trimmed serbest bırakıldı
            }
            else
            {
                free(line);
                close(fd);
                return (-1);
            }
        }
        else if(ft_strncmp(line, "C ", 2) == 0)
        {
            if (textures->textures[4] == 0 && (count_char(line, ',') == 2))
            {
                textures->textures[4] = 1;
                textures->c = ft_split(line + i + 2, ',');
                // textures->c için bellek serbest bırakma işlemi eklenmeli
            }
            else
            {
                free(line);
                close(fd);
                return (-1);
            }
        }
        else if (ft_strncmp(line, "F ", 2) == 0 && (count_char(line, ',') == 2))
        {
            if (textures->textures[5] == 0)
            {
                textures->textures[5] = 1;
                textures->f = ft_split(line + i + 2, ',');
            }
            else
            {
                free(line);
                close(fd);
                return (-1);
            }
        }
        else if(!ft_find_in_str(line, "FCNSEAWO \n"))
        {
            printf("Invalid Map.\n");
            free(line);
            break;
        }
        else if (!check_textures_done(textures))
        {
            free(line); // line serbest bırakıldı
            break;
        }
        free(line); // line serbest bırakıldı
    }
    close(fd);
    return (fd);
}

char get_map_size(t_main *main, int *fd, const char *file_name)
{
    char    *line;
    int     i;

    i = 1;

    if (check_textures_done(main->textures)) // Bu kontrolün doğru olduğundan emin olun
    {
        printf("Hatalı map dosyası girdiniz.\n");
        return (EXIT_FAILURE);
    }
    char *line2;
    while ((line = get_next_line(*fd)))
    {
        if (!ft_find_in_str(line, "10NSWE \n"))
        {
            printf("Invalid Map.\n");
            break;
        }
        line2 = ft_strtrim(line, " ");
        if (*line2 != '\n')
        {
            free(line2);
            break;
        }
        free(line2);
        free(line);
    }
    // if (line2)
    //     free(line2);
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
    free(line);
    main->map->map_max_y = i;
    // printf("en uzun satır: %d, en uzun sütun: %d\n", main->map->map_max_x, main->map->map_max_y);
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
    if (*fd < 0)
        return (EXIT_FAILURE);

    if (init_map(main->map) == EXIT_FAILURE)
    {
        close(*fd);
        return (EXIT_FAILURE);
    }

    // Skip lines until the map starts
    while ((line = get_next_line(*fd)) != NULL)
    {  
        if (ft_find_in_str(line, "1 0SNWE\n") || *line == '\n')
        {
            free(line);
            break;
        }
        free(line);
    }
    // Skip empty lines before the map
    while ((line = get_next_line(*fd)) != NULL)
    {
        
        if (!ft_find_in_str(line, " \n"))
            break;
        free(line);
        line = NULL; // Set line to NULL after freeing
    }
    
    // Fill the map
    i = 0;
    while (i < main->map->map_max_y && line != NULL)
    {
        if (!ft_find_in_str(line, "10NSWE\n "))
        {
            free(line);
            line = NULL; // Set line to NULL after freeing
            break;
        }

        int j = 0;
        while (line[j] && line[j] != '\n')
        {
            main->map->map[i + 1][j + 1] = line[j];
            j++;
        }
        free(line);
        line = NULL; // Set line to NULL after freeing
        line = get_next_line(*fd);
        i++;
    }

    // Free the last line if it exists
    free(line);

    close(*fd);
    return (EXIT_SUCCESS);
}