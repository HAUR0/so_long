/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:40:51 by rloos             #+#    #+#             */
/*   Updated: 2022/10/04 17:00:04 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tnt;

	tnt = s;
	while (n--)
	{
		*tnt = '\0';
		tnt++;
	}
}

/*
int	main(void)
{
	char	tnt[];
	char	tnt2[];

	
	tnt[] = "dynamite is dangerous";
	
	ft_bzero(tnt + 5, 3);
	printf("%s\n", tnt);
	
	tnt2[] = "dynamite is dangerous";
	
	bzero(tnt2 + 2, 1);
	printf("%s", tnt2);
	//printf("%s", tnt2 + 9);
}
 */
