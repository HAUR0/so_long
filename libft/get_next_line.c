/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:22:23 by rloos             #+#    #+#             */
/*   Updated: 2023/02/15 17:55:57 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd = 1;
	while (!get_strchr(left_str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		left_str = get_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = get_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = get_line(left_str);
	left_str = get_new_left_str(left_str);
	return (line);
}
/* 
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	
	fd1 = open("test.txt", O_RDONLY);
	
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
 */
/*
int	main(void)
{
	int			count = 4;
	static int	x;
	int			fd;
	char		*willy;
	int			i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	if(fd == -1)
		ft_printf("Error\n");
	while (i < count)
	{
		willy = get_next_line(fd);
		printf("\n%x - Newline: %s", x, willy);
		x++;
		i++;
		free(willy);
		willy = NULL;
	}
	close(fd);
	return (0);
}
*/
