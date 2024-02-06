/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:00 by juramos           #+#    #+#             */
/*   Updated: 2024/02/06 13:02:23 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks -q ./push_swap");
}

int	is_str_digit(char *str)
{
	int	pos;

	pos = -1;
	while (str[++pos])
	{
		if (!ft_isdigit(str[pos]))
			return (0);
	}
	return (1);
}

int	is_arg_unique(char *arr[], int pos)
{
	char	*ref;

	ref = arr[pos];
	while (arr[++pos])
	{
		if (ft_strncmp(ref, arr[pos], LEN_MAX_INT) == 0)
			return (0);
	}
	return (1);
}

int	is_eq_or_less_int_max(char *str)
{
	int	val;

	val = ft_atoi(str);
	if ((val < 0 && str[0] != '-')
		|| (ft_strlen(str) != ft_strlen(ft_itoa(val))))
		return (0);
	return (1);
}

int	*convert_to_arr(int argc, char *argv[])
{
	int	*arr;
	int	argv_pos;

	arr = ft_calloc(argc, sizeof(int));
	if (!arr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	argv_pos = 0;
	while (argv[++argv_pos])
	{
		if (is_str_digit(argv[argv_pos]) && is_arg_unique(argv, argv_pos)
			&& is_eq_or_less_int_max(argv[argv_pos]))
			arr[argv_pos - 1] = ft_atoi(argv[argv_pos]);
		else
		{
			ft_putstr_fd("Error\n", 2);
			free(arr);
			exit(1);
		}
	}
	return (arr);
}

void	print_arr(int *arr, int arr_size)
{
	int	pos;

	pos = 0;
	while (pos < arr_size)
	{
		ft_printf("%d ", arr[pos]);
		pos++;
	}
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	int	*arr;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
	{
		arr = convert_to_arr(argc, argv);
		print_arr(arr, argc - 1);
		if (!arr)
		// there is a function to be created, message_and_exit or smth like that
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	atexit(leaks);
	return (0);
}
