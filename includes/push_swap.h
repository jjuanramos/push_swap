/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:35:27 by juramos           #+#    #+#             */
/*   Updated: 2024/02/11 16:07:22 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define LEN_MAX_INT 10

# include "include/ft_printf.h"
# include "include/libft.h"
# include <stdlib.h>

typedef struct s_stack {
	struct s_stack	*prev;
	int				value;
	struct s_stack	*next;
	int				size;
}	t_stack;

/* args_parse */
t_stack	*parse_to_stck(int argc, char *argv[]);

/* utils */
void	message_and_exit(char *str, int out, int exit_code);

/* stack */
t_stack	*arr_to_stack(int *arr, int len);
void	print_stack(t_stack	*stck);

/* movements */
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack	**stack_a);
void	sb(t_stack	**stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/* movements_left */
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_b);

/* quicksort */
// void	quicksort(int *stack_a, int *stack_b, int len);
#endif
