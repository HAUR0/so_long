/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:18:16 by rloos             #+#    #+#             */
/*   Updated: 2022/10/25 15:21:10 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*var;

	i = 0;
	if (!s)
		return (NULL);
	var = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!var)
		return (NULL);
	while (s[i])
	{
		var[i] = f(i, s[i]);
		i++;
	}
	var[i] = '\0';
	return (var);
}
