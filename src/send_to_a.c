/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:28:12 by juramos           #+#    #+#             */
/*   Updated: 2024/03/04 13:39:35 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*check_mvmts_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*pivot;
	t_stack	*a_closest_greater;
	int		*b_mvmts;
	int		*a_mvmts;
	int		*min_mvmts;

	pivot = stack_b;
	a_closest_greater = get_closest_greater(pivot, stack_a);
	if (!a_closest_greater)
		a_mvmts = simulate_mvmts_a(get_min_to_right(get_head(stack_a)));
	else
		a_mvmts = simulate_mvmts_a(a_closest_greater);
	b_mvmts = simulate_mvmts_b(pivot);
	min_mvmts = concat_mvmts(b_mvmts, a_mvmts, 1);
	return (free(a_mvmts), free(b_mvmts), min_mvmts);
}

void	send_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	int		*mvmts;
	int		*pivot_mvmts;

	a = get_head(*stack_a);
	b = *stack_b;
	pivot_mvmts = check_mvmts_to_a(a, b);
	while (b)
	{
		if (get_int_arr_len(pivot_mvmts) <= 2)
			break ;
		mvmts = check_mvmts_to_a(a, b);
		if (get_int_arr_len(mvmts) < get_int_arr_len(pivot_mvmts))
			pivot_mvmts = mvmts;
		if (!b->next)
			break ;
		b = b->next;
	}
	exec_mvmts(&a, &b, pivot_mvmts);
	free(pivot_mvmts);
	*stack_a = get_head(a);
	*stack_b = get_head(b);
}
