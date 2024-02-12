/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walkthrough.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:30:44 by juramos           #+#    #+#             */
/*   Updated: 2024/02/12 12:03:38 by juramos          ###   ########.fr       */
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
			if ((t->prev)->value > t->value)
				return (0);
			t = t->prev;
		}
	}
	else
	{
		while (t->next)
		{
			if ((t->next)->value > t->value)
				return (0);
			t = t->next;
		}
	}
	return (1);
}

static int	is_smaller_than(t_stack *stck, int to_right)
{
	t_stack	*t;

	t = stck;
	if (to_right)
	{
		while (t->next)
		{
			if ((t->next)->value > t->value)
				return (0);
			t = t->next;
		}
	}
	else
	{
		while (t->prev)
		{
			if ((t->prev)->value > t->value)
				return (0);
			t = t->prev;
		}
	}
	return (1);
}

void	walkthrough(t_stack *stack_a)
{
	t_stack	*a;
	t_stack	*b;

	a = get_tail(stack_a);
	b = NULL;
	while (a->prev)
	{
		if (is_greater_than(stack_a, 1) && is_smaller_than(stack_a, 1))
			a = a->prev;
		else
		{
			b = order(a, b, 1);
			a = get_tail(a);
		}
	}
	while (b)
	{
		b = get_head(b);
		order(a, b, 0);
	}
}
