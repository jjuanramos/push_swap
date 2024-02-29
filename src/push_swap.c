/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:33 by juramos           #+#    #+#             */
/*   Updated: 2024/02/29 12:55:47 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_til_head(t_stack *stck)
{
	t_stack	*t;
	int		dist;

	t = stck;
	dist = 0;
	while (t)
	{
		dist++;
		t = t->prev;
	}
	return (dist);
}

void	mvmts_to_head(t_stack *stck, int *mvmts)
{
	t_stack	*head;
	t_stack	*copy;

	copy = copy_stck(stck);
	while (copy->value != get_head(copy)->value)
	{
		head = get_head(copy);
		if ((head->next) && (head->next)->value == copy->value)
			sb(copy);
		else if (pos_til_head(copy) < get_stack_size(head) / 2)
			rb(copy);
		else
			rrb(copy);
		(*mvmts)++;
	}
	clean_stack(copy);
}

t_stack	*get_closest_min(int ref, t_stack *stck)
{
	t_stack	*t;
	t_stack	*closest_min;

	t = get_head(stck);
	closest_min = get_min_to_right(t);
	while (t)
	{
		if (t->value < ref && t->value > closest_min->value)
			closest_min = t;
		t = t->next;
	}
	return (closest_min);
}

int	check_mvmts(t_stack *a, t_stack *b)
{
	t_stack	*max_b;
	t_stack	*closest_min;
	t_stack	*tmp_a;
	int		mvmts;

	tmp_a = a;
	mvmts = 0;
	max_b = get_max_to_right(b);
	if (a->value < get_min_to_right(b)->value || a->value > max_b->value)
	{
		mvmts_to_head(max_b, &mvmts);
		mvmts_to_head(tmp_a, &mvmts);
	}
	else
	{
		closest_min = get_closest_min(a->value, max_b);
		mvmts_to_head(closest_min, &mvmts);
		mvmts_to_head(tmp_a, &mvmts);
	}
	mvmts += 1;
	return (mvmts);
}

void	move_to_head_b(t_stack **stck)
{
	t_stack	*head;

	head = get_head(*stck);
	while ((*stck)->value != get_head(head)->value)
	{
		if (head->value == (*stck)->value)
			break ;
		else if ((head->next) && (head->next)->value == (*stck)->value)
			sb(*stck);
		else if (pos_til_head(*stck) < get_stack_size(head) / 2)
			rb(*stck);
		else
			rrb(*stck);
		head = get_head(*stck);
	}
	*stck = head;
}

void	move_to_head_a(t_stack **stck)
{
	t_stack	*head;

	head = get_head(*stck);
	while ((*stck)->value != get_head(head)->value)
	{
		if (head->value == (*stck)->value)
			break ;
		if ((head->next) && (head->next)->value == (*stck)->value)
			sa(head);
		else if (pos_til_head(*stck) < get_stack_size(head) / 2)
			ra(head);
		else
			rra(head);
		head = get_head(head);
	}
	*stck = head;
}

void	exec_mvmts(t_stack **a, t_stack **b)
{
	t_stack	*max_b;
	t_stack	*closest_min;
	t_stack	*tmp_a;

	tmp_a = *a;
	max_b = get_max_to_right(get_head(*b));
	if ((*a)-> value < get_min_to_right(get_head(*b))->value
		|| (*a)->value > max_b->value)
	{
		move_to_head_b(&max_b);
		move_to_head_a(&tmp_a);
	}
	else
	{
		closest_min = get_closest_min(tmp_a->value, max_b);
		move_to_head_b(&closest_min);
		move_to_head_a(&tmp_a);
	}
	pb(&tmp_a, &max_b);
	*a = get_head(tmp_a);
	*b = get_head(max_b);
}

t_stack	*get_min_pivot(t_stack *a, t_stack *b)
{
	int		min;
	t_stack	*min_pivot;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = a;
	tmp_b = b;
	min = check_mvmts(tmp_a, tmp_b);
	min_pivot = tmp_a;
	if (min <= 2)
		return (min_pivot);
	while (tmp_a)
	{
		if (check_mvmts(tmp_a, tmp_b) < min)
		{
			min = check_mvmts(tmp_a, tmp_b);
			min_pivot = tmp_a;
		}
		tmp_a = a->next;
	}
	return (min_pivot);
}

t_stack	*get_closest_greater(t_stack *ref, t_stack *stack_a)
{
	t_stack	*t;
	t_stack	*closest_greater;

	t = get_head(stack_a);
	closest_greater = get_max_to_right(t);
	if (ref->value > closest_greater->value)
		return (NULL);
	while (t)
	{
		if (t->value > ref->value && t->value < closest_greater->value)
			closest_greater = t;
		t = t->next;
	}
	return (closest_greater);
}

void	turk_order_reversed(t_stack **a, t_stack **b)
{
	t_stack	*closest_greater;
	t_stack	*tmp_a;

	tmp_a = *a;
	closest_greater = get_closest_greater(*b, *a);
	if (closest_greater)
	{
		move_to_head_a(&closest_greater);
		tmp_a = get_head(closest_greater);
	}
	pa(b, &tmp_a);
	*a = get_head(tmp_a);
	*b = get_head(*b);
}

void	turk_order(t_stack **a, t_stack **b)
{
	t_stack	*pivot_a;

	pivot_a = get_min_pivot(*a, *b);
	exec_mvmts(&pivot_a, b);
	*a = pivot_a;
	*b = *b;
}

void	push_swap(t_stack *stack_a)
{
	t_stack	*a;
	t_stack	*b;
	int		iters;

	a = get_head(stack_a);
	b = NULL;
	if (get_stack_size(a) <= 3)
		check_three(a);
	while (get_stack_size(a) > 3 && get_stack_size(b) < 2)
	{
		pb(&a, &b);
		a = get_head(a);
		b = get_head(b);
	}
	while (get_stack_size(a) > 3)
		turk_order(&a, &b);
	iters = -1;
	while (iters++ < 2)
	{
		if (!(is_greater_than(a, 1) && is_smaller_than(a, 1)))
		{
			check_three(a);
			a = get_head(a);
		}
	}
	while (b)
		turk_order_reversed(&a, &b);
	a = get_tail(a);
	while (get_max_to_right(get_head(a))->value != a->value)
	{
		rra(a);
		a = get_tail(a);
	}
}
