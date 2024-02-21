/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:25:37 by juramos           #+#    #+#             */
/*   Updated: 2024/02/21 13:10:54 by juramos          ###   ########.fr       */
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

int	distance_to_head(t_stack *stck)
{
	int		n;
	t_stack	*t;

	n = 0;
	t = stck;
	while (t->prev)
	{
		n++;
		t = t->prev;
	}
	return (n);
}

t_stack	*move_to_stack_b(t_stack *a, t_stack *b)
{
	t_stack	*head_a;

	head_a = get_head(stack_a);
	if (head_a->value == a->value)
		b = pb(head_a, b);
	else if ((head_a->next) && (head_a->next)->value == a->value)
		sa(stack_a);
	else if (distance_to_head(a) < get_stack_size(head_a) / 2)
		ra(stack_a);
	else
		rra(stack_a);
	return (b);
}

t_stack	*check_three_reversed(t_stack *stck)
{
	t_stack	*s;

	s = get_head(stck);
	if (s->value < (s->next)->value && s->value > (get_tail(s))->value)
		sb(stck);
	else if (s->value < (s->next)->value && s->value < (get_tail(s))->value)
		rb(stck);
	else
		rrb(stck);
	return (stck);
}

t_stack	*reverse_order_chunk_in_b(t_stack *head_a, t_stack *b)
{
	int		max_b;
	int		size_b;
	t_stack	*head_b;

	head_b = get_head(b);
	max_b = get_max_to_right(head_b);
	size_b = get_stack_size(head_b);
	if (size_b <= 3)
		b = check_three_reversed(b);
	else if (head_b->value == max_b)
		b = pa(head_b, head_a);
	else if ((head_b->next) && (head_b->next)->value == max_b)
		sb(b);
	else if (pos_til_max_at_head(head_b) < size_b / 2)
		rb(b);
	else
		rrb(b);
	return (b);
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
void	order_chunks(t_stack *stack_a, int chunks, int a_size)
{
	int		current_chunk;
	int		chunk_for_pivot;
	t_stack	*a;
	t_stack	*b;

	current_chunk = 0;
	b = NULL;
	while (current_chunk < chunks)
	{
		// iter on A
		a = get_head(stack_a);
		while (a && a->next)
		{
			chunk_for_pivot = how_many_smaller(a) / (a_size / chunks);
			if (chunk_for_pivot == current_chunk)
			{
				b = move_to_stack_b(a, b);
				a = get_head(a);
				b = get_head(b);
			}
			else
				a = a->next;
		}
		// iter on B
		b = get_head(b);
		while (b && b->next)
		{
			chunk_for_pivot = how_many_smaller(b) / (a_size / chunks);
			if (chunk_for_pivot == current_chunk
				&& is_greater_than(b, 0) && is_smaller_than(b, 0))
			{
				b = reverse_order_chunk_in_b(a, b);
				b = get_head(b);
				a = get_head(a);
			}
			else
				b = b->next;
		}
		// iter on A
		a = get_head(stack_a);
		while (a && a->next)
		{
			chunk_for_pivot = how_many_smaller(a) / (a_size / chunks);
			if (chunk_for_pivot == current_chunk)
			{
				b = move_to_stack_b(a, b);
				a = get_head(a);
				b = get_head(b);
			}
			else
				a = a->next;
		}
		current_chunk++;
		if (current_chunk == chunks)
			push_to_a(a, b);
	}
}

/*
	maybe we could resort to previous behavior 
	when size < N (where N == 50, to iterate)
*/
void	quicksort(t_stack *stack_a)
{
	int		a_size;
	int		current_chunk;
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
	order_chunks(stack_a, chunks, a_size);
	if (b)
		clean_stack(b);
}
