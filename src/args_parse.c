/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:24:13 by juramos           #+#    #+#             */
/*   Updated: 2024/02/11 12:13:58 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_str_digit(char *str)
{
	int	pos;

	pos = -1;
	while (str[++pos])
	{
		if (!ft_isdigit(str[pos]))
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

static void	stck_add_back(t_stack **stck, int val)
{
	t_stack	*t;

	t = ft_calloc(1, sizeof(t_stack));
	if (!t)
		message_and_exit("Exit\n", 2, 1);
	t->head = (*stck)->head;
	t->prev = *stck;
	t->value = val;
	t->next = NULL;
	t->tail = t;
	t->size = (*stck)->size;
	(*stck)->next = t;
	(*stck)->tail = t;
}

static t_stack	*arr_to_stack(int *arr, int len)
{
	t_stack	*stck;
	int		pos;

	stck = ft_calloc(1, sizeof(t_stack));
	if (!stck)
		message_and_exit("Exit\n", 2, 1);
	stck->head = stck;
	stck->prev = NULL;
	stck->value = arr[0];
	stck->tail = stck;
	stck->size = len;
	pos = 0;
	while (++pos < len)
	{
		stck_add_back(&stck, arr[pos]);
		stck = stck->next;
	}
	return (stck);
}

static void	print_stack(t_stack	*stck)
{
	t_stack	*t;
	int		pos;

	pos = 0;
	t = stck->head;
	while (pos < t->size)
	{
		ft_printf("%d", t->value);
		if (t->next)
			t = t->next;
		else
			break ;
	}
	ft_printf("\n");
}

int	*convert_to_arr(int argc, char *argv[])
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
	print_stack(stck);
	return (arr);
}
