/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:28:38 by juramos           #+#    #+#             */
/*   Updated: 2024/02/21 10:30:28 by juramos          ###   ########.fr       */
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
