/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:06:44 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/10 10:41:40 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	number;
	int		sign;

	i = 0;
	sign = 1;
	number = ft_atol(nptr);
	if (number >= INT_MAX)
		return (INT_MAX);
	else if (number <= INT_MIN)
		return (INT_MIN);
	return (number);
}
