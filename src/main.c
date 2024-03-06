/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:00 by juramos           #+#    #+#             */
/*   Updated: 2024/03/06 11:32:31 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_arr_len(char **str_arr)
{
	int	len;

	len = 0;
	while (str_arr[len])
		len++;
	return (len);
}

static void	free_str_arr(char **arr)
{
	int	pos;

	pos = -1;
	while (arr[pos++])
		free(arr[pos]);
	free(arr);
}

static t_stack	*parse_to_stck_from_str(int len, char **str_arr)
{
	int		*arr;
	int		pos;
	t_stack	*stck;

	arr = ft_calloc(len, sizeof(int));
	if (!arr)
		message_and_exit("Error\n", 2, 1);
	pos = 0;
	while (str_arr[pos])
	{
		if (is_str_digit(str_arr[pos]) && is_arg_unique(str_arr, pos)
			&& is_eq_or_less_int_max(str_arr[pos]))
			arr[pos] = ft_atoi(str_arr[pos]);
		else
		{
			free(arr);
			message_and_exit("Error\n", 2, 1);
		}
		pos++;
	}
	stck = arr_to_stack(arr, len);
	free(arr);
	return (stck);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	**helper;
	int		len;

	if (argc >= 2)
	{
		helper = NULL;
		len = 0;
		if (argc == 2 && ft_strnstr(argv[1], " ", ft_strlen(argv[1])))
		{
			helper = ft_split(argv[1], ' ');
			len = str_arr_len(helper);
			stack_a = parse_to_stck_from_str(len, helper);
			free_str_arr(helper);
		}
		else
			stack_a = parse_to_stck(argc, argv);
		if (!stack_a)
			message_and_exit("Error\n", 2, 1);
		push_swap(&stack_a);
		clean_stack(stack_a);
	}
	return (0);
}
