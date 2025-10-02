/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:09:11 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 15:09:14 by beyildiz         ###   ########.fr       */
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
