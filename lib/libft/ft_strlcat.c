/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:57:53 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:57:55 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	g;
	size_t	d_len;

	i = 0;
	g = 0;
	d_len = 0;
	while (*dst)
	{
		dst++;
		d_len++;
	}
	while (src[i])
		i++;
	if (dstsize == 0 || dstsize <= d_len)
		return (i + dstsize);
	while (src[g] && (g < dstsize - d_len - 1))
	{
		dst[g] = src[g];
		g++;
	}
	dst[g] = '\0';
	return (d_len + i);
}
