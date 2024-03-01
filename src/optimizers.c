/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:29:57 by juramos           #+#    #+#             */
/*   Updated: 2024/03/01 13:23:28 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_combined_mvmt(char *mvmt)
{
	if (ft_strncmp(mvmt, "rr", 2) == 0)
		return ("rrr");
	return ("rr");
}

char	**optimize_mvmts_to_b(char **mvmts_1, char **mvmts_2)
{
	int		pos_main;
	int		pos_sec;
	int		pos_mvmts;
	char	**mvmts;
	char	**main;
	char	**sec;

	pos_main = 0;
	pos_sec = 0;
	pos_mvmts = 0;
	mvmts = ft_calloc(get_str_arr_len(mvmts_1)
			+ get_str_arr_len(mvmts_2) + 2, sizeof(char *));
	if (get_str_arr_len(mvmts_1) >= get_str_arr_len(mvmts_2))
	{
		main = mvmts_1;
		sec = mvmts_2;
	}
	else
	{
		main = mvmts_2;
		sec = mvmts_1;
	}
	while (main[pos_main])
	{
		if (sec[pos_sec] && ft_strncmp(main[pos_main], sec[pos_sec], 3) == 0
			&& pos_sec++)
			mvmts[pos_mvmts] = get_combined_mvmt(main[pos_main]);
		else
			mvmts[pos_mvmts] = main[pos_main];
		pos_mvmts++;
		pos_main++;
	}
	while (sec[pos_sec])
	{
		mvmts[pos_mvmts] = sec[pos_sec];
		pos_mvmts++;
		pos_sec++;
	}
	mvmts[pos_mvmts] = "pb";
	return (mvmts);
}
