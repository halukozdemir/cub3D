/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:50:21 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/11 15:07:57 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

char    check_image(t_textures *textures)
{
    if (!textures->no || !textures->so || !textures->we || !textures->ea || !textures->c || !textures->f)
    {
        printf("Invalid Map.\n");
        return (EXIT_FAILURE);
    }
    else if ((textures->no[ft_strlen(textures->no) - 1] != 'm' ||
         textures->no[ft_strlen(textures->no) - 2] != 'p' ||
         textures->no[ft_strlen(textures->no) - 3] != 'x' ||
         textures->no[ft_strlen(textures->no) - 4] != '.' ||
         textures->so[ft_strlen(textures->so) - 1] != 'm' ||
         textures->so[ft_strlen(textures->so) - 2] != 'p' ||
         textures->so[ft_strlen(textures->so) - 3] != 'x' ||
         textures->so[ft_strlen(textures->so) - 4] != '.' ||
         textures->ea[ft_strlen(textures->ea) - 1] != 'm' ||
         textures->ea[ft_strlen(textures->ea) - 2] != 'p' ||
         textures->ea[ft_strlen(textures->ea) - 3] != 'x' ||
         textures->ea[ft_strlen(textures->ea) - 4] != '.' ||
         textures->we[ft_strlen(textures->we) - 1] != 'm' ||
         textures->we[ft_strlen(textures->we) - 2] != 'p' ||
         textures->we[ft_strlen(textures->we) - 3] != 'x' ||
         textures->we[ft_strlen(textures->we) - 4] != '.'))
    {
        printf("Hatalı xpm dosyası girildi.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static char check_texture_file(char *filename)
{
    int fd;
    char buffer[1];
    ssize_t bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Texture dosyası açılamadı");
        return EXIT_FAILURE;
    }
    bytes_read = read(fd, buffer, 1);
    close(fd);
    if (bytes_read <= 0)
    {
        printf("HATA: Texture dosyası boş: \"%s\"\n", filename);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

char is_any_texture_file_empty(t_textures *tex)
{
    if (check_texture_file(tex->no) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (check_texture_file(tex->so) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (check_texture_file(tex->we) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (check_texture_file(tex->ea) == EXIT_FAILURE)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

char    check_color(t_textures *textures)
{
    int     temp_d;
    char    *temp_s;
    int     i;

    i = 0;
    while (textures->c[i])
    {
        temp_d = ft_atoi(textures->c[i]);
        temp_s = ft_itoa(temp_d);
        if (ft_strncmp(textures->c[i], temp_s, ft_strlen(temp_s)) || (temp_d < 0 || temp_d >= 255))
        {
            printf("Invalid Map.\n");
            free(temp_s);
            return (EXIT_FAILURE);
        }
        free(temp_s);
        i++;
    }
    i = 0;
    while (textures->f[i])
    {
        temp_d = ft_atoi(textures->f[i]);
        temp_s = ft_itoa(temp_d);
        if (ft_strncmp(textures->f[i], temp_s, ft_strlen(temp_s)) || (temp_d < 0 || temp_d >= 255))
        {
            printf("Invalid Map.\n");
            free(temp_s);
            return (EXIT_FAILURE);
        }
        free(temp_s);
        i++;
    }
    return (EXIT_SUCCESS);
}