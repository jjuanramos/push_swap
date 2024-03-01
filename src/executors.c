/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:02 by juramos           #+#    #+#             */
/*   Updated: 2024/03/01 13:05:01 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_rr(t_stack *a, t_stack *b, char *mvmt)
{
	if (ft_strncmp(mvmt, "rrr", 3) == 0)
	{
		rrr(a, b);
		ft_printf("rrr\n");
	}
	else if (ft_strncmp(mvmt, "rrb", 3) == 0)
	{
		rrb(b);
		ft_printf("rrb\n");
	}
	else if (ft_strncmp(mvmt, "rra", 3) == 0)
	{
		rra(a);
		ft_printf("rra\n");
	}
}

static void	check_r(t_stack *a, t_stack *b, char *mvmt)
{
	if (ft_strncmp(mvmt, "rr", 2) == 0)
	{
		rr(a, b);
		ft_printf("rr\n");
	}
	else if (ft_strncmp(mvmt, "rb", 2) == 0)
	{
		rb(b);
		ft_printf("rb\n");
	}
	else if (ft_strncmp(mvmt, "ra", 2) == 0)
	{
		ra(a);
		ft_printf("ra\n");
	}
}

void	exec_mvmts_to_b(t_stack **a, t_stack **b, char **pivot_mvmts)
{
	int		pos;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	pos = 0;
	tmp_a = get_head(*a);
	tmp_b = get_head(*b);
	while (pivot_mvmts[pos])
	{
		if (ft_strncmp(pivot_mvmts[pos], "pb", 2) == 0)
		{
			pb(&tmp_a, &tmp_b);
			ft_printf("pb\n");
		}
		else if (ft_strncmp(pivot_mvmts[pos], "rr", 2) == 0
			&& ft_strlen(pivot_mvmts[pos]) == 3)
			check_rr(tmp_a, tmp_b, pivot_mvmts[pos]);
		else
			check_r(tmp_a, tmp_b, pivot_mvmts[pos]);
		pos++;
	}
	*a = get_head(tmp_a);
	*b = get_head(tmp_b);
}
