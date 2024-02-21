/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:00 by juramos           #+#    #+#             */
/*   Updated: 2024/02/21 18:33:52 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// debugging
void	leaks(void)
{
	system("leaks push_swap");
}

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
	// atexit(leaks);
	return (0);
}
