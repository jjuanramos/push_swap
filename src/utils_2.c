/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:42:20 by juramos           #+#    #+#             */
/*   Updated: 2024/03/04 13:33:08 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_int_arr_len(int	*mvmts)
{
	int	pos;

	pos = 0;
	while (mvmts[pos])
		pos++;
	return (pos);
}

void	print_int_arr(int *mvmts)
{
	int	pos;

	pos = 0;
	while (mvmts[pos])
	{
		ft_printf("%d\n", mvmts[pos]);
		pos++;
	}
}

t_stack	*get_closest_greater(t_stack *ref, t_stack *stack_a)
{
	t_stack	*t;
	t_stack	*closest_greater;

	t = get_head(stack_a);
	closest_greater = get_max_to_right(t);
	if (ref->value > closest_greater->value)
		return (NULL);
	while (t)
	{
		if (t->value > ref->value && t->value < closest_greater->value)
			closest_greater = t;
		t = t->next;
	}
	return (closest_greater);
}

t_stack	*get_closest_min(t_stack *ref, t_stack *stck)
{
	t_stack	*t;
	t_stack	*closest_min;

	t = get_head(stck);
	closest_min = get_min_to_right(t);
	if (ref->value < closest_min->value)
		return (NULL);
	while (t)
	{
		if (t->value < ref->value && t->value > closest_min->value)
			closest_min = t;
		t = t->next;
	}
	return (closest_min);
}
