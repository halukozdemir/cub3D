/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:10:26 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 15:10:29 by beyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return (((char *) haystack));
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[j + i] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == 0)
				return (&((char *) haystack)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
