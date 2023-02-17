/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:35:30 by rloos             #+#    #+#             */
/*   Updated: 2023/02/16 15:19:27 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int nbr_char)
{
	int	len;

	len = ft_strlen(str);
	if ((char)nbr_char == '\0')
		return ((char *)(&str[ft_strlen(str)]));
	while (len >= 0)
	{
		if (str[len] == (char)nbr_char)
		{
			return ((char *)&str[len]);
		}
		len--;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	tnt[];
	int		test;
	char	tnt2[];
	int		test2;

	tnt[] = "abbbbc";
	test = 'b';
	printf("%s", ft_strrchr(tnt, test));
	tnt2[] = "abbbbc";
	test2 = 'b';
	printf("%s", strrchr(tnt2, test2));
}
*/
