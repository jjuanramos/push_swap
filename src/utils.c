/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:28:38 by juramos           #+#    #+#             */
/*   Updated: 2024/02/12 17:22:24 by juramos          ###   ########.fr       */
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

	t = get_head(stck);
	ft_printf("%s", pre);
	ft_printf("|");
	while (t)
	{
		ft_printf(" %d |", t->value);
		t = t->next;
	}
	ft_printf("\n");
}
