/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:04:26 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/10 14:42:28 by clados-s         ###   ########.fr       */
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

int		valid_input(char **argv);
int		main(int argc, char **argv);
char	*join_args(int argc, char **argv);
int		validate_arrays(char **nbrs);
t_stack *stack_a(void *num);
void	stack_clear(t_stack **stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);


#endif