/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:51:48 by juramos           #+#    #+#             */
/*   Updated: 2024/03/04 10:17:14 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_three(t_stack *stack_a)
{
	t_stack	*a;

	a = get_head(stack_a);
	if (a->value > (a->next)->value && a->value < (get_tail(a))->value)
	{
		sa(stack_a);
		ft_printf("sa\n");
	}
	else if (a->value < (a->next)->value
		&& (a->next)->value > (get_tail(a))->value)
	{
		rra(stack_a);
		ft_printf("rra\n");
	}
	else
	{
		ra(stack_a);
		ft_printf("ra\n");
	}
}

t_stack	*get_min_to_right(t_stack *stck)
{
	t_stack	*min;
	t_stack	*t;

	t = stck;
	min = t;
	while (t->next)
	{
		t = t->next;
		if (t->value < min->value)
			min = t;
	}
	return (min);
}

t_stack	*get_max_to_right(t_stack *stck)
{
	t_stack	*max;
	t_stack	*t;

	t = stck;
	max = t;
	while (t->next)
	{
		t = t->next;
		if (t->value > max->value)
			max = t;
	}
	return (max);
}
