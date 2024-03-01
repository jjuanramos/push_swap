/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:33:09 by juramos           #+#    #+#             */
/*   Updated: 2024/03/01 11:04:25 by juramos          ###   ########.fr       */
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
