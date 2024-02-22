/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:10:40 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 10:11:08 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
