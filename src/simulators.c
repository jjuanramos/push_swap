/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:01:31 by juramos           #+#    #+#             */
/*   Updated: 2024/03/04 12:10:14 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_mvmts(char **mvmts, char *val, int *pos, int is_a)
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

static void	append_to_main(char **main, int *pos_main, char **sec)
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
	return (clean_stack(tmp), mvmts);
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
	return (clean_stack(tmp), mvmts);
}

char	**concat_mvmts(char **mvmts_1, char **mvmts_2, int to_a)
{
	int		pos_main;
	char	**main;

	pos_main = 0;
	main = ft_calloc(get_str_arr_len(mvmts_1)
			+ get_str_arr_len(mvmts_2) + 2, sizeof(char *));
	append_to_main(main, &pos_main, mvmts_1);
	append_to_main(main, &pos_main, mvmts_2);
	if (to_a)
		add_to_mvmts(main, "p", &pos_main, 1);
	else
		add_to_mvmts(main, "p", &pos_main, 0);
	return (main);
}
