/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:09:17 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:42:12 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		x;
	char	*dst;

	i = 0;
	x = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (x > i && ft_strchr(set, s1[x - 1]))
	{
		x--;
	}
	dst = ft_substr(s1, i, (x - i));
	return (dst);
}

/* 
char	*ft_strtrim(char *str, char rem)
{
    char    *res;
    int        j;
    int        i;

    i = 0;
    j = 0;
    if (!str || !str[0] || str == NULL)
    {
        return (NULL);
    }
    while (str[i] != rem && str[i] != '\0')
        i++;
    if (str[i] == rem)
        i++;
    res = (char *)malloc(sizeof(char) * i + 1);
    if (!res)
        return (NULL);
    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        res[j++] = str[i++];
    if (str[i] == rem)
        res[j++] = '\n';
    res[j] = '\0';
    return (res);
}
 */

/* int	main(void)
{
	char *s1;
	char *set;

	s1 = "Hello Please Trim me !";
	set = "P";

	printf("%s", ft_strtrim(s1, set));
} */