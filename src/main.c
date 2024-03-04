/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:00 by juramos           #+#    #+#             */
/*   Updated: 2024/03/04 13:33:36 by juramos          ###   ########.fr       */
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
			stack_a = parse_to_stck(len, helper);
			free_str_arr(helper);
		}
		else
			stack_a = parse_to_stck(argc, argv);
		if (!stack_a)
			message_and_exit("Error\n", 2, 1);
		debug_push_swap(&stack_a);
		print_stack(stack_a, "");
		clean_stack(stack_a);
	}
	return (0);
}
