/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:00 by juramos           #+#    #+#             */
/*   Updated: 2024/02/06 12:18:48 by juramos          ###   ########.fr       */
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

int	*convert_to_arr(int argc, char	*argv[])
{
	int	*arr;
	int	argv_pos;

	arr = ft_calloc(argc, sizeof(int));
	if (!arr)
	{
		ft_printf("Error\n");
		exit(1);
	}
	argv_pos = 0;
	while (argv[++argv_pos])
	{
		if (is_str_digit(argv[argv_pos]))
			arr[argv_pos - 1] = ft_atoi(argv[argv_pos]);
		else
		{
			ft_printf("Error\n");
			free(arr);
			exit(1);
		}
	}
	return (arr);
}

void	print_arr(int *arr)
{
	int	pos;

	pos = 0;
	while (arr[pos])
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
		ft_printf("Error\n");
		exit(1);
	}
	/* TODO:
		We must assign a dynamically sized array of ints, whose size
		depends on the number of arguments passed to the executable.
		- atoi for each string.
			- error and exit if isdigit fails for any of the characters of each string passed.
		- we can use argc to attribute a calloc size of that value to our array. (actual size is
		argc - 1, but we want to leave an space for a \0)

	*/
	else
	{
		arr = convert_to_arr(argc, argv);
		print_arr(arr);
		if (!arr)
		// there is a function to be created, message_and_exit or smth like that
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	atexit(leaks);
	return (0);
}
