/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:02 by juramos           #+#    #+#             */
/*   Updated: 2024/03/08 10:11:40 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_rr(t_stack *a, t_stack *b, int mvmt)
{
	if (mvmt == RRB)
	{
		rrb(b);
		ft_printf("rrb\n");
	}
	else if (mvmt == RRA)
	{
		rra(a);
		ft_printf("rra\n");
	}
	else if (mvmt == RRR)
	{
		rra(a);
		rrb(b);
		ft_printf("rrr\n");
	}
}

static void	check_r(t_stack *a, t_stack *b, int mvmt)
{
	if (mvmt == RB)
	{
		rb(b);
		ft_printf("rb\n");
	}
	else if (mvmt == RA)
	{
		ra(a);
		ft_printf("ra\n");
	}
	else if (mvmt == RR)
	{
		ra(a);
		rb(b);
		ft_printf("rr\n");
	}
}

static void	check_p(t_stack **a, t_stack **b, int mvmt)
{
	if (mvmt == PA)
	{
		pa(b, a);
		ft_printf("pa\n");
	}
	else if (mvmt == PB)
	{
		pb(a, b);
		ft_printf("pb\n");
	}
}

void	exec_mvmts(t_stack **a, t_stack **b, int *pivot_mvmts)
{
	int		pos;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	pos = 0;
	tmp_a = get_head(*a);
	tmp_b = get_head(*b);
	while (pivot_mvmts[pos])
	{
		if (pivot_mvmts[pos] == PA || pivot_mvmts[pos] == PB)
			check_p(&tmp_a, &tmp_b, pivot_mvmts[pos]);
		else if (pivot_mvmts[pos] == RA || pivot_mvmts[pos] == RB
			|| pivot_mvmts[pos] == RR)
			check_r(tmp_a, tmp_b, pivot_mvmts[pos]);
		else if (pivot_mvmts[pos] == RRA || pivot_mvmts[pos] == RRB
			|| pivot_mvmts[pos] == RRR)
			check_rr(tmp_a, tmp_b, pivot_mvmts[pos]);
		pos++;
	}
	*a = get_head(tmp_a);
	*b = get_head(tmp_b);
}
