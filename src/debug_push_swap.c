/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:33 by juramos           #+#    #+#             */
/*   Updated: 2024/02/29 13:35:24 by juramos          ###   ########.fr       */
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

static void	turk_order(t_stack **a, t_stack **b)
{
	ft_printf("\n------------------iteration------------------\n");
	print_stack(*a, "A looking like this: ");
	print_stack(*b, "B looking like this: ");
	print_stack(*a, "A looking like this after: ");
	print_stack(*b, "B looking like this after: ");
}

/*	push_swap:
	We used the turkish algorithm. This means:
	1.  If A.length > 3, we send A.values to B until B.length == 2
		or A.length == 3.
	2.  We start sending A.values to B. We check which A.pivot has to be sent
		based on the minimum number of mvmts that has to be performed.
		How we decide:
			- if we are pushing to B, pivot has to be above direct B.min.
			- if we are pushing to A, pivot has to be abover direct A.max.
	3.	How we calculate the mvmts:
		- Identify direct B.min/A.max depending on the destination of the pivot.
		- Identify first what mvmts B.min/A.max needs to get to the top.
		- Identify then the mvmts needed to get pivot to the top.
		- Compare mvmts to see if we can replace with rr/rrr's.
			- if length of mvmts is the same for both and all values are unique
			for each set, replace set of mvmts of pivot with mvmts of B.min/A.max
			so we can replace them with rr/rrr's instead.
*/
void	debug_push_swap(t_stack *stack_a)
{
	t_stack	*a;
	t_stack	*b;
	int		iters;

	a = get_head(stack_a);
	b = NULL;
	if (get_stack_size(a) <= 3)
		check_three(a);
	while (get_stack_size(a) > 3 && get_stack_size(b) < 2)
	{
		pb(&a, &b);
		a = get_head(a);
		b = get_head(b);
	}
	while (get_stack_size(a) > 3)
		turk_order(&a, &b);
	exit(0);
}
