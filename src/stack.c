/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:27:52 by juramos           #+#    #+#             */
/*   Updated: 2024/02/13 14:40:48 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_head(t_stack *stck)
{
	t_stack	*head;

	if (!stck)
		return (NULL);
	head = stck;
	while (head->prev)
		head = head->prev;
	return (head);
}

t_stack	*get_tail(t_stack *stck)
{
	t_stack	*tail;

	if (!stck)
		return (NULL);
	tail = stck;
	while (tail->next)
		tail = tail->next;
	return (tail);
}

int	get_stack_size(t_stack *stck)
{
	int		n;
	t_stack	*t;

	t = stck;
	n = 0;
	while (t)
	{
		n++;
		t = t->next;
	}
	return (n);
}

t_stack	*init_stack_on_value(int val)
{
	t_stack	*stck;

	stck = ft_calloc(1, sizeof(t_stack));
	if (!stck)
		message_and_exit("Exit\n", 2, 1);
	stck->prev = NULL;
	stck->value = val;
	stck->next = NULL;
	return (stck);
}

int	get_max_to_right(t_stack *stck)
{
	int		max;
	t_stack	*t;

	t = stck;
	max = t->value;
	while (t->next)
	{
		t = t->next;
		if (t->value > max)
			max = t->value;
	}
	return (max);
}
