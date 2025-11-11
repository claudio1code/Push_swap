/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:26:42 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/11 14:39:26 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assingn_index(t_stack *stack)
{
	t_stack	*actual;
	t_stack	*checker;
	int		pos;

	actual = stack;
	while (actual)
	{
		pos = 0;
		checker = stack;
		while (checker)
		{
			if (actual->num > checker->num)
				pos++;
			checker = checker->next;
		}
		actual->pos = pos;
		actual = actual->next;
	}
}

void	stack_add_front(t_stack **stack, t_stack *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

