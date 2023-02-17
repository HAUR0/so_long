/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:34:40 by rloos             #+#    #+#             */
/*   Updated: 2022/11/15 16:34:43 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_write(unsigned long long dingdong, int cnt)
{
	if (!dingdong)
	{
		cnt = pr_putstr("(nil)", cnt);
		return (cnt);
	}
	cnt = pr_putstr("0x", cnt);
	cnt = pr_pointer(dingdong, cnt);
	return (cnt);
}
