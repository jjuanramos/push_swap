/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:25:37 by juramos           #+#    #+#             */
/*   Updated: 2024/02/13 12:49:00 by juramos          ###   ########.fr       */
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
			if ((t->prev)->value > stck->value)
				return (0);
			t = t->prev;
		}
	}
	return (1);
}

/* quicksort
	1. checking:
		- if pivot == 0 && stack B is empty -> done
		- else if pivot == 0 && stack B is not empty -> start conquering B
		- else if all values of stack A to left are smaller than & all values
		to right are greater than, pivot--.
		- else: conquer A
	2. conquering:
		- in Stack A:
			- if pivot - n < pivot -> pb
			- if pivot - n > pivot
				-> if len - pos <= 3
					-> check if sa (0 > 1 && 0 < 2) // check stack B for ss
					-> check if sa && ra (0 < 1 && 2 < 1) // check stack B for ss & rr
				-> ra
		- in Stack B:
			- if pivot is max -> pa
			- if last is max -> rrb
			- if 0 < 1 -> sb // check stack A for ss
			- else -> rrb
	3. 
		- else if last pivot pos == 0 && stack B is not empty -> start ordering stack B
		- else if last pivot pos == len of stack B - 1 -> pa
		- else if last pivot pos != len - 1 && stack B -> pivot + 1 and repeat
*/
void	quicksort(t_stack *stack_a)
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
			b = order(a, b, 1);
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
		b = order(a, b, 0);
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
