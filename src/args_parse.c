/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:24:13 by juramos           #+#    #+#             */
/*   Updated: 2024/02/15 11:43:33 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_str_digit(char *str)
{
	int	pos;

	pos = -1;
	while (str[++pos])
	{
		if (!ft_isdigit(str[pos])
			&& !(str[pos] == '-' && pos == 0))
			return (0);
	}
	return (1);
}

static int	is_arg_unique(char *arr[], int pos)
{
	char	*ref;

	ref = arr[pos];
	while (arr[++pos])
	{
		if (ft_strncmp(ref, arr[pos], LEN_MAX_INT) == 0)
			return (0);
	}
	return (1);
}

static int	is_eq_or_less_int_max(char *str)
{
	int	val;

	val = ft_atoi(str);
	if ((val < 0 && str[0] != '-')
		|| (ft_strlen(str) != ft_strlen(ft_itoa(val))))
		return (0);
	return (1);
}

static t_stack	*arr_to_stack(int *arr, int len)
{
	t_stack	*stck;
	t_stack	*new;
	int		pos;

	stck = init_stack_on_value(arr[0]);
	pos = 0;
	while (++pos < len)
	{
		new = init_stack_on_value(arr[pos]);
		stck->next = new;
		new->prev = stck;
		stck = new;
	}
	return (stck);
}

t_stack	*parse_to_stck(int argc, char *argv[])
{
	int		*arr;
	int		argv_pos;
	t_stack	*stck;

	arr = ft_calloc(argc, sizeof(int));
	if (!arr)
		message_and_exit("Error\n", 2, 1);
	argv_pos = 0;
	while (argv[++argv_pos])
	{
		if (is_str_digit(argv[argv_pos]) && is_arg_unique(argv, argv_pos)
			&& is_eq_or_less_int_max(argv[argv_pos]))
			arr[argv_pos - 1] = ft_atoi(argv[argv_pos]);
		else
		{
			free(arr);
			message_and_exit("Error\n", 2, 1);
		}
	}
	stck = arr_to_stack(arr, argc - 1);
	return (stck);
}
