/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:35:27 by juramos           #+#    #+#             */
/*   Updated: 2024/02/11 12:10:49 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define LEN_MAX_INT 10

# include "include/ft_printf.h"
# include "include/libft.h"
# include <stdlib.h>

typedef struct s_stack {
	struct s_stack	*head;
	struct s_stack	*prev;
	int				value;
	struct s_stack	*next;
	struct s_stack	*tail;
	int				size;
}	t_stack;

int		*convert_to_arr(int argc, char *argv[]);
void	message_and_exit(char *str, int out, int exit_code);
// void	quicksort(int *stack_a, int *stack_b, int len);
#endif
