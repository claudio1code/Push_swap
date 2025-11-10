/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:20:03 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/10 17:14:02 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new_node(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->pos = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

static t_stack	*stack_get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = stack_get_last(*stack);
	last_node->next = new_node;
	new_node->prev = last_node;
}

int	is_sorted(t_stack *stack)
{
	t_stack	*current;
	
	if (!stack)
		return (0);
	current = stack;
	while (current && current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}
