/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:22:14 by rloos             #+#    #+#             */
/*   Updated: 2022/10/04 13:22:18 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", isprint(' '));
	printf("%d\n", ft_isprint(' '));
}
*/
