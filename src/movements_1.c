/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:36:04 by juramos           #+#    #+#             */
/*   Updated: 2024/02/13 10:55:24 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* TODO:
	we have to make sure that, when any of the stacks becomes empty
	(check if only stack B can get empty), we free it. This way,
	we can make sure to check the right size.
*/
t_stack	*pa(t_stack *stack_b, t_stack *stack_a)
{
	t_stack	*head_b;
	t_stack	*head_a;
	t_stack	*new_head_a;

	if (get_stack_size(stack_b) != 0)
	{
		head_b = get_head(stack_b);
		new_head_a = init_stack_on_value(head_b->value);
		head_a = get_head(stack_a);
		head_a->prev = new_head_a;
		new_head_a->next = head_a;
		if (head_b->next)
		{
			stack_b = head_b->next;
			stack_b->prev = NULL;
		}
		ft_printf("pa\n");
	}
	return (stack_b);
}

t_stack	*pb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;

	if (get_stack_size(stack_a) != 0)
	{
		head_a = get_head(stack_a);
		if (get_stack_size(stack_b) == 0)
		{
			head_b = init_stack_on_value(head_a->value);
			head_a = head_a->next;
			head_a->prev = NULL;
		}
		else
		{
			head_b = get_head(stack_b);
			head_b->prev = head_a;
			(head_a->next)->prev = NULL;
			head_a->next = head_b;
		}
	}
	ft_printf("pb\n");
	return (head_b);
}

void	sa(t_stack	*stack_a)
{
	t_stack	*old_head;
	t_stack	*new_head;

	old_head = get_head(stack_a);
	new_head = old_head->next;
	old_head->next = new_head->next;
	(old_head->next)->prev = old_head;
	new_head->next = old_head;
	old_head->prev = new_head;
	new_head->prev = NULL;
	ft_printf("sa\n");
}

void	sb(t_stack	*stack_b)
{
	t_stack	*old_head;
	t_stack	*new_head;

	old_head = get_head(stack_b);
	new_head = old_head->next;
	old_head->next = new_head->next;
	(old_head->next)->prev = old_head;
	new_head->next = old_head;
	old_head->prev = new_head;
	new_head->prev = NULL;
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
