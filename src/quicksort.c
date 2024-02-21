/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:25:37 by juramos           #+#    #+#             */
/*   Updated: 2024/02/21 19:04:37 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_greater_than(t_stack *stck, int to_left)
{
	t_stack	*t;

	t = stck;
	if (to_left)
	{
		while (t->prev)
		{
			if ((t->prev)->value > stck->value)
				return (0);
			t = t->prev;
		}
	}
	else
	{
		while (t->next)
		{
			if ((t->next)->value > stck->value)
				return (0);
			t = t->next;
		}
	}
	return (1);
}

static int	is_smaller_than(t_stack *stck, int to_right)
{
	t_stack	*t;

	t = stck;
	if (to_right)
	{
		while (t->next)
		{
			if ((t->next)->value < stck->value)
				return (0);
			t = t->next;
		}
	}
	else
	{
		while (t->prev)
		{
			if ((t->prev)->value < stck->value)
				return (0);
			t = t->prev;
		}
	}
	return (1);
}

void	quicksort(t_stack *stack_a)
{
	t_stack	*a;
	t_stack	*b;

	a = get_tail(stack_a);
	b = NULL;
	while (a->prev)
	{
		if (is_greater_than(a, 1) && is_smaller_than(a, 1))
			a = a->prev;
		else
		{
			order(&a, &b, 1);
			a = get_tail(a);
		}
	}
	b = get_head(b);
	a = get_tail(a);
	while (b)
	{
		order(&a, &b, 0);
		b = get_head(b);
		a = get_tail(a);
	}
	if (b)
		clean_stack(b);
}

void	debug_quicksort(t_stack *stack_a)
{
	t_stack	*a;
	t_stack	*b;
	int		movements;

	a = get_tail(stack_a);
	b = NULL;
	movements = 0;
	while (a->prev)
	{
		if (is_greater_than(a, 1) && is_smaller_than(a, 1))
			a = a->prev;
		else
		{
			ft_printf("now checking for %d in A\n", a->value);
			print_stack(get_head(a), "start of A:\t");
			print_stack(get_head(b), "start of B:\t");
			order(&a, &b, 1);
			a = get_tail(a);
			print_stack(get_head(a), "result of A:\t");
			print_stack(get_head(b), "result of B:\t");
			ft_printf("\n---------------------------------\n\n");
			movements++;
		}
	}
	b = get_head(b);
	a = get_tail(a);
	while (b)
	{
		ft_printf("now checking for %d in B\n", b->value);
		print_stack(get_head(a), "start of A:\t");
		print_stack(get_head(b), "start of B:\t");
		order(&a, &b, 0);
		b = get_head(b);
		a = get_tail(a);
		print_stack(get_head(a), "result of A:\t");
		print_stack(get_head(b), "result of B:\t");
		ft_printf("\n---------------------------------\n\n");
		movements++;
	}
	ft_printf("\t>>>> required %d movements. <<<<\n", movements);
	if (b)
		free(b);
}
