/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:51 by rloos             #+#    #+#             */
/*   Updated: 2022/11/08 16:46:54 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_print(const char *str, int cnt, int i, va_list args)
{
	if (str[i] == 'c')
		cnt = pr_putchar(va_arg(args, int), cnt);
	else if (str[i] == 's')
		cnt = pr_putstr(va_arg(args, char *), cnt);
	else if (str[i] == 'p')
		cnt = ptr_write(va_arg(args, unsigned long long), cnt);
	else if (str[i] == 'i' || str[i] == 'd')
		cnt = pr_putnbr(va_arg(args, int), cnt);
	else if (str[i] == 'u')
		cnt = pr_putunsigned_nbr(va_arg(args, int), cnt);
	else if (str[i] == 'x')
		cnt = pr_hexa_lo(va_arg(args, unsigned int), cnt);
	else if (str[i] == 'X')
		cnt = pr_hexa_up(va_arg(args, unsigned int), cnt);
	else if (str[i] == '%')
		cnt = pr_putchar('%', cnt);
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cnt;
	va_list	args;

	va_start(args, str);
	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cnt = if_print(str, cnt, i, args);
		}
		else
			cnt = pr_putchar(str[i], cnt);
		i++;
	}
	va_end(args);
	return (cnt);
}

/* 
int	main(void)
{
	char	x;
	char	*s;
	int		i;

	x = 'Q';
	s = "explicit";
	i = 12;
	ft_printf("%x", 26);
	ft_printf("\n");
	printf("%x", 12);
	return (0);
}
 */