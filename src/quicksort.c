/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:25:37 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 10:17:08 by juramos          ###   ########.fr       */
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

int	is_smaller_than(t_stack *stck, int to_right)
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

/*	order_chunks:
	1. for each pivot, identify the chunk it belongs to.
	2. if pivot in current chunk iter, move pivot to B.
	3. when all values from stack A of current chunk iter
		are in B, order B. (after ordering we might pb values
		that, during the order, have been moved to A).
	4. do 1-3 until last chunk iter, there, after ordering,
		make sure all values are push back to A.
*/
void	debug_order_chunks(t_stack **stack_a, int chunks)
{
	int		current_chunk;
	int		iters;
	t_stack	*a;
	t_stack	*b;

	current_chunk = 0;
	b = NULL;
	iters = 0;
	get_chunks(*stack_a, chunks);
	a = get_head(*stack_a);
	while (current_chunk <= chunks)
	{
		ft_printf("chunk %d out of %d chunks\n\n", current_chunk, chunks);
		// iter on A
		a = get_head(a);
		b = get_head(b);
		while (a)
		{
			if (a->chunk == current_chunk)
			{
				ft_printf("%d chunk in A: now checking for %d in A\n", a->chunk, a->value);
				print_stack(get_head(a), "start of A:\t");
				print_stack(get_head(b), "start of B:\t");
				move_to_stack_b(&a, &b);
				a = get_head(a);
				b = get_head(b);
				print_stack(get_head(a), "result of A:\t");
				print_stack(get_head(b), "result of B:\t");
				ft_printf("\n---------------------------------\n\n");
				iters++;
			}
			else if (a->next)
				a = a->next;
			else
				break ;
		}
		// iter on B
		a = get_head(a);
		b = get_head(b);
		while (b)
		{
			if (!((is_greater_than(b, 0) && is_smaller_than(b, 0)) || b->chunk != current_chunk))
			{
				ft_printf("%d chunk in B: now checking for %d in B\n", b->chunk, b->value);
				print_stack(a, "start of A:\t");
				print_stack(b, "start of B:\t");
				reverse_order_chunk_in_b(&a, &b);
				b = get_head(b);
				a = get_head(a);
				print_stack(a, "result of A:\t");
				print_stack(b, "result of B:\t");
				ft_printf("\n---------------------------------\n\n");
			}
			else if (b->next)
				b = b->next;
			else
				break ;
		}
		// iter on A
		a = get_head(a);
		b = get_head(b);
		while (a)
		{
			ft_printf("2nd: %d chunk in A, current chunk %d: comprobando for %d in A\n", a->chunk, current_chunk, a->value);
			if (a->chunk == current_chunk)
			{
				ft_printf("2nd: now checking for %d in A for chunk %d\n", a->value, current_chunk);
				print_stack(a, "start of A:\t");
				print_stack(b, "start of B:\t");
				move_to_stack_b(&a, &b);
				a = get_head(a);
				b = get_head(b);
				print_stack(get_head(a), "result of A:\t");
				print_stack(get_head(b), "result of B:\t");
				ft_printf("\n---------------------------------\n\n");
			}
			else if (a->next)
				a = a->next;
			else
				break ;
		}
		current_chunk++;
	}
	a = get_head(a);
	b = get_head(b);
	while (b)
		pa(&b, &a);
	print_stack(get_head(a), "end result of A:\t");
	print_stack(get_head(b), "end result of B:\t");
	ft_printf("\n---------------------------------\n\n");
}

/*
	maybe we could resort to previous behavior 
	when size < N (where N == 50, to iterate)
*/
void	quicksort(t_stack *stack_a)
{
	int		a_size;
	int		chunks;

	a_size = get_stack_size(get_head(stack_a));
	if (a_size > 250)
		chunks = 11;
	else if (a_size > 49)
		chunks = 6;
	else if (a_size > 19)
		chunks = 3;
	else
		chunks = 1;
	order_chunks(&stack_a, chunks);
}
