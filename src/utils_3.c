/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:33:09 by juramos           #+#    #+#             */
/*   Updated: 2024/03/01 10:42:38 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_mvmts(char **mvmts, char *val, int *pos, int is_a)
{
	int	str_len;
	int	i;

	i = 0;
	str_len = ft_strlen(val);
	mvmts[*pos] = ft_calloc(str_len + 2, sizeof(char));
	while (i < str_len)
	{
		mvmts[*pos][i] = val[i];
		i++;
	}
	if (is_a)
		mvmts[*pos][i] = 'a';
	else
		mvmts[*pos][i] = 'b';
	*pos = *pos + 1;
}



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
