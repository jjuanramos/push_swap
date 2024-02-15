/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:51:48 by juramos           #+#    #+#             */
/*   Updated: 2024/02/15 10:56:13 by juramos          ###   ########.fr       */
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

static int	get_min_to_right(t_stack *stck)
{
	int		min;
	t_stack	*t;

	t = stck;
	min = t->value;
	while (t->next)
	{
		t = t->next;
		if (t->value < min)
			min = t->value;
	}
	return (min);
}

t_stack	*order_a(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_size;
	t_stack	*head_a;

	head_a = get_head(stack_a);
	stack_size = get_stack_size(head_a);
	if (stack_size <= 3 && (stack_b && get_min_to_right(head_a)
			> get_max_to_right(get_head(stack_b))))
		check_three(stack_a);
	else if (head_a->next && (head_a->next)->value == get_min_to_right(head_a)
		&& stack_b
		&& (head_a->next)->value > get_max_to_right(get_head(stack_b)))
		sa(stack_a);
	else if (head_a->value < stack_a->value)
		stack_b = pb(head_a, stack_b);
	else if ((how_many_smaller(head_a) < how_many_greater(head_a)
			&& get_max_to_right(head_a) != get_tail(head_a)->value)
		|| (get_tail(stack_a)->value == get_min_to_right(head_a)
			&& how_many_smaller(stack_a) < how_many_greater(stack_a)))
		rra(stack_a);
	else if (how_many_smaller(head_a) < how_many_greater(head_a))
		stack_b = pb(stack_a, stack_b);
	else
		ra(stack_a);
	return (stack_b);
}
