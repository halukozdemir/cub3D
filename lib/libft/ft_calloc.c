/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:06:55 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 15:06:58 by beyildiz         ###   ########.fr       */
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
