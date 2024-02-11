/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:00 by juramos           #+#    #+#             */
/*   Updated: 2024/02/11 15:32:02 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// debugging
void	leaks(void)
{
	system("leaks -q ./push_swap");
}

// debugging
// void	print_arr(int *arr, int arr_size)
// {
// 	int	pos;

// 	pos = 0;
// 	while (pos < arr_size)
// 	{
// 		ft_printf("%d ", arr[pos]);
// 		pos++;
// 	}
// 	ft_printf("\n");
// }

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		message_and_exit("Error\n", 2, 1);
	else
	{
		stack_a = parse_to_stck(argc, argv);
		stack_b = ft_calloc(argc - 1, sizeof(t_stack));
		if (!stack_a || !stack_b)
			message_and_exit("Error\n", 2, 1);
	}
	print_stack(stack_a);
	atexit(leaks);
	return (0);
}
