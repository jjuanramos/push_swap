/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:27:52 by juramos           #+#    #+#             */
/*   Updated: 2024/02/11 16:20:53 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stck_add_back(t_stack **stck, int val)
{
	t_stack	*t;

	t = ft_calloc(1, sizeof(t_stack));
	if (!t)
		message_and_exit("Exit\n", 2, 1);
	t->prev = *stck;
	t->value = val;
	t->next = NULL;
	t->size = (*stck)->size;
	(*stck)->next = t;
}

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

t_stack	*arr_to_stack(int *arr, int len)
{
	t_stack	*stck;
	int		pos;

	stck = ft_calloc(1, sizeof(t_stack));
	if (!stck)
		message_and_exit("Exit\n", 2, 1);
	stck->prev = NULL;
	stck->value = arr[0];
	stck->size = len;
	pos = 0;
	while (++pos < len)
	{
		stck_add_back(&stck, arr[pos]);
		stck = stck->next;
	}
	return (stck);
}

void	print_stack(t_stack	*stck)
{
	t_stack	*t;

	t = get_head(stck);
	while (t)
	{
		ft_printf("%d ", t->value);
		t = t->next;
	}
	ft_printf("\n");
}
