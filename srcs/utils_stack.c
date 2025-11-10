/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:20:03 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/10 14:32:55 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_a(void *num)
{
	t_stack	*new_node;
	
	new_node = malloc(sizeof(t_list));
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
