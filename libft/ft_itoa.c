/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:18:57 by rloos             #+#    #+#             */
/*   Updated: 2022/10/25 15:32:17 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pnvalue(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*meloc(int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = length(n);
	str = meloc(len);
	if (!str)
		return (NULL);
	str[length(n)] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		len--;
		str[len] = pnvalue(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

/* 
int	main(void)
{
	int	n;

	n = -666;
	printf("MAIN: %s", ft_itoa(n));
}
 */
