/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:13:33 by nosman            #+#    #+#             */
/*   Updated: 2024/06/01 13:13:35 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s == NULL || !*s)
		s = "(null)";
	while (s[i])
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

void	ft_print_arr(char **arr)
{
	int	i;

	i = 0;
	ft_printf("\e[90marr = [");
	while (arr[i])
	{
		if (i != 0)
			ft_printf(", ");
		ft_printf("{%s}", arr[i]);
		i++;
	}
	ft_printf("]\e[0m\n");
}

void	ft_print_intarr(int *arr, size_t arr_size)
{
	size_t	i;

	i = 0;
	if (!arr || arr_size == 0)
		return ;
	ft_printf("\e[34marr = [");
	while (i < arr_size)
	{
		if (i != 0)
			ft_printf(", ");
		ft_printf("{%d}", arr[i]);
		i++;
	}
	ft_printf("]\e[0m\n");
}
