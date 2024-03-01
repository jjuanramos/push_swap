/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:28:12 by juramos           #+#    #+#             */
/*   Updated: 2024/03/01 13:37:32 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**check_mvmts_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*pivot;
	t_stack	*a_closest_greater;
	char	**b_mvmts;
	char	**a_mvmts;
	char	**min_mvmts;

	pivot = stack_b;
	a_closest_greater = get_closest_greater(pivot, stack_a);
	a_mvmts = simulate_mvmts_a(a_closest_greater);
	b_mvmts = simulate_mvmts_b(pivot);
	min_mvmts = optimize_mvmts_to_a(b_mvmts, a_mvmts);
	return (min_mvmts);
}

void	send_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	char	**mvmts;
	char	**pivot_mvmts;

	a = *stack_a;
	b = *stack_b;
	pivot_mvmts = check_mvmts_to_a(a, b);
	while (b)
	{
		mvmts = check_mvmts_to_a(a, b);
		if (get_str_arr_len(mvmts) < get_str_arr_len(pivot_mvmts))
			pivot_mvmts = mvmts;
		b = b->next;
	}
	ft_printf("------->resulting optimized mvmts are:\n");
	print_str_arr(pivot_mvmts);
	ft_printf("<------------->\n");
	exec_mvmts_to_a(&a, &b, pivot_mvmts);
	ft_printf("\n--->After exect_mvmts_to_a:\n");
	print_stack(a, "A: ");
	print_stack(b, "B: ");
	*stack_a = get_head(a);
	*stack_b = get_head(b);
}
