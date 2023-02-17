/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_hexa_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:33:55 by rloos             #+#    #+#             */
/*   Updated: 2022/11/15 16:33:58 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	pr_hexa_up(unsigned int n, int cnt)
{
	int		remain;
	int		len;
	char	*res;

	len = hex_len(n);
	if (n == 0)
		cnt = pr_putchar('0', cnt);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (n > 0)
	{
		len--;
		remain = (n % 16);
		n = n / 16;
		if (remain > 9)
			res[len] = remain - 10 + 'A';
		else
			res[len] = remain + '0';
	}
	cnt = pr_putstr(res, cnt);
	free(res);
	return (cnt);
}
