/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:28:38 by juramos           #+#    #+#             */
/*   Updated: 2024/02/07 15:30:30 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message_and_exit(char *str, int out, int exit_code)
{
	ft_putstr_fd(str, out);
	exit(exit_code);
}
