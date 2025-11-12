/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:58:04 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/12 16:09:05 by clados-s         ###   ########.fr       */
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
	sa(stack);
	sa(stack);
	rra(stack);
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack(argc, argv);
	if (!stack_a)
		return (1);
	if (is_sorted(stack_a))
	{
		stack_clear(&stack_a);
		return (0);
	}
	assign_index(stack_a);
	test(&stack_a, "A");
	stack_clear(&stack_a);
	return (0);
}


