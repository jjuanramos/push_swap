/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:35:27 by juramos           #+#    #+#             */
/*   Updated: 2024/03/04 13:33:45 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define LEN_MAX_INT 10

/*  movements	*/
# define PA 1
# define RA 2
# define RRA 3
# define PB 4
# define RB 5
# define RRB 6

# include "include/ft_printf.h"
# include "include/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				value;
	struct s_stack	*next;
	int				chunk;
}	t_stack;

/* args_parse */
t_stack	*parse_to_stck(int argc, char *argv[]);

/* utils_1 */
void	message_and_exit(char *str, int out, int exit_code);
void	print_stack(t_stack	*stck, char *pre);
void	clean_stack(t_stack	*stck);
int		is_greater_than(t_stack *stck, int to_left);
int		is_smaller_than(t_stack *stck, int to_right);

/*	utils_2 */
int		get_int_arr_len(int *mvmts);
t_stack	*get_closest_greater(t_stack *ref, t_stack *stack_a);
t_stack	*get_closest_min(t_stack *ref, t_stack *stck);
void	print_int_arr(int *mvmts);

/*	utils_3 */
int		pos_til_head(t_stack *stck, int n);

/* stack_1 */
t_stack	*get_head(t_stack *stck);
t_stack	*get_tail(t_stack *stck);
int		get_stack_size(t_stack *stck);
t_stack	*init_stack_on_value(int val);
t_stack	*copy_stck(t_stack	*stck);

/*	stack_2 */
t_stack	*get_min_to_right(t_stack *stck);
t_stack	*get_max_to_right(t_stack *stck);
void	check_three(t_stack *stack_a);

/*	simulators */
int		*simulate_mvmts_a(t_stack *stck);
int		*simulate_mvmts_b(t_stack *stck);
int		*concat_mvmts(int *mvmts_1, int *mvmts_2, int to_a);

/*	executors */
void	exec_mvmts(t_stack **pivot, t_stack **b, int *pivot_mvmts);

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

/*	movements	*/
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* push_swap */
void	push_swap(t_stack **stack_a);

/*	debug_turk	*/
void	debug_turk(t_stack *stack_a);

/*	debug_push_swap */
void	debug_push_swap(t_stack **stack_a);

/*	send_to_b */
void	send_to_b(t_stack **stack_a, t_stack **stack_b);

/*	send_to_a */
void	send_to_a(t_stack **stack_a, t_stack **stack_b);

#endif
