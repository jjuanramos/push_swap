/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:35:27 by juramos           #+#    #+#             */
/*   Updated: 2024/02/22 11:06:59 by juramos          ###   ########.fr       */
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
	int				chunk;
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
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack	*stack_a);
void	sb(t_stack	*stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/* movements_2 */
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);

/*	small_order_1 */
int		how_many_smaller(t_stack *stck);
void	order_a(t_stack **stack_a, t_stack **stack_b);

/*	small_order_2 */
int		pos_til_max_at_head(t_stack *head);
void	order(t_stack **stack_a, t_stack **stack_b, int is_a);

/*	chunk_order	*/
int		distance_to_head(t_stack *stck);
void	move_to_stack_b(t_stack **a, t_stack **b);
void	check_three_reversed(t_stack *stck);
void	reverse_order_chunk_in_b(t_stack **head_a, t_stack **b);
void	get_chunks(t_stack *stck, int chunks);

/*	chunk_quicksort	*/
void	chunk_quicksort(t_stack **stack_a, int chunks);
void	debug__chunk_quicksort(t_stack **stack_a, int chunks);

/* quicksort */
int		is_greater_than(t_stack *stck, int to_left);
int		is_smaller_than(t_stack *stck, int to_right);
void	quicksort(t_stack *stack_a);
void	debug_quicksort(t_stack *stack_a);

#endif
