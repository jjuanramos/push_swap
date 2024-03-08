/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:33:09 by juramos           #+#    #+#             */
/*   Updated: 2024/03/08 10:03:32 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_til_head(t_stack *stck, int n)
{
	t_stack	*t;
	int		dist;

	t = get_head(stck);
	dist = 0;
	while (t && t->value != n)
	{
		dist++;
		t = t->next;
	}
	return (dist);
}

void	update_pivot(int **pivot, int **new)
{
	free(*pivot);
	*pivot = *new;
}

void	add_to_mvmts(int *mvmts, int val, int *pos)
{
	mvmts[*pos] = val;
	*pos = *pos + 1;
}

void	append_to_main(int *main, int *pos_main, int *sec)
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
