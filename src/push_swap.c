/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:25:37 by juramos           #+#    #+#             */
/*   Updated: 2024/02/29 12:46:39 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a)
{
	int		a_size;
	int		chunks;

	a_size = get_stack_size(get_head(stack_a));
	if (a_size > 250)
		chunks = 12;
	else if (a_size > 50)
		chunks = 6;
	else
		chunks = 1;
	if (chunks > 1)
		chunk_quicksort(&stack_a, chunks);
	else
		small_quicksort(&stack_a);
}
