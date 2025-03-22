/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:06:40 by nosman            #+#    #+#             */
/*   Updated: 2024/06/07 09:18:55 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse(int ac, char **av, size_t *arr_sz)
{
	int		i;
	int		*array;
	char	**split_strings;

	i = 0;
	array = NULL;
	while (++i < ac)
	{
		split_strings = ft_string_check(av[i], array);
		if (!split_strings)
		{
			free_arr(split_strings);
			perr (6);
		}
		array = ft_join_array(arr_sz, array, split_strings);
		if ((!array) || (ft_check_doubles(array, *arr_sz) == 1))
		{
			free_arr_int(array);
			perr (8);
		}
	}
	return (array);
}

void	ft_sort(int *array, int array_size, t_stack **list)
{
	t_stack	*temp;

	*list = ft_arr_to_linkedlist(array, array_size);
	temp = *list;
	free_arr_int(array);
	*list = ft_alias(*list, array_size);
	free_list(temp);
	if (sorted(*list))
	{
		free_list(*list);
		return ;
	}
	*list = ft_sort_list(*list);
	free_list(*list);
}

int	main(int ac, char **av)
{
	t_stack	*list;
	int		*array;
	size_t	arr_sz;

	array = NULL;
	arr_sz = 0;
	if (ac < 2)
		return (0);
	if (arg_checker(av) == false)
		perr (2);
	array = parse (ac, av, &arr_sz);
	ft_sort(array, arr_sz, &list);
	return (0);
}
