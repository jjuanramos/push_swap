/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:28:12 by juramos           #+#    #+#             */
/*   Updated: 2024/03/05 13:28:54 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*check_mvmts_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*pivot;
	t_stack	*b_closest_min;
	int		*b_mvmts;
	int		*a_mvmts;
	int		*min_mvmts;

	pivot = stack_a;
	b_closest_min = get_closest_min(pivot, stack_b);
	if (!b_closest_min)
		b_mvmts = simulate_mvmts_b(get_max_to_right(get_head(stack_b)));
	else
		b_mvmts = simulate_mvmts_b(b_closest_min);
	a_mvmts = simulate_mvmts_a(pivot);
	min_mvmts = concat_mvmts(b_mvmts, a_mvmts, 0);
	return (free(a_mvmts), free(b_mvmts), min_mvmts);
}

static void	search_opt_a(t_stack *a, t_stack *b, int **pivot, int iters)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		*tmp_mvmts;
	int		pos;

	tmp_a = a;
	tmp_b = b;
	pos = -1;
	while (tmp_a && pos++ < iters)
	{
		if (get_int_arr_len(*pivot) <= 2)
			break ;
		tmp_mvmts = check_mvmts_to_b(tmp_a, tmp_b);
		if (get_int_arr_len(tmp_mvmts) < get_int_arr_len(*pivot))
			update_pivot(pivot, &tmp_mvmts);
		else
			free(tmp_mvmts);
		if (!(a->next))
			break ;
		tmp_a = tmp_a->next;
	}
}

static void	search_rev_a(t_stack *a, t_stack *b, int **pivot, int iters)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		*tmp_mvmts;
	int		pos;

	tmp_a = get_tail(a);
	tmp_b = b;
	pos = -1;
	while (tmp_a && pos++ < iters)
	{
		if (get_int_arr_len(*pivot) <= 2)
			break ;
		tmp_mvmts = check_mvmts_to_b(tmp_a, tmp_b);
		if (get_int_arr_len(tmp_mvmts) < get_int_arr_len(*pivot))
			update_pivot(pivot, &tmp_mvmts);
		else
			free(tmp_mvmts);
		if (!(tmp_a->prev))
			break ;
		tmp_a = tmp_a->prev;
	}
}

void	send_to_b(t_stack **stack_a, t_stack **stack_b, int iters)
{
	t_stack	*a;
	t_stack	*b;
	int		*pivot_mvmts;

	a = *stack_a;
	b = *stack_b;
	pivot_mvmts = check_mvmts_to_b(a, b);
	search_opt_a(a, b, &pivot_mvmts, iters);
	search_rev_a(a, b, &pivot_mvmts, iters);
	exec_mvmts(&a, &b, pivot_mvmts);
	free(pivot_mvmts);
	*stack_a = get_head(a);
	*stack_b = get_head(b);
}
