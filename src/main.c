/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:00 by juramos           #+#    #+#             */
/*   Updated: 2024/02/09 17:21:35 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// debugging
void	leaks(void)
{
	system("leaks -q ./push_swap");
}

// debugging
void	print_arr(int *arr, int arr_size)
{
	int	pos;

	pos = 0;
	while (pos < arr_size)
	{
		ft_printf("%d ", arr[pos]);
		pos++;
	}
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;

	if (argc < 2)
		message_and_exit("Error\n", 2, 1);
	else
	{
		stack_a = convert_to_arr(argc, argv);
		stack_b = ft_calloc(argc - 1, sizeof(int));
		if (!stack_a || !stack_b)
			message_and_exit("Error\n", 2, 1);
	}
	print_arr(stack_a, argc - 1);
	quicksort(stack_a, stack_b, argc - 1);
	print_arr(stack_a, argc - 1);
	atexit(leaks);
	return (0);
}
