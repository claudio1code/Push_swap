/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:04:11 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/11 17:19:34 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*node_to_push;
	
	if (!stack_src || !*stack_src)
		return ;
	node_to_push = *stack_src;
	*stack_src =(*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	stack_add_front(stack_dest, node_to_push);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
