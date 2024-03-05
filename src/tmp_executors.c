/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_executors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:02 by juramos           #+#    #+#             */
/*   Updated: 2024/03/05 10:41:49 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_top(t_stack *stck)
{
	t_stack	*tmp;

	tmp = get_head(stck);
	while (stck->value != get_head(tmp)->value)
	{
		if (pos_til_head(tmp, stck->value) < get_stack_size(get_head(tmp)) / 2)
		{
			ra(tmp);
			ft_printf("ra\n");
		}
		else
		{
			rra(tmp);
			ft_printf("rra\n");
		}
	}
}

static void	move_b_to_top(t_stack *stck)
{
	t_stack	*tmp;

	tmp = get_head(stck);
	while (stck->value != get_head(tmp)->value)
	{
		if (pos_til_head(tmp, stck->value) < get_stack_size(get_head(tmp)) / 2)
		{
			rb(tmp);
			ft_printf("rb\n");
		}
		else
		{
			rrb(tmp);
			ft_printf("rrb\n");
		}
	}
}

void	tmp_exec_mvmts(t_stack **a, t_stack **b, int to_a)
{
	t_stack	*tmp_a;
	t_stack *tmp_b;

	tmp_a = *a,
	tmp_b = *b;
	move_a_to_top(tmp_a);
	move_b_to_top(tmp_b);
	if (to_a)
	{
		pa(&tmp_b, &tmp_a);
		ft_printf("pa\n");
	}
	else
	{
		pb(&tmp_a, &tmp_b);
		ft_printf("pb\n");
	}
	*a = get_head(tmp_a);
	*b = get_head(tmp_b);
}
