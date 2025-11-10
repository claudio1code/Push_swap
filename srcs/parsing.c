/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:26:32 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/10 14:06:41 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_ints(char *arg)
{
	int	i;

	i = 0;
	if (!ft_isint(arg))
		return (0);
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

char	*join_args(int argc, char **argv)
{
	char	*full_str;
	char	*temp;
	int		i;

	i = 2;
	full_str = ft_strdup(argv[1]);
	while (i < argc)
	{
		temp = ft_strjoin(full_str, 32);
		free(full_str);
		if (!temp)
			return (NULL);
		full_str = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!full_str)
			return (NULL);
		i++;
	}
	return (full_str);
}

int	validate_arrays(char **nbrs)
{
	int	i;

	i = 0;
	if (!nbrs[0])
		return (0);
	while (nbrs[i])
	{
		if (!valid_ints(nbrs[i]))
			return (0);
		i++;
	}
////////////

	return (1);
}

