/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:25:34 by rloos             #+#    #+#             */
/*   Updated: 2022/10/25 12:25:37 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t bytes, size_t size)
{
	void	*kellogg;

	if (bytes > 4294967295 || size > 4294967295)
		return (0);
	kellogg = malloc(bytes * size);
	if (kellogg == NULL)
		return (NULL);
	ft_bzero(kellogg, size * bytes);
	return (kellogg);
}

/* 
int	main(int argc, const char *argv[])
{
	char	*str;

	alarm(TIMEOUT);
	if (argc == 1)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		str = (char *)ft_calloc(30, 1);
		if (!str)
			write(1, "NULL", 4);
		else
			write(1, str, 30);
	}
	return (0);
}
 */