/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:58:04 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/13 16:21:00 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	test(t_stack **stack, char *name)
{
	t_stack	*temp;

	temp = *stack;
	ft_printf("---- Stack %s ----\n", name);
	if (is_sorted(*stack))
		ft_printf("---- Ordenada ----\n");
	if (!temp)
	{
		ft_printf("(vazia)\n");
		return ;
	}
	while (temp)
	{
		ft_printf("%d\n", temp->num);
		temp = temp->next;
	}
	ft_printf("--------------------\n");
	temp = *stack;
	ft_printf("---- Stack %s ----\n", name);
		while (temp)
	{
		ft_printf("num: %d (pos:%d)\n", temp->num, temp->pos);
		temp = temp->next;
	}
	ft_printf("--------------------\n");
	
}

t_stack	*init_stack(int argc, char **argv)
{
	char	*arg_str;
	char	**nbrs_array;
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (NULL);
	arg_str = join_args(argc, argv);
	if (!arg_str)
		return (NULL);
	nbrs_array = ft_split(arg_str, ' ');
	free(arg_str);
	if (!nbrs_array)
		return (NULL);
	if (!load_stack_a(&stack_a, nbrs_array) || verific_duplicates(stack_a))
	{
		ft_printf("Error\n");
		free_split(nbrs_array);
		stack_clear(&stack_a);
		return (NULL);
	}
	free_split(nbrs_array);
	return (stack_a);
}

static void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	size = get_stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	assign_index(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, &stack_b);
	else if (size == 5)
		sort_five(stack_a, &stack_b);
	
	
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack(argc, argv);
	if (!stack_a)
		return (1);
	push_swap(&stack_a);
	test(&stack_a, "A");
	stack_clear(&stack_a);
	return (0);
}


