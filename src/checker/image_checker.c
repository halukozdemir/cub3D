/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:50:21 by halozdem          #+#    #+#             */
/*   Updated: 2025/02/12 17:52:34 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

char    check_image(t_textures *textures)
{
    if ((textures->no[ft_strlen(textures->no) - 1] != 'm' ||
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
    }
}
