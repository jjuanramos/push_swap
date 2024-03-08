/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:01:31 by juramos           #+#    #+#             */
/*   Updated: 2024/03/08 10:12:56 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*simulate_mvmts_a(t_stack *stck)
{
	int		*mvmts;
	t_stack	*tmp;
	int		pos;

	mvmts = ft_calloc(get_stack_size(get_head(stck)), sizeof(int));
	if (!stck)
		return (mvmts);
	tmp = copy_stck(stck);
	pos = 0;
	while (stck->value != get_head(tmp)->value)
	{
		if (pos_til_head(tmp, stck->value) < get_stack_size(get_head(tmp)) / 2)
		{
			add_to_mvmts(mvmts, RA, &pos);
			ra(tmp);
		}
		else
		{
			add_to_mvmts(mvmts, RRA, &pos);
			rra(tmp);
		}
	}
	return (clean_stack(tmp), mvmts);
}

int	*check_if_double_mov(t_stack *pivot, t_stack *opp, int to_a)
{
	int	*mvmts;
	int	pos;

	pos = 0;
	mvmts = ft_calloc(3, sizeof(int));
	if (pivot->value == get_tail(pivot)->value
		&& opp->value == get_tail(opp)->value)
		add_to_mvmts(mvmts, RRR, &pos);
	else if (pivot->prev && pivot->prev->value == get_head(pivot)->value
		&& opp->prev && opp->prev->value == get_head(pivot)->value)
		add_to_mvmts(mvmts, RR, &pos);
	if (to_a)
		add_to_mvmts(mvmts, PA, &pos);
	else
		add_to_mvmts(mvmts, PB, &pos);
	return (mvmts);
}

int	*simulate_mvmts_b(t_stack *stck)
{
	int		*mvmts;
	t_stack	*tmp;
	int		pos;

	mvmts = ft_calloc(get_stack_size(get_head(stck)), sizeof(int));
	if (!stck)
		return (mvmts);
	tmp = copy_stck(stck);
	pos = 0;
	while (stck->value != get_head(tmp)->value)
	{
		if (pos_til_head(tmp, stck->value) < get_stack_size(get_head(tmp)) / 2)
		{
			add_to_mvmts(mvmts, RB, &pos);
			rb(tmp);
		}
		else
		{
			add_to_mvmts(mvmts, RRB, &pos);
			rrb(tmp);
		}
	}
	return (clean_stack(tmp), mvmts);
}

int	*concat_mvmts(int *mvmts_1, int *mvmts_2, int to_a)
{
	int		pos_main;
	int		*main;

	pos_main = 0;
	main = ft_calloc(get_int_arr_len(mvmts_1)
			+ get_int_arr_len(mvmts_2) + 2, sizeof(int));
	append_to_main(main, &pos_main, mvmts_1);
	append_to_main(main, &pos_main, mvmts_2);
	if (to_a)
		add_to_mvmts(main, PA, &pos_main);
	else
		add_to_mvmts(main, PB, &pos_main);
	return (main);
}
