/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:35:27 by juramos           #+#    #+#             */
/*   Updated: 2024/02/21 13:14:55 by juramos          ###   ########.fr       */
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
}	t_stack;

/* args_parse */
t_stack	*parse_to_stck(int argc, char *argv[]);

/* utils */
void	message_and_exit(char *str, int out, int exit_code);
void	print_stack(t_stack	*stck, char *pre);
void	clean_stack(t_stack	*stck);

/* stack */
t_stack	*get_head(t_stack *stck);
t_stack	*get_tail(t_stack *stck);
int		get_stack_size(t_stack *stck);
int		get_max_to_right(t_stack *stck);
t_stack	*init_stack_on_value(int val);

/* movements_1 */
t_stack	*pa(t_stack *stack_b, t_stack *stack_a);
t_stack	*pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack	*stack_a);
void	sb(t_stack	*stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/* movements_2 */
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);

/*	order_1 */
int		how_many_smaller(t_stack *stck);
t_stack	*order_a(t_stack *stack_a, t_stack *stack_b);

/*	order_2 */
int		pos_til_max_at_head(t_stack *head);
t_stack	*order(t_stack *stack_a, t_stack *stack_b, int is_a);

/* quicksort */
int		is_greater_than(t_stack *stck, int to_left);
void	quicksort(t_stack *stack_a);

#endif
