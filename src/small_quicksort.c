/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:07:23 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 11:13:18 by juramos          ###   ########.fr       */
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

void	small_quicksort(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;

	a = get_tail(*stack_a);
	b = NULL;
	// while (a->prev)
	// {
	// 	if (is_greater_than(a, 1) && is_smaller_than(a, 1))
	// 		a = a->prev;
	// 	else
	// 	{
	// 		order(&a, &b, 1);
	// 		a = get_tail(a);
	// 	}
	// }
	// b = get_head(b);
	// a = get_tail(a);
	small_iter_a(&a, &b);
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
