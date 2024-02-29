/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:33 by juramos           #+#    #+#             */
/*   Updated: 2024/02/29 14:57:59 by juramos          ###   ########.fr       */
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

void	set_stacks_for_order(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = NULL;
	while (get_stack_size(a) > 3 && get_stack_size(b) < 2)
	{
		pb(&a, &b);
		a = get_head(a);
		b = get_head(b);
	}
	*stack_a = a;
	*stack_b = b;
}

char	**simulate_mvmts(t_stack *stck)
{
	char	**mvmts;
	t_stack	*tmp;
	int		pos;

	mvmts = ft_calloc(get_stack_size(get_head(stck)), sizeof(char *));
	tmp = copy_stck(stck);
	pos = 0;
	while (stck->value != get_head(tmp)->value)
	{
		if (pos_til_head(tmp, stck->value) < get_stack_size(get_head(tmp)) / 2)
		{
			add_to_mvmts(mvmts, "rb", &pos);
			rb(tmp);
		}
		else
		{
			add_to_mvmts(mvmts, "rrb", &pos);
			rrb(tmp);
		}
		clean_stack(tmp);
		tmp = copy_stck(stck);
	}
	clean_stack(tmp);
	print_str_arr_len(mvmts);
	exit(0);
	return (mvmts);
}

char	**check_mvmts_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*pivot;
	t_stack	*b_closest_min;
	char	**b_mvmts;
	char	**a_mvmts;
	// char	**min_mvmts;

	pivot = stack_a;
	b_closest_min = get_closest_greater(pivot, stack_b);
	b_mvmts = simulate_mvmts(b_closest_min);
	a_mvmts = simulate_mvmts(pivot);
	// min_mvmts = optimize_mvmts(b_mvmts, a_mvmts);
	// actually we return min_mvmts, this is just to make it shut up
	return (free_str_arr(b_mvmts), free_str_arr(a_mvmts), ft_calloc(3, sizeof(char **)));
}

void	send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	char	**mvmts;
	char	**pivot_mvmts;
	int		min_mvmts;

	a = *stack_a;
	b = *stack_b;
	min_mvmts = 0;
	while (a)
	{
		mvmts = check_mvmts_to_b(a, b);
		if (get_str_arr_len(mvmts) < min_mvmts)
		{
			// pivot = a;
			pivot_mvmts = mvmts;
		}
		a = a->next;
	}
	// exec_mvmts_to_b(&pivot, &b, pivot_mvmts);
	free_str_arr(mvmts);
	free_str_arr(pivot_mvmts);
	*stack_a = get_head(a);
	*stack_b = get_head(b);
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
	check_three(a);
	ft_printf("\n--->After ordering A, resulting stacks are:\n");
	print_stack(a, "A: ");
	print_stack(b, "B: ");
	exit(0);
	/*
	send_to_a(&b, &a);
	ft_printf("\n--->After sending values from B to A, resulting stacks are:\n");
	print_stack(a, "A: ");
	print_stack(b, "B: ");
	check_and_order(&a);
	ft_printf("\n--->After last check of A, resulting stacks are:\n");
	print_stack(a, "A: ");
	print_stack(b, "B: ");
	*stack_a = a;
	*/
}
