/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:33:34 by rloos             #+#    #+#             */
/*   Updated: 2022/11/15 16:33:39 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hex_unsigned_len(unsigned long long n)
{
	long long	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	pr_pointer(unsigned long long n, int cnt)
{
	int		remain;
	int		len;
	char	*res;

	len = hex_unsigned_len(n);
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
			res[len] = remain - 10 + 'a';
		else
			res[len] = remain + '0';
	}
	cnt = pr_putstr(res, cnt);
	free(res);
	return (cnt);
}
