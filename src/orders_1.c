/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:51:48 by juramos           #+#    #+#             */
/*   Updated: 2024/02/13 17:50:49 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	how_many_greater(t_stack *stck)
{
	int		n;
	t_stack	*t;

	t = get_head(stck);
	n = 0;
	while (t)
	{
		if (t->value > stck->value)
			n++;
		t = t->next;
	}
	return (n);
}

t_stack	*order_a(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_size;
	t_stack	*head_a;

	head_a = get_head(stack_a);
	stack_size = get_stack_size(head_a);
	if (stack_size <= 3)
		check_three(stack_a);
	else if (head_a->value < stack_a->value)
		stack_b = pb(head_a, stack_b);
	else if (head_a->value > stack_a->value)
	{
		if (how_many_smaller(head_a) < how_many_greater(head_a)
			&& get_max_to_right(head_a) != get_tail(head_a)->value)
			rra(stack_a);
		else if (how_many_smaller(head_a) < how_many_greater(head_a))
			stack_b = pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	return (stack_b);
}
