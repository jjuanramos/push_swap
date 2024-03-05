/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_senders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:28:12 by juramos           #+#    #+#             */
/*   Updated: 2024/03/05 10:55:58 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_mvmts_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*pivot;
	t_stack	*a_closest_greater;
	int		b_mvmts;
	int		a_mvmts;

	pivot = stack_b;
	a_closest_greater = get_closest_greater(pivot, stack_a);
	if (!a_closest_greater)
		a_mvmts = pos_til_head(stack_a,
				get_min_to_right(get_head(stack_a))->value);
	else
		a_mvmts = pos_til_head(stack_a, a_closest_greater->value);
	b_mvmts = pos_til_head(stack_b, pivot->value);
	return (a_mvmts + b_mvmts);
}

static void	update_refs_to_a(t_stack *a, t_stack *b, t_stack **p, t_stack **c)
{
	t_stack	*a_closest_greater;

	*p = b;
	a_closest_greater = get_closest_greater(b, a);
	if (!a_closest_greater)
		*c = get_min_to_right(get_head(a));
	else
		*c = a_closest_greater;
}

static int	check_mvmts_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*pivot;
	t_stack	*b_closest_min;
	int		b_mvmts;
	int		a_mvmts;

	pivot = stack_a;
	b_closest_min = get_closest_min(pivot, stack_b);
	if (!b_closest_min)
		b_mvmts = pos_til_head(stack_b,
				get_max_to_right(get_head(stack_b))->value);
	else
		b_mvmts = pos_til_head(stack_b, b_closest_min->value);
	a_mvmts = pos_til_head(stack_a, pivot->value);
	ft_printf("for pivot %d, we need %d mvmts to put it in head A and %d mvmts to put its counter in head B\n",
		pivot->value, a_mvmts, b_mvmts);
	return (a_mvmts + b_mvmts);
}

static void	update_refs_to_b(t_stack *a, t_stack *b, t_stack **p, t_stack **c)
{
	t_stack	*b_closest_min;

	*p = a;
	b_closest_min = get_closest_min(a, b);
	if (!b_closest_min)
		*c = get_max_to_right(get_head(b));
	else
		*c = b_closest_min;
}

void	tmp_send_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*pivot;
	t_stack	*counter;
	int		pivot_mvmts;

	a = *stack_a;
	b = *stack_b;
	pivot_mvmts = MAX_INT;
	while (b)
	{
		if (pivot_mvmts <= 2)
			break ;
		if (check_mvmts_to_a(a, b) < pivot_mvmts)
		{
			pivot_mvmts = check_mvmts_to_a(a, b);
			update_refs_to_a(a, b, &pivot, &counter);
		}
		if (!b->next)
			break ;
		b = b->next;
	}
	tmp_exec_mvmts(&a, &b, 1);
	*stack_a = get_head(a);
	*stack_b = get_head(b);
}

void	tmp_send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*pivot;
	t_stack	*counter;
	int		pivot_mvmts;

	a = *stack_a;
	b = *stack_b;
	pivot_mvmts = MAX_INT;
	while (a)
	{
		if (pivot_mvmts <= 2)
			break ;
		if (check_mvmts_to_b(a, b) < pivot_mvmts)
		{
			pivot_mvmts = check_mvmts_to_b(a, b);
			update_refs_to_b(a, b, &pivot, &counter);
			ft_printf("new pivot is %d with counter %d, expecting %d mvmts.\n",
				pivot->value, counter->value, pivot_mvmts);
		}
		if (!(a->next))
			break ;
		a = a->next;
	}
	print_stack(a, "----------\nA before execution");
	print_stack(b, "B before execution");
	ft_printf("\n...executing...\n");
	tmp_exec_mvmts(&pivot, &counter, 0);
	ft_printf("...done!...\n\n");
	print_stack(get_head(pivot), "----------\nA after execution");
	print_stack(get_head(counter), "B after execution");
	ft_printf("---------------\n");
	*stack_a = get_head(pivot);
	*stack_b = get_head(counter);
}
