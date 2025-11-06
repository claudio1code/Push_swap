/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:26:32 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/06 16:47:25 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_ints(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		while (arg[i] && arg[i] == 32)
			i++;
		if (arg[i] == '+' || arg[i] == '-')
		{
			if (!arg[i + 1] || (i > 0 && arg[i - 1] != 32)
				|| !ft_isdigit(arg[i + 1]))
				return (0);
		}
		else if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_input(char **argv)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (valid_ints(argv[j]))
		{
			ft_split(argv[j], 32);
			return (1);
		}
		j++;
	}
	return (0);
}
