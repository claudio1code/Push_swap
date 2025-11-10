/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:26:32 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/10 16:17:22 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_format(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[0])
		return (0);
	if (arg[i] == '+' || arg[i] == '-')
	{
		i++;
		if (!arg[i])
			return (0);
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
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
		temp = ft_strjoin(full_str, " ");
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

int	load_stack_a(t_stack **stack_a, char **numbers)
{
	int		i;
	long	num_long;
	t_stack	*new_node;

	i = 0;
	while (numbers[i])
	{
		if (!is_valid_format(numbers[i]))
			return (0);
		if (!ft_isint(numbers[i]))
			return (0);
		num_long = ft_almost_atol(numbers[i]);
		new_node = stack_new_node(num_long);
		if (!new_node)
			return (0);
		stack_add_back(stack_a, new_node);
		i++;
	}
	return (1);
}

int	verific_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->num == checker->num)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
