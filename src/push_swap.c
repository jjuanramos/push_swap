/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:33 by juramos           #+#    #+#             */
/*   Updated: 2024/03/05 17:06:24 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_stacks_for_order(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = NULL;
	while (get_stack_size(a) > 3 && get_stack_size(b) < 2)
	{
		pb(&a, &b);
		ft_printf("pb\n");
		a = get_head(a);
		b = get_head(b);
	}
	*stack_a = a;
	*stack_b = b;
}

static void	perform_rra(t_stack *a)
{
	rra(a);
	ft_printf("rra\n");
}

static void	perform_on_three(t_stack *a)
{
	if (get_stack_size(a) == 1)
		return ;
	else if (get_stack_size(a) == 2)
		check_three(a);
	else
	{
		while (!(get_head(a)->value < get_head(a)->next->value
				&& get_head(a)->next->value < get_tail(a)->value))
			check_three(a);
	}
}

/*	push_swap:
	We used the turkish algorithm. This means:
	1.  If A.length > 3, we send A.values to B until B.length == 2
		or A.length == 3.
	2.  We start sending A.values to B. We check which A.pivot has to be sent
		based on the minimum number of mvmts that has to be performed.
		How we decide:
			- when pushing to B, pivot has to be above direct B.min.
	3.	How we calculate the mvmts:
		- Identify direct B.min/A.max depending on the destination of the pivot.
		- Identify first what mvmts B.min/A.max needs to get to the top.
		- Identify then the mvmts needed to get pivot to the top.
		- Compare mvmts to see if we can replace with rr/rrr's.
			- if length of mvmts is the same for both and all values are unique
			for each set, replace set of mvmts of pivot with mvmts of B.min/A.max
			so we can replace them with rr/rrr's instead.
	4.  When A.length == 3, we order it.
	5.  We send B.values back to A, taking into account that:
		- when pushing to A, pivot has to be above direct A.max.
	6.	Make sure that latest value sent is min of A.
*/
void	push_swap(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = NULL;
	if (get_stack_size(a) <= 3)
	{
		perform_on_three(a);
		return ;
	}
	set_stacks_for_order(&a, &b);
	while (get_stack_size(a) > 3)
		send_to_b(&a, &b, 25);
	perform_on_three(a);
	while (b)
		send_to_a(&a, &b, 25);
	while (get_min_to_right(get_head(a))->value != get_head(a)->value)
		perform_rra(a);
	*stack_a = a;
}
