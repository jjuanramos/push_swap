/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:05:05 by juramos           #+#    #+#             */
/*   Updated: 2024/02/12 12:11:57 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* quicksort
	1. conquering:
		- in Stack A:
			- if pivot - n < pivot -> pb
			- if pivot - n > pivot
				-> if len - pos <= 3
					-> check if sa (0 > 1 && 0 < 2) // check stack B for ss
					-> check if sa && ra (0 < 1 && 2 < 1) // check stack B for ss & rr
				-> ra
		- in Stack B:
			- if pivot is max -> pa
			- if last is max -> rrb
			- if 0 < 1 -> sb // check stack A for ss
			- else -> rrb
	2.
		- else if last pivot pos == len of stack B - 1 -> pa
		- else if last pivot pos != len - 1 && stack B -> pivot + 1 and repeat
*/
t_stack	*order(t_stack *stack_a, t_stack *stack_b, int is_a)
{
	t_stack	*a;
	t_stack	*b;

	a = get_head(stack_a);
	if (is_a)
	{
		if (get_stack_size(a) <= 3)
			b = check_three(stack_a, stack_b); // here we might want to check sb
		else if (a->value < stack_a->value)
			b = pb(a, stack_b);
		else if (a->value > stack_a->value)
			ra(stack_a);
	}
	else
	{
		if (is_greater_than(stack_b, 0))
			pa(stack_b, stack_a);
		else if (is_greater_than(get_tail(stack_b), 1))
			rrb(stack_b);
		else if (get_head(stack_b)->value < (get_head(stack_b)->next)->value)
			sb(stack_b);
		else
			rrb(stack_b);
	}
	return (b);
}
