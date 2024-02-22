/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:07:23 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 11:17:37 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_iter_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a->prev)
	{
		if (is_greater_than(tmp_a, 1) && is_smaller_than(tmp_a, 1))
			tmp_a = tmp_a->prev;
		else
		{
			order(&tmp_a, &tmp_b, 1);
			tmp_a = get_tail(tmp_a);
		}
	}
	*a = get_tail(tmp_a);
	*b = get_head(tmp_b);
}

static void	small_iter_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_b)
	{
		order(&tmp_a, &tmp_b, 0);
		tmp_b = get_head(tmp_b);
		tmp_a = get_tail(tmp_a);
	}
	*a = get_tail(tmp_a);
	*b = get_head(tmp_b);
}

void	small_quicksort(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;

	a = get_tail(*stack_a);
	b = NULL;
	small_iter_a(&a, &b);
	small_iter_b(&a, &b);
	if (b)
		clean_stack(b);
	*stack_a = a;
}
