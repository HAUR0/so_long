/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:05:52 by rloos             #+#    #+#             */
/*   Updated: 2022/09/21 14:06:48 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	multi;
	int	res;

	i = 0;
	multi = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			multi *= -1;
		}
		i++;
	}
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * multi);
}

/*  
int	main(void)
{
	char	string[];

	
	string[] = "   --+-+1234ab567";
	printf("%i", ft_atoi(string));
	printf("\n");
	printf("%i", atoi(string));
	return(0);
}
 */
