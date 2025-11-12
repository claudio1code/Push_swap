/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:26:42 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/12 14:05:07 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
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



