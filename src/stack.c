/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:27:52 by juramos           #+#    #+#             */
/*   Updated: 2024/02/11 16:46:58 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_head(t_stack *stck)
{
	t_stack	*head;

	head = stck;
	while (head->prev)
		head = head->prev;
	return (head);
}

t_stack	*get_tail(t_stack *stck)
{
	t_stack	*tail;

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

t_stack	*arr_to_stack(int *arr, int len)
{
	t_stack	*stck;
	t_stack	*tmp;
	int		pos;

	stck = init_stack_on_value(arr[0]);
	pos = 0;
	while (++pos < len)
	{
		tmp = init_stack_on_value(arr[pos]);
		stck->next = tmp;
		tmp->prev = stck;
		stck = tmp;
	}
	return (stck);
}
