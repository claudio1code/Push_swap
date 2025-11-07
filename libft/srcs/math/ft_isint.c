/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:05:46 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/07 14:13:09 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *nptr)
{
	long long	number;

	if (!nptr || !*nptr)
		return (0);
	number = ft_atol(nptr);
	if (number <= 2147483647 && number >= -2147483648)
		return (1);
	return (0);
}

