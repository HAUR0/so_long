/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:45:02 by rloos             #+#    #+#             */
/*   Updated: 2022/10/11 12:17:07 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n--)
	{
		if (*(char *)(str + i) == (char)c)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}

/*
int main () 
{
   const char str[] = "Hello";
   const char ch = '.';
   char *ret;

   ret = ft_memchr(str, ch, strlen(str));

   printf("String after |%c| is - %s\n", ch, ret);

   return(0);
}
*/
