/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:33 by juramos           #+#    #+#             */
/*   Updated: 2024/03/04 13:36:05 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	pos_til_head(t_stack *stck);
static void	mvmts_to_head(t_stack *stck, int *mvmts);
static t_stack	*get_closest_min(int ref, t_stack *stck);
static int	check_mvmts(t_stack *a, t_stack *b);
static void	move_to_head_b(t_stack **stck);
static void	move_to_head_a(t_stack **stck);
static void	exec_mvmts(t_stack **a, t_stack **b);
static t_stack	*get_min_pivot(t_stack *a, t_stack *b);
static t_stack	*get_closest_greater(t_stack *ref, t_stack *stack_a);
static void	turk_order_reversed(t_stack **a, t_stack **b);
*/

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
void	debug_push_swap(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = NULL;
	print_stack(a, "we receive A: ");
	if (get_stack_size(a) <= 3)
	{
		while (!(get_head(a)->value < get_head(a)->next->value
				&& get_head(a)->next->value < get_tail(a)->value))
			check_three(a);
		return ;
	}
	set_stacks_for_order(&a, &b);
	ft_printf("\n--->After moving all possible values to B, resulting stacks are:\n");
	print_stack(a, "A: ");
	print_stack(b, "B: ");
	while (get_stack_size(a) > 3)
		send_to_b(&a, &b);
	ft_printf("\n--->After sending all values to B, resulting stacks are:\n");
	print_stack(a, "A: ");
	print_stack(b, "B: ");
	while (!(get_head(a)->value < get_head(a)->next->value
			&& get_head(a)->next->value < get_tail(a)->value))
		check_three(a);
	ft_printf("\n--->After ordering A, resulting stacks are:\n");
	print_stack(a, "A: ");
	print_stack(b, "B: ");
	while (b)
		send_to_a(&a, &b);
	ft_printf("\n--->After sending values from B to A, resulting stacks are:\n");
	print_stack(a, "A: ");
	print_stack(b, "B: ");
	while (get_min_to_right(get_head(a))->value != get_head(a)->value)
	{
		rra(a);
		ft_printf("rra\n");
	}
	ft_printf("\n--->After last check of A, resulting stacks are:\n");
	print_stack(a, "A: ");
	print_stack(b, "B: ");
	*stack_a = a;
}
