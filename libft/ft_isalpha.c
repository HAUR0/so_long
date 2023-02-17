/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:53:44 by rloos             #+#    #+#             */
/*   Updated: 2022/10/03 15:54:00 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int argument)
{
	if ((argument >= 'A' && argument <= 'Z') || (argument >= 'a'
			&& argument <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", isalpha(0));
	printf("%d\n", ft_isalpha(0));
}
*/
