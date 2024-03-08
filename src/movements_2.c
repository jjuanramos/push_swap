/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:38:39 by juramos           #+#    #+#             */
/*   Updated: 2024/03/08 10:02:05 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_stack	*head;
	t_stack	*tail;

	head = get_head(stack_a);
	tail = get_tail(stack_a);
	tail->next = head;
	head->prev = tail;
	(head->next)->prev = NULL;
	head->next = NULL;
}

void	rb(t_stack *stack_b)
{
	t_stack	*head;
	t_stack	*tail;

	head = get_head(stack_b);
	tail = get_tail(stack_b);
	tail->next = head;
	head->prev = tail;
	(head->next)->prev = NULL;
	head->next = NULL;
}

void	rra(t_stack *stack_a)
{
	t_stack	*head;
	t_stack	*tail;

	head = get_head(stack_a);
	tail = get_tail(stack_a);
	tail->next = head;
	head->prev = tail;
	(tail->prev)->next = NULL;
	tail->prev = NULL;
}

void	rrb(t_stack *stack_b)
{
	t_stack	*head;
	t_stack	*tail;

	head = get_head(stack_b);
	tail = get_tail(stack_b);
	tail->next = head;
	head->prev = tail;
	(tail->prev)->next = NULL;
	tail->prev = NULL;
}
