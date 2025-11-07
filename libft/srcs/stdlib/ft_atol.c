/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:55:08 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/07 16:33:18 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verific_overflow(unsigned long number, int sign, int digit)
{
	unsigned long	cutoff;

	cutoff = LONG_MAX / 10;
	if (sign == 1)
	{
		if (number > cutoff || (number == cutoff && digit > 7))
			return (1);
	}
	else
	{
		if (number > cutoff || (number == cutoff && digit > 8))
			return (1);
	}
	return (0);
}

long	ft_atol(char *nptr)
{
	int				i;
	unsigned long	number;
	int				sign;
	int				digit;

	i = 0;
	sign = ft_signal(nptr);
	number = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		if (ft_check_overflow(number, digit, sign))
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MAX * -1 - 1);
		}
		number = number * 10 + digit;
		i++;
	}
	return ((long)number * sign);
}
