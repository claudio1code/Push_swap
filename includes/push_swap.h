/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:04:26 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/13 20:31:44 by clados-s         ###   ########.fr       */
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
void	assign_index(t_stack *stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
t_stack	*init_stack(int argc, char **argv);
void	sort_three(t_stack **stack_a);
int		size_stack(t_stack *stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_radix(t_stack **stack_a, t_stack **stack_b);

#endif