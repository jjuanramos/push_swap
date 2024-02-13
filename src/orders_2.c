/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:05:05 by juramos           #+#    #+#             */
/*   Updated: 2024/02/13 14:05:26 by juramos          ###   ########.fr       */
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

static int	pos_til_left_of_max(t_stack *head)
{
	int		max;
	int		n;
	t_stack	*t;

	max = get_max_val_from_stack(head);
	t = head;
	n = 0;
	while (t->next && (t->next)->value != max)
	{
		n++;
		t = t->next;
	}
	return (n);
}

t_stack	*order(t_stack *stack_a, t_stack *stack_b, int is_a)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		max_b;

	head_a = get_head(stack_a);
	head_b = get_head(stack_b);
	if (is_a)
		stack_b = order_a(stack_a, stack_b);
	else
	{
		max_b = get_max_val_from_stack(stack_b);
		if (head_a->value < max_b)
			stack_b = pb(head_a, stack_b);
		else if (head_b->value == max_b)
			stack_b = pa(head_b, stack_a);
		else if ((head_b->next) && (head_b->next)->value == max_b)
			sb(stack_b);
		else
		{
			if (pos_til_left_of_max(head_b) < get_stack_size(head_b) / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
	return (stack_b);
}
