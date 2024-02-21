/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:25:37 by juramos           #+#    #+#             */
/*   Updated: 2024/02/21 19:03:17 by juramos          ###   ########.fr       */
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

void	move_to_stack_b(t_stack **a, t_stack **b)
{
	t_stack	*head_a;

	head_a = get_head(*a);
	if (head_a->value == (*a)->value)
		pb(a, b);
	else if ((head_a->next) && (head_a->next)->value == (*a)->value)
		sa(*a);
	else if (distance_to_head(*a) < get_stack_size(head_a) / 2)
		ra(*a);
	else
		rra(*a);
}

void	check_three_reversed(t_stack *stck)
{
	t_stack	*s;

	s = get_head(stck);
	if (s->value < (s->next)->value && s->value > (get_tail(s))->value)
		sb(stck);
	else if (s->value < (s->next)->value && s->value < (get_tail(s))->value)
		rb(stck);
	else
		rrb(stck);
}

void	reverse_order_chunk_in_b(t_stack **head_a, t_stack **b)
{
	int		max_b;
	int		size_b;
	t_stack	*head_b;

	head_b = get_head(*b);
	max_b = get_max_to_right(head_b);
	size_b = get_stack_size(head_b);
	if (size_b <= 3)
		check_three_reversed(*b);
	else if (head_b->value == max_b)
		pa(b, head_a);
	else if ((head_b->next) && (head_b->next)->value == max_b)
		sb(*b);
	else if (pos_til_max_at_head(head_b) < size_b / 2)
		rb(*b);
	else
		rrb(*b);
}

void	get_chunks(t_stack *stck, int chunks)
{
	t_stack	*s;
	int		size;

	s = get_head(stck);
	size = get_stack_size(s);
	while (s)
	{
		s->chunk = how_many_smaller(s) / (size / chunks);
		s = s->next;
	}
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
void	order_chunks(t_stack **stack_a, int chunks)
{
	int		current_chunk;
	int		iters;
	t_stack	*a;
	t_stack	*b;

	current_chunk = 0;
	b = NULL;
	iters = 0;
	get_chunks(*stack_a, chunks);
	while (current_chunk < chunks)
	{
		// iter on A
		a = get_head(*stack_a);
		while (a && a->next)
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
				if (iters > 1000)
					exit(0);
			}
			else
				a = a->next;
		}
		// iter on B
		b = get_head(b);
		while (b && b->next)
		{
			if ((is_greater_than(b, 0) && is_smaller_than(b, 0)) || b->chunk != current_chunk)
				b = b->next;
			else
			{
				ft_printf("%d chunk in B: now checking for %d in B\n", b->chunk, b->value);
				print_stack(get_head(a), "start of A:\t");
				print_stack(get_head(b), "start of B:\t");
				reverse_order_chunk_in_b(&a, &b);
				b = get_head(b);
				a = get_head(a);
				print_stack(get_head(a), "result of A:\t");
				print_stack(get_head(b), "result of B:\t");
				ft_printf("\n---------------------------------\n\n");
			}
		}
		// iter on A
		a = get_head(*stack_a);
		while (a && a->next)
		{
			if (a->chunk == current_chunk)
			{
				ft_printf("2nd: now checking for %d in A for chunk %d\n", a->value, current_chunk);
				print_stack(get_head(a), "start of A:\t");
				print_stack(get_head(b), "start of B:\t");
				move_to_stack_b(&a, &b);
				a = get_head(a);
				b = get_head(b);
				print_stack(get_head(a), "result of A:\t");
				print_stack(get_head(b), "result of B:\t");
				ft_printf("\n---------------------------------\n\n");
			}
			else
				a = a->next;
		}
		exit(0);
		current_chunk++;
		if (current_chunk == chunks)
		{
			while (b)
				pa(&b, &a);
		}
	}
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
	if (chunks > 1)
		order_chunks(&stack_a, chunks);
	else
		ft_printf("TODO\n");
}
