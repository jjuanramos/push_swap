/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:05:05 by juramos           #+#    #+#             */
/*   Updated: 2024/02/12 13:53:15 by juramos          ###   ########.fr       */
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

/*
	-> check if sa (0 > 1 && 0 < 2) // check stack B for ss
	-> check if sa && ra (0 < 1 && 2 < 1) // check stack B for ss & rr(?)
*/

#include "push_swap.h"

static void	check_three(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*a;

	a = get_head(stack_a);
	if (a->value > (a->next)->value && a->value < (get_tail(a))->value)
	{
		if (stack_b && get_head(stack_b) && get_head(stack_b)->next
			&& get_head(stack_b)->value < (get_head(stack_b)->next)->value)
			ss(stack_a, stack_b);
		else
			sa(stack_a);
	}
	else if (a->value < (a->next)->value
		&& (a->next)->value > (get_tail(a))->value)
	{
		if (stack_b && get_head(stack_b) && get_head(stack_b)->next
			&& get_head(stack_b)->value < (get_head(stack_b)->next)->value)
			ss(stack_a, stack_b);
		else
			sa(stack_a);
		ra(stack_a);
	}
}

t_stack	*order(t_stack *stack_a, t_stack *stack_b, int is_a)
{
	t_stack	*b;

	b = NULL;
	if (is_a)
	{
		if (get_stack_size(get_head(stack_a)) <= 3)
			check_three(stack_a, stack_b);
		else if (get_head(stack_a)->value < stack_a->value)
			b = pb(get_head(stack_a), stack_b);
		else if (get_head(stack_a)->value > stack_a->value)
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
