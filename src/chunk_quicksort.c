/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:12:29 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 11:04:34 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	iter_on_a(t_stack **a, t_stack **b, int current_chunk)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = get_head(*a);
	tmp_b = get_head(*b);
	while (tmp_a)
	{
		if (tmp_a->chunk == current_chunk)
		{
			move_to_stack_b(&tmp_a, &tmp_b);
			tmp_a = get_head(tmp_a);
			tmp_b = get_head(tmp_b);
		}
		else if (tmp_a->next)
			tmp_a = tmp_a->next;
		else
			break ;
		*a = get_head(tmp_a);
		*b = get_head(tmp_b);
	}
}

static void	iter_on_b(t_stack **a, t_stack **b, int current_chunk)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = get_head(*a);
	tmp_b = get_head(*b);
	while (tmp_b)
	{
		if (!((is_greater_than(tmp_b, 0) && is_smaller_than(tmp_b, 0))
				|| tmp_b->chunk != current_chunk))
		{
			reverse_order_chunk_in_b(&tmp_a, &tmp_b);
			tmp_b = get_head(tmp_b);
			tmp_a = get_head(tmp_a);
		}
		else if (tmp_b->next)
			tmp_b = tmp_b->next;
		else
			break ;
		*b = get_head(tmp_b);
		*a = get_head(tmp_a);
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
void	chunk_quicksort(t_stack **stack_a, int chunks)
{
	int		current_chunk;
	t_stack	*a;
	t_stack	*b;

	current_chunk = 0;
	b = NULL;
	get_chunks(*stack_a, chunks);
	a = get_head(*stack_a);
	while (current_chunk <= chunks)
	{
		iter_on_a(&a, &b, current_chunk);
		iter_on_b(&a, &b, current_chunk);
		iter_on_a(&a, &b, current_chunk);
		current_chunk++;
	}
	a = get_head(a);
	b = get_head(b);
	while (b)
		pa(&b, &a);
}

static	void	debug__iter_on_a(t_stack **a, t_stack **b, int current_chunk)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = get_head(*a);
	tmp_b = get_head(*b);
	while (tmp_a)
	{
		if (tmp_a->chunk == current_chunk)
		{
			ft_printf("%d chunk in A: now checking for %d in A\n",
				tmp_a->chunk, tmp_a->value);
			print_stack(*a, "start of A:\t");
			print_stack(*b, "start of B:\t");
			move_to_stack_b(&tmp_a, &tmp_b);
			tmp_a = get_head(tmp_a);
			tmp_b = get_head(tmp_b);
			print_stack(*a, "result of A:\t");
			print_stack(*b, "result of B:\t");
			ft_printf("\n---------------------------------\n\n");
		}
		else if (tmp_a->next)
			tmp_a = tmp_a->next;
		else
			break ;
		*a = get_head(tmp_a);
		*b = get_head(tmp_b);
	}
}

static void	debug__iter_on_b(t_stack **a, t_stack **b, int current_chunk)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = get_head(*a);
	tmp_b = get_head(*b);
	while (tmp_b)
	{
		if (!((is_greater_than(tmp_b, 0) && is_smaller_than(tmp_b, 0))
				|| tmp_b->chunk != current_chunk))
		{
			ft_printf("%d chunk in B: now checking for %d in B\n",
				tmp_b->chunk, tmp_b->value);
			print_stack(*a, "start of A:\t");
			print_stack(*b, "start of B:\t");
			reverse_order_chunk_in_b(&tmp_a, &tmp_b);
			tmp_b = get_head(tmp_b);
			tmp_a = get_head(tmp_a);
			print_stack(*a, "result of A:\t");
			print_stack(*b, "result of B:\t");
			ft_printf("\n---------------------------------\n\n");
		}
		else if (tmp_b->next)
			tmp_b = tmp_b->next;
		else
			break ;
		*b = get_head(tmp_b);
		*a = get_head(tmp_a);
	}
}

void	debug__chunk_quicksort(t_stack **stack_a, int chunks)
{
	int		current_chunk;
	t_stack	*a;
	t_stack	*b;

	current_chunk = 0;
	b = NULL;
	get_chunks(*stack_a, chunks);
	a = get_head(*stack_a);
	while (current_chunk <= chunks)
	{
		ft_printf("chunk %d out of %d chunks\n\n", current_chunk, chunks);
		debug__iter_on_a(&a, &b, current_chunk);
		debug__iter_on_b(&a, &b, current_chunk);
		debug__iter_on_a(&a, &b, current_chunk);
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
