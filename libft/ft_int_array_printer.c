/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_array_printer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:57:06 by rloos             #+#    #+#             */
/*   Updated: 2023/02/16 12:59:00 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_array_printer(int *arr, int *size_a)
{
	int	i;

	i = 0;
	if (arr[0] == 0)
	{
		ft_printf("Array[0] = 0\n");
		i = 1;
	}
	while (i < *size_a)
	{
		ft_printf("Array[%i] = %d\n", i, arr[i]);
		i++;
	}
}
