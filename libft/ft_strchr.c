/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:06:49 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:42:51 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int nbr_char)
{
	unsigned int	i;

	i = 0;
	if (nbr_char == '\0')
		return ((char *)(&str[ft_strlen(str)]));
	while (str[i])
	{
		if (str[i] == (char)nbr_char)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

/* 
int	main(void)
{
	int	tes[30];

	//char	tnt[30] = "bonjour";
	tes[30] = 'o';
	printf("mine: %s", ft_strchr("bonjour", 106));
	printf("\n");
	//char	tnt2[30] = "bonjour";
	//int		test2[30] = 'o';
	printf("%s", strchr("bonjour", 106));
}
 */