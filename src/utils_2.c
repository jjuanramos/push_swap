/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:42:20 by juramos           #+#    #+#             */
/*   Updated: 2024/02/29 14:43:47 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_mvmts(char **mvmts, char *val, int *pos)
{
	mvmts[pos] = ft_calloc(ft_strlen(val) + 1, sizeof(char));
	mvmts[pos] = val;
	(*pos) = pos + 1;
}

void	free_str_arr(char **mvmts)
{
	int	pos;

	pos = -1;
	while (mvmts[pos++])
		free(mvmts[pos]);
	free(mvmts);
}
