/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:01:31 by juramos           #+#    #+#             */
/*   Updated: 2024/03/04 13:34:37 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_mvmts(int *mvmts, int val, int *pos)
{
	mvmts[*pos] = val;
	*pos = *pos + 1;
}

static void	append_to_main(int *main, int *pos_main, int *sec)
{
	int	pos_sec;

	pos_sec = 0;
	while (sec[pos_sec])
	{
		main[*pos_main] = sec[pos_sec];
		pos_sec++;
		*pos_main = *pos_main + 1;
	}
}

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
			add_to_mvmts(mvmts, 2, &pos);
			ra(tmp);
		}
		else
		{
			add_to_mvmts(mvmts, 3, &pos);
			rra(tmp);
		}
	}
	return (clean_stack(tmp), mvmts);
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
			add_to_mvmts(mvmts, 5, &pos);
			rb(tmp);
		}
		else
		{
			add_to_mvmts(mvmts, 6, &pos);
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
		add_to_mvmts(main, 1, &pos_main);
	else
		add_to_mvmts(main, 4, &pos_main);
	return (main);
}
