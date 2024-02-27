/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:33 by juramos           #+#    #+#             */
/*   Updated: 2024/02/27 13:30:45 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_mvmts(t_stack *a, t_stack *b)
{
	t_stack	*max_b;
	t_stack	*closest_min;
	t_stack	*tmp_a;
	int		mvmts;

	tmp_a = a;
	mvmts = 0;
	max_b = get_max_to_right(b);
	if (a-> value < get_min_to_right(b)->value || a->value > max_b->value)
	{
		mvmts_to_head(max_b, &mvmts);
		mvmts_to_head(tmp_a, &mvmts);
		mvmts += 1;
	}
	else
	{
		closest_min = get_closest_min(tmp_a);
		mvmts_to_head(closest_min, &mvmts);
		mvmts_to_head(tmp_a, &mvmts);
	}
	return (mvmts);

}

t_stack	*get_min_pivot(t_stack *a, t_stack *b)
{
	int		min;
	t_stack	*min_pivot;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = a;
	tmp_b = b;
	min = check_mvmts(tmp_a, tmp_b);
	min_pivot = tmp_a;
	while (tmp_a)
	{
		if (check_mvmts(tmp_a, tmp_b) < min)
		{
			min = check_mvmts(tmp_a, tmp_b);
			min_pivot = tmp_a;
		}
		tmp_a = a->next;
	}
	return (min_pivot);
}

void	turk_order(t_stack **a, t_stack **b)
{
	t_stack	*pivot_a;
	t_stack	*tmp_b;

	pivot_a = get_min_pivot(*a, *b);
	tmp_b = *b;
	exec_mvmts(pivot_a, tmp_b);
	*a = get_head(pivot_a);
	*b = get_head(tmp_b);
}

void	turk(t_stack *stack_a)
{
	t_stack	*a;
	t_stack	*b;

	a = get_head(stack_a);
	b = NULL;
	if (get_stack_size(a) <= 3)
		check_three(a);
	while (get_stack_size(a) > 3 && get_stack_size(b) < 2)
	{
		pb(&a, &b);
		a = get_head(a);
		b = get_head(b);
	}
	while (get_stack_size(a) > 3)
		turk_order(&a, &b);
	check_three(a);
	while (b)
		turk_order_reversed(&a, &b);
}
