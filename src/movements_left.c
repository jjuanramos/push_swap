/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:38:39 by juramos           #+#    #+#             */
/*   Updated: 2024/02/11 17:37:48 by juramos          ###   ########.fr       */
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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
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
	ft_printf("rrb\n");
}
