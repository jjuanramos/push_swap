/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:36:04 by juramos           #+#    #+#             */
/*   Updated: 2024/03/01 12:58:30 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* TODO:
	we have to make sure that, when any of the stacks becomes empty
	(check if only stack B can get empty), we free it. This way,
	we can make sure to check the right size.
*/
void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*head_b;
	t_stack	*head_a;

	head_a = get_head(*stack_a);
	head_b = get_head(*stack_b);
	if (get_stack_size(*stack_b) != 0)
	{
		*stack_a = head_b;
		if (head_b->next)
		{
			*stack_b = head_b->next;
			(*stack_b)->prev = NULL;
		}
		else
			*stack_b = NULL;
		if (head_a)
		{
			(*stack_a)->next = head_a;
			head_a->prev = *stack_a;
		}
		else
			(*stack_a)->next = NULL;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = get_head(*stack_a);
	head_b = get_head(*stack_b);
	if (get_stack_size(*stack_a) != 0)
	{
		*stack_b = head_a;
		if (head_a->next)
		{
			*stack_a = head_a->next;
			(*stack_a)->prev = NULL;
		}
		else
			*stack_a = NULL;
		if (head_b)
		{
			(*stack_b)->next = head_b;
			head_b->prev = *stack_b;
		}
		else
			(*stack_b)->next = NULL;
	}
}

void	sa(t_stack	*stack_a)
{
	t_stack	*old_head;
	t_stack	*new_head;

	old_head = get_head(stack_a);
	new_head = old_head->next;
	old_head->next = new_head->next;
	if (new_head->next)
		(new_head->next)->prev = old_head;
	new_head->next = old_head;
	old_head->prev = new_head;
	new_head->prev = NULL;
}

void	sb(t_stack	*stack_b)
{
	t_stack	*old_head;
	t_stack	*new_head;

	old_head = get_head(stack_b);
	new_head = old_head->next;
	old_head->next = new_head->next;
	if (new_head->next)
		(new_head->next)->prev = old_head;
	new_head->next = old_head;
	old_head->prev = new_head;
	new_head->prev = NULL;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
