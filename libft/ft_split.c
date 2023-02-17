/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:05:33 by rloos             #+#    #+#             */
/*   Updated: 2022/10/31 10:06:18 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			cnt++;
			while (str[i] != c)
			{
				i++;
				if (str[i] == '\0')
					return (cnt);
			}
		}
		i++;
	}
	return (cnt);
}

static int	word_length(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			cnt++;
			i++;
		}
		return (cnt);
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**arr;

	i = 0;
	x = 0;
	arr = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (!arr)
		return (NULL);
	while (x < word_cnt(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		arr[x] = ft_substr(s, i, word_length(&s[i], c));
		i = i + word_length(&s[i], c);
		x++;
	}
	arr[word_cnt(s, c)] = NULL;
	return (arr);
}

/* 
int	main(void)
{
	const char	*s;
	char		c;
	int			i;
	char		**str;

	s = "55 223";
	c = '2';
	i = 0;
	str = ft_split(s, c);
	while (i < word_cnt(s, c))
	{
		printf("%s\n", str[i]);
		i++;
	}
	i = 0;
	while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
	return (0);
}
 */