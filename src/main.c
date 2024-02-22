/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:00 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 11:39:04 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	if (argc >= 2)
	{
		stack_a = parse_to_stck(argc, argv);
		if (!stack_a)
			message_and_exit("Error\n", 2, 1);
		quicksort(stack_a);
		clean_stack(stack_a);
	}
	return (0);
}
