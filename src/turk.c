/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:33 by juramos           #+#    #+#             */
/*   Updated: 2024/02/28 12:14:57 by juramos          ###   ########.fr       */
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

	while (stck->value != get_head(stck)->value)
	{
		head = get_head(stck);
		if ((head->next) && (head->next)->value == stck->value)
			sb(stck);
		else if (pos_til_head(stck) < get_stack_size(head) / 2)
			rb(stck);
		else
			rrb(stck);
		(*mvmts)++;
	}
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
		mvmts += 1;
	}
	else
	{
		closest_min = get_closest_min(a->value, max_b);
		mvmts_to_head(closest_min, &mvmts);
		mvmts_to_head(tmp_a, &mvmts);
		mvmts += 1;
	}
	return (mvmts);
}

void	move_to_head_b(t_stack **stck)
{
	t_stack	*head;

	head = get_head(*stck);
	while ((*stck)->value != get_head(head)->value)
	{
		if ((head->next) && (head->next)->value == (*stck)->value)
			sb(head);
		else if (pos_til_head(*stck) < get_stack_size(head) / 2)
			rb(head);
		else
			rrb(head);
		head = get_head(head);
	}
	*stck = head;
}

void	move_to_head_a(t_stack **stck)
{
	t_stack	*head;

	head = get_head(*stck);
	while ((*stck)->value != get_head(head)->value)
	{
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
	max_b = get_max_to_right(*b);
	if ((*a)-> value < get_min_to_right(*b)->value || (*a)->value > max_b->value)
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

void	turk_order(t_stack **a, t_stack **b)
{
	t_stack	*pivot_a;
	t_stack	*tmp_b;

	ft_printf("we got into turk");
	pivot_a = get_min_pivot(*a, *b);
	tmp_b = *b;
	exec_mvmts(&pivot_a, &tmp_b);
	*a = get_head(pivot_a);
	*b = get_head(tmp_b);
}

void	turk(t_stack *stack_a)
{
	t_stack	*a;
	t_stack	*b;

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
	{
		print_stack(a, "A looking like this: ");
		print_stack(b, "B looking like this: ");
		turk_order(&a, &b);
		print_stack(a, "A looking like this after: ");
		print_stack(b, "B looking like this after: ");
	}
	exit(0);
	check_three(a);
	// while (b)
	// 	turk_order_reversed(&a, &b);
}
