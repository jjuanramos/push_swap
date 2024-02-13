/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:05:05 by juramos           #+#    #+#             */
/*   Updated: 2024/02/13 12:37:30 by juramos          ###   ########.fr       */
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

static void	check_three(t_stack *stack_a)
{
	t_stack	*a;

	a = get_head(stack_a);
	if (a->value > (a->next)->value && a->value < (get_tail(a))->value)
		sa(stack_a);
	else if (a->value < (a->next)->value
		&& (a->next)->value > (get_tail(a))->value)
		rra(stack_a);
	else
		ra(stack_a);
}

static int	how_many_smaller(t_stack *stck)
{
	int		n;
	t_stack	*t;

	t = get_head(stck);
	n = 0;
	while (t)
	{
		if (t->value < stck->value)
			n++;
		t = t->next;
	}
	return (n);
}

t_stack	*check_a(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_size;
	t_stack	*head_a;

	head_a = get_head(stack_a);
	stack_size = get_stack_size(head_a);
	if (stack_size <= 3)
		check_three(stack_a);
	else if (head_a == stack_a->prev
		&& head_a->value > stack_a->value)
		sa(stack_a);
	else if (head_a->value < stack_a->value)
		stack_b = pb(head_a, stack_b);
	else if (head_a->value > stack_a->value)
	{
		if (how_many_smaller(stack_a) < stack_size / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	return (stack_b);
}

t_stack	*order(t_stack *stack_a, t_stack *stack_b, int is_a)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		max_b;

	head_a = get_head(stack_a);
	head_b = get_head(stack_b);
	if (is_a)
		stack_b = check_a(stack_a, stack_b);
	else
	{
		max_b = get_max_val_from_stack(stack_b);
		if (head_a->value < max_b)
			stack_b = pb(head_a, stack_b);
		else if (head_b->value == max_b)
			stack_b = pa(head_b, stack_a);
		else if ((head_b->next)->value == max_b)
			sb(stack_b);
		else
			rrb(stack_b);
	}
	return (stack_b);
}
