/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:41 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/13 16:18:12 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_node_distance(t_stack *stack, int pos_to_find)
{
	int	distance;

	distance = 1;
	while (stack)
	{
		if (stack->pos == pos_to_find)
			return (distance);
		stack = stack->next;
		distance++;
	}
	return (0);
}

void	sort_three(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack_a)->pos;
	mid = (*stack_a)->next->pos;
	bot = (*stack_a)->next->next->pos;
	if (top > mid && mid < bot && top < bot)
		sa(stack_a);
	else if (top > mid && mid < bot && top > bot)
		ra(stack_a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stack_a);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_node_distance(*stack_a, 0);
	if (distance == 2)
		sa(stack_a);
	else if (distance == 3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (!is_sorted(*stack_a))
		pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	bring_to_top(t_stack **stack_a, int pos_find, int size)
{
	int	distance;

	distance = get_node_distance(*stack_a, pos_find);
	if (distance - 1 <= size / 2)
	{
		distance--;
		while (distance > 0)
		{
			ra(stack_a);
			distance--;
		}
	}
	else
	{
		distance = size - distance + 1;
		while (distance > 0)
		{
			rra(stack_a);
			distance--;
		}
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	bring_to_top(stack_a, 0, 5);
	pb(stack_a, stack_b);
	bring_to_top(stack_a, 1, 4);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	if ((*stack_b)->pos == 0)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
