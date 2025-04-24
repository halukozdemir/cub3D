/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:58:18 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:58:20 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *) s1;
	ptr2 = (const unsigned char *) s2;
	if (!n)
		return (0);
	while ((n - 1) && *ptr1 && *ptr2)
	{
		if (*ptr1 > *ptr2)
			return (*ptr1 - *ptr2);
		if (*ptr1 < *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	return (*ptr1 - *ptr2);
}
