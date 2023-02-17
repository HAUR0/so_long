/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:34:36 by rloos             #+#    #+#             */
/*   Updated: 2023/02/15 17:27:52 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] != '\0')
		cnt++;
	return (cnt);
}

/*
int	main(void)
{
	char tnt[] = "Dynamite";	
	
	printf("%ld", strlen(tnt));
	printf("\n%ld", ft_strlen(tnt));
}
*/