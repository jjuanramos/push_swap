/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:00 by juramos           #+#    #+#             */
/*   Updated: 2024/02/07 15:31:34 by juramos          ###   ########.fr       */
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
	int	*arr;

	if (argc < 2)
		message_and_exit("Error\n", 2, 1);
	else
	{
		arr = convert_to_arr(argc, argv);
		print_arr(arr, argc - 1);
		if (!arr)
			message_and_exit("Error\n", 2, 1);
	}
	atexit(leaks);
	return (0);
}
