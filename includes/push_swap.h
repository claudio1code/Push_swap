/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:04:26 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/11 17:26:51 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				num;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}t_stack;

int		main(int argc, char **argv);
char	*join_args(int argc, char **argv);
t_stack	*stack_new_node(int num);
void	stack_clear(t_stack **stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		load_stack_a(t_stack **stack_a, char **numbers);
int		verific_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
void	stack_add_front(t_stack **stack, t_stack *new_node);
t_stack	*stack_get_last(t_stack *stack);

#endif