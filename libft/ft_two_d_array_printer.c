/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_d_array_printer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:02:01 by rloos             #+#    #+#             */
/*   Updated: 2023/02/16 13:03:23 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_two_d_array_printer(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		ft_printf("%s", array[i]);
		i++;
	}
	ft_printf("\n");
}
