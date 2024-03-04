/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:29:57 by juramos           #+#    #+#             */
/*   Updated: 2024/03/04 11:23:45 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_combined_mvmt(char *mvmt)
{
	if (ft_strncmp(mvmt, "rr", 2) == 0)
		return ("rrr");
	return ("rr");
}

static char	**minimize_mvmts(char **main, char **sec, int *pos_mvmts)
{
	int		pos_main;
	int		pos_sec;
	char	**mvmts;

	pos_main = 0;
	pos_sec = 0;
	mvmts = ft_calloc(get_str_arr_len(main)
			+ get_str_arr_len(sec) + 2, sizeof(char *));
	while (main[pos_main])
	{
		if (sec[pos_sec] && ft_strncmp(main[pos_main], sec[pos_sec], 3) == 0
			&& pos_sec++)
			mvmts[*pos_mvmts] = get_combined_mvmt(main[pos_main]);
		else
			mvmts[*pos_mvmts] = main[pos_main];
		*pos_mvmts = *pos_mvmts + 1;
		pos_main++;
	}
	while (sec[pos_sec])
	{
		mvmts[*pos_mvmts] = sec[pos_sec];
		*pos_mvmts = *pos_mvmts + 1;
		pos_sec++;
	}
	return (mvmts);
}

char	**optimize_mvmts(char **mvmts_1, char **mvmts_2, int to_a)
{
	int		pos_mvmts;
	char	**mvmts;

	pos_mvmts = 0;
	if (get_str_arr_len(mvmts_1) >= get_str_arr_len(mvmts_2))
		mvmts = minimize_mvmts(mvmts_1, mvmts_2, &pos_mvmts);
	else
		mvmts = minimize_mvmts(mvmts_2, mvmts_1, &pos_mvmts);
	if (to_a)
		mvmts[pos_mvmts] = "pa";
	else
		mvmts[pos_mvmts] = "pb";
	return (mvmts);
}
