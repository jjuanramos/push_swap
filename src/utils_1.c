/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:28:38 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 11:12:17 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message_and_exit(char *str, int out, int exit_code)
{
	ft_putstr_fd(str, out);
	exit(exit_code);
}

void	print_stack(t_stack	*stck, char *pre)
{
	t_stack	*t;

	ft_printf("%s", pre);
	if (!stck || get_stack_size(stck) == 0)
		ft_printf("|\t|\n");
	else
	{
		t = get_head(stck);
		ft_printf("|");
		while (t)
		{
			ft_printf(" %d |", t->value);
			t = t->next;
		}
		ft_printf("\n");
	}
}

void	clean_stack(t_stack	*stck)
{
	t_stack	*t;

	if (stck)
	{
		t = get_head(stck);
		while (t->next)
		{
			t = t->next;
			free(t->prev);
		}
		free(t);
	}
}

int	is_greater_than(t_stack *stck, int to_left)
{
	t_stack	*t;

	t = stck;
	if (to_left)
	{
		while (t->prev)
		{
			if ((t->prev)->value > stck->value)
				return (0);
			t = t->prev;
		}
	}
	else
	{
		while (t->next)
		{
			if ((t->next)->value > stck->value)
				return (0);
			t = t->next;
		}
	}
	return (1);
}

int	is_smaller_than(t_stack *stck, int to_right)
{
	t_stack	*t;

	t = stck;
	if (to_right)
	{
		while (t->next)
		{
			if ((t->next)->value < stck->value)
				return (0);
			t = t->next;
		}
	}
	else
	{
		while (t->prev)
		{
			if ((t->prev)->value < stck->value)
				return (0);
			t = t->prev;
		}
	}
	return (1);
}
