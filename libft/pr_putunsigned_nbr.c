/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putunsigned_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:32:30 by rloos             #+#    #+#             */
/*   Updated: 2022/11/15 16:32:33 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pr_putunsigned_nbr(unsigned int e, int cnt)
{
	if (e > 9)
	{
		cnt = pr_putunsigned_nbr(e / 10, cnt);
		cnt = pr_putunsigned_nbr(e % 10, cnt);
	}
	if (e <= 9)
	{
		e = e + '0';
		cnt = pr_putchar(e, cnt);
	}
	return (cnt);
}
