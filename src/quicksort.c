/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:25:37 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 10:54:26 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_greater_than(t_stack *stck, int to_left)
{
	t_stack	*t;

	t = stck;
	if (to_left)
	{
		while (t->prev)
		{
			if ((t->prev)->value > stck->value)
				return (0);
			t = t->prev;
		}
	}
	else
	{
		while (t->next)
		{
			if ((t->next)->value > stck->value)
				return (0);
			t = t->next;
		}
	}
	return (1);
}

int	is_smaller_than(t_stack *stck, int to_right)
{
	t_stack	*t;

	t = stck;
	if (to_right)
	{
		while (t->next)
		{
			if ((t->next)->value < stck->value)
				return (0);
			t = t->next;
		}
	}
	else
	{
		while (t->prev)
		{
			if ((t->prev)->value < stck->value)
				return (0);
			t = t->prev;
		}
	}
	return (1);
}

static void	quicksort_small(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;

	a = get_tail(*stack_a);
	b = NULL;
	while (a->prev)
	{
		if (is_greater_than(a, 1) && is_smaller_than(a, 1))
			a = a->prev;
		else
		{
			order(&a, &b, 1);
			a = get_tail(a);
		}
	}
	b = get_head(b);
	a = get_tail(a);
	while (b)
	{
		order(&a, &b, 0);
		b = get_head(b);
		a = get_tail(a);
	}
	if (b)
		clean_stack(b);
	*stack_a = a;
}

/*
	maybe we could resort to previous behavior 
	when size < N (where N == 50, to iterate)
*/
void	quicksort(t_stack *stack_a)
{
	int		a_size;
	int		chunks;

	a_size = get_stack_size(get_head(stack_a));
	if (a_size > 250)
		chunks = 11;
	else if (a_size > 49)
		chunks = 6;
	else if (a_size > 19)
		chunks = 3;
	else
		chunks = 1;
	if (chunks > 1)
		order_chunks(&stack_a, chunks);
	else
		quicksort_small(&stack_a);
	print_stack(get_head(stack_a), "\nend result of A:\t");
}
