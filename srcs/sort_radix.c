/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hadix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:37:04 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/13 20:31:36 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack_a)
{
	int	max_pos;
	int	max_bits;

	max_pos = size_stack(stack_a) - 1;
	max_bits = 0;
	while ((max_pos >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	j = 0;
	size = size_stack(*stack_a);
	max_bits = get_max_bits(*stack_a);
	while (j < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->pos >> j) & 1))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		while (size_stack(*stack_b) > 0)
			pa(stack_a, stack_b);
		j++;
	}
}
