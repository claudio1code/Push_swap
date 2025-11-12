/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:41 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/12 16:58:29 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
