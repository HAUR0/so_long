/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:14:08 by rloos             #+#    #+#             */
/*   Updated: 2022/10/25 16:19:50 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		dst = malloc(ft_strlen(s) - start + 1);
	else
		dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* 
int	main(void)
{
	char	*dest;

	dest = ft_substr("Hola Mundo", 0, 3);
	printf("%s", dest);
}
 */