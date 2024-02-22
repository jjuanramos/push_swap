/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:12:29 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 10:33:15 by juramos          ###   ########.fr       */
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
			*a = get_head(tmp_a);
			*b = get_head(tmp_b);
		}
		else if (tmp_a->next)
			tmp_a = tmp_a->next;
		else
			break ;
	}
}

// static void	iter_on_b(t_stack **a, t_stack **b, int current_chunk)
// {
// 	t_stack	*tmp_a;
// 	t_stack	*tmp_b;

// 	tmp_a = get_head(*a);
// 	tmp_b = get_head(*b);
// 	while (tmp_b)
// 	{
// 		if (!((is_greater_than(tmp_b, 0) && is_smaller_than(tmp_b, 0))
// 				|| tmp_b->chunk != current_chunk))
// 		{
// 			reverse_order_chunk_in_b(&tmp_a, &tmp_b);
// 			*b = get_head(tmp_b);
// 			*a = get_head(tmp_a);
// 		}
// 		else if (tmp_b->next)
// 			tmp_b = tmp_b->next;
// 		else
// 			break ;
// 	}
// }

void	order_chunks(t_stack **stack_a, int chunks)
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
		// iter_on_b(&a, &b, current_chunk);
		// iter on B
		a = get_head(a);
		b = get_head(b);
		while (b)
		{
			if (!((is_greater_than(b, 0) && is_smaller_than(b, 0)) || b->chunk != current_chunk))
			{
				reverse_order_chunk_in_b(&a, &b);
				b = get_head(b);
				a = get_head(a);
			}
			else if (b->next)
				b = b->next;
			else
				break ;
		}
		iter_on_a(&a, &b, current_chunk);
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