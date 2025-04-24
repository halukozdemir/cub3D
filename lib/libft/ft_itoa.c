/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:55:26 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:55:28 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long num)
{
	int	digits;

	digits = 1;
	if (num < 0)
	{
		num *= -1;
	}
	while (num > 9)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		digits;
	long	num;
	int		sign;

	num = n;
	sign = 0;
	digits = count_digits(num);
	if (num < 0 && ++digits)
	{
		num *= -1;
		sign = -1;
	}
	number = (char *) malloc (sizeof(char) * digits + 1);
	if (!number)
		return (NULL);
	number[digits] = 0;
	while (digits)
	{
		number[digits-- - 1] = (num % 10) + 48;
		num /= 10;
	}
	if (sign == -1)
		number[0] = '-';
	return (number);
}
