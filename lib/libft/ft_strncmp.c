/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildiz <beyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:10:22 by beyildiz          #+#    #+#             */
/*   Updated: 2025/04/25 15:10:24 by beyildiz         ###   ########.fr       */
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
