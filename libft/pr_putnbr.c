/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:31:42 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:44:14 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pr_putnbr(int e, int cnt)
{
	if (e == -2147483648)
		cnt = pr_putstr("-2147483648", cnt);
	else if (e < 0)
	{
		cnt = pr_putchar('-', cnt);
		cnt = pr_putnbr(-e, cnt);
	}
	else if (e > 9)
	{
		cnt = pr_putnbr(e / 10, cnt);
		cnt = pr_putnbr(e % 10, cnt);
	}
	else if (e <= 9)
	{
		e = e + '0';
		cnt = pr_putchar(e, cnt);
	}
	return (cnt);
}
