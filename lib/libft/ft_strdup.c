/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:57:35 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:57:37 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	p = (char *)malloc(sizeof(char) * len);
	if (!p)
		return (NULL);
	while (len)
	{
		p[i] = s1[i];
		i++;
		len--;
	}
	return (p);
}
