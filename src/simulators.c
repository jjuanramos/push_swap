/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:01:31 by juramos           #+#    #+#             */
/*   Updated: 2024/03/01 11:02:11 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**simulate_mvmts_a(t_stack *stck)
{
	char	**mvmts;
	t_stack	*tmp;
	int		pos;

	mvmts = ft_calloc(get_stack_size(get_head(stck)), sizeof(char *));
	if (!stck)
		return (mvmts);
	tmp = copy_stck(stck);
	pos = 0;
	while (stck->value != get_head(tmp)->value)
	{
		if (pos_til_head(tmp, stck->value) < get_stack_size(get_head(tmp)) / 2)
		{
			add_to_mvmts(mvmts, "r", &pos, 1);
			ra(tmp);
		}
		else
		{
			add_to_mvmts(mvmts, "rr", &pos, 1);
			rra(tmp);
		}
	}
	clean_stack(tmp);
	return (mvmts);
}

char	**simulate_mvmts_b(t_stack *stck)
{
	char	**mvmts;
	t_stack	*tmp;
	int		pos;

	mvmts = ft_calloc(get_stack_size(get_head(stck)), sizeof(char *));
	if (!stck)
		return (mvmts);
	tmp = copy_stck(stck);
	pos = 0;
	while (stck->value != get_head(tmp)->value)
	{
		if (pos_til_head(tmp, stck->value) < get_stack_size(get_head(tmp)) / 2)
		{
			add_to_mvmts(mvmts, "r", &pos, 0);
			rb(tmp);
		}
		else
		{
			add_to_mvmts(mvmts, "rr", &pos, 0);
			rrb(tmp);
		}
	}
	clean_stack(tmp);
	return (mvmts);
}
