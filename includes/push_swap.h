/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:04:26 by clados-s          #+#    #+#             */
/*   Updated: 2025/11/06 16:40:48 by clados-s         ###   ########.fr       */
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

int	valid_input(char **argv);
int	main(int argc, char **argv);

#endif