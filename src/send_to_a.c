/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:28:12 by juramos           #+#    #+#             */
/*   Updated: 2024/03/05 13:28:33 by juramos          ###   ########.fr       */
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

static void	search_opt_b(t_stack *a, t_stack *b, int **pivot, int iters)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		*tmp_mvmts;
	int		pos;

	tmp_a = a;
	tmp_b = b;
	pos = -1;
	while (tmp_b && pos++ < iters)
	{
		if (get_int_arr_len(*pivot) <= 2)
			break ;
		tmp_mvmts = check_mvmts_to_a(tmp_a, tmp_b);
		if (get_int_arr_len(tmp_mvmts) < get_int_arr_len(*pivot))
			update_pivot(pivot, &tmp_mvmts);
		else
			free(tmp_mvmts);
		if (!(b->next))
			break ;
		tmp_b = tmp_b->next;
	}
}

static void	search_rev_b(t_stack *a, t_stack *b, int **pivot, int iters)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		*tmp_mvmts;
	int		pos;

	tmp_a = a;
	tmp_b = get_tail(b);
	pos = -1;
	while (tmp_b && pos++ < iters)
	{
		if (get_int_arr_len(*pivot) <= 2)
			break ;
		tmp_mvmts = check_mvmts_to_a(tmp_a, tmp_b);
		if (get_int_arr_len(tmp_mvmts) < get_int_arr_len(*pivot))
			update_pivot(pivot, &tmp_mvmts);
		else
			free(tmp_mvmts);
		if (!(tmp_b->prev))
			break ;
		tmp_b = tmp_b->prev;
	}
}

void	send_to_a(t_stack **stack_a, t_stack **stack_b, int iters)
{
	t_stack	*a;
	t_stack	*b;
	int		*pivot_mvmts;

	a = *stack_a;
	b = *stack_b;
	pivot_mvmts = check_mvmts_to_a(a, b);
	search_opt_b(a, b, &pivot_mvmts, iters);
	search_rev_b(a, b, &pivot_mvmts, iters);
	exec_mvmts(&a, &b, pivot_mvmts);
	free(pivot_mvmts);
	*stack_a = get_head(a);
	*stack_b = get_head(b);
}