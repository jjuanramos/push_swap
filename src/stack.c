/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:27:52 by juramos           #+#    #+#             */
/*   Updated: 2024/02/11 15:28:44 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stck_add_back(t_stack **stck, int val)
{
	t_stack	*t;

	t = ft_calloc(1, sizeof(t_stack));
	if (!t)
		message_and_exit("Exit\n", 2, 1);
	t->head = (*stck)->head;
	t->prev = *stck;
	t->value = val;
	t->next = NULL;
	t->tail = t;
	t->size = (*stck)->size;
	(*stck)->next = t;
	(*stck)->tail = t;
}

t_stack	*arr_to_stack(int *arr, int len)
{
	t_stack	*stck;
	int		pos;

	stck = ft_calloc(1, sizeof(t_stack));
	if (!stck)
		message_and_exit("Exit\n", 2, 1);
	stck->head = stck;
	stck->prev = NULL;
	stck->value = arr[0];
	stck->tail = stck;
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
	int		pos;

	pos = 0;
	t = stck->head;
	while (pos < t->size)
	{
		ft_printf("%d", t->value);
		if (t->next)
			t = t->next;
		else
			break ;
	}
	ft_printf("\n");
}
