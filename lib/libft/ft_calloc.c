/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:54:51 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:54:54 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	while (i < (count * size))
	{
		((char *)p)[i] = 0;
		i++;
	}
	return (p);
}
