/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:58:04 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/10 17:19:08 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	test_parsing(t_stack *stack, char *name)
{
	t_stack	*temp;

	temp = stack;
	ft_printf("---- Stack %s ----\n", name);
	if (is_sorted(stack))
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
}

int	main(int argc, char **argv)
{
	char	*arg_string;
	char	**numbers_array;
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	arg_string = join_args(argc, argv);
	if (!arg_string)
		return (0);
	numbers_array = ft_split(arg_string, ' ');
	free(arg_string);
	if (!numbers_array)
		return (0);
	if (!load_stack_a(&stack_a, numbers_array) || verific_duplicates(stack_a))
	{
		ft_printf("Error\n");
		free_split(numbers_array);
		stack_clear(&stack_a);
		return (1);
	}
	test_parsing(stack_a, "A");
	free_split(numbers_array);
	stack_clear(&stack_a);
	return (0);
}


