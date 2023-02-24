
#include "solong.h"

void	initializer(t_map *s_map)
{
    s_map->line_length = 0;
    s_map->valid = 0;
    s_map->rows = 0;

    s_map->p_cnt = 0;
    s_map->c_cnt = 0;
    s_map->e_cnt = 0;
    s_map->one_cnt = 0;
    s_map->zero_cnt = 0;


}

void	free_2d_map(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	safe_exit(int error, int *map)
{
	if (error == 0)
		exit(0);
	else if (error == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	else if (error == 2)
	{
		free(map);
		ft_printf("Error\n");
		exit(1);
	}
	else if (error == 3)
		free(map);
	else if (error == 4)
	{
		free(map);
		exit(1);
	}
}

void	safe_exit_2d(int error, char **map)
{
	if(error == 1)
	{
		free_2d_map(map);
		ft_printf("Error\n");
		exit(1);
	}
}

int		map_row_count(char *file_name)
{
	int			fd;
	char		*map;
	int 		counter;

	counter = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perror("cant open file");
	map = get_next_line(fd);
	while (map != NULL)
	{
		free(map);
		map = NULL;
		map = get_next_line(fd);
		counter++;
	}
	free(map);
	map = NULL;
	close(fd);
	return (counter);
}

void	store_in_map_s(char *file_name, t_map *s_map)
{
	int i;
	int fd;

	fd = open(file_name, O_RDONLY);
	s_map->map = ft_calloc (s_map->rows + 1, sizeof(char*));
	i = 0;
	while (i != s_map->rows)
	{
		s_map->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return ;
}
/* 
void	store_in_map_v(char *file_name, t_map *s_map)
{
	int i;
	int fd;

	fd = open(file_name, O_RDONLY);
	s_map->valid_map = ft_calloc (s_map->rows + 1, sizeof(char*));
	i = 0;
	while (i != s_map->rows)
	{
		s_map->valid_map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return ;
}
 */
void	check_map_length(t_map *s_map)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while((s_map->map && s_map->map[0][i] != '\0') && (s_map->map && s_map->map[0][i] != '\n'))
		i++;
	s_map->line_length = i;
	while (s_map->map && s_map->map[x])
	{
		i = 0;
		while((s_map->map[x][i] != '\0') && (s_map->map[x][i] != '\n'))
			i++;
		if(s_map->line_length != i)
			safe_exit_2d(1, s_map->map);
		x++;
	}
} 

void	check_map_x_walls(t_map *s_map)
{
	int i;
	int x;
	int tmp;

	i = 0;
	x = 0;
	tmp = s_map->line_length * 2;
	while(s_map->map && s_map->map[0][i] == '1')
		i++;
	while(s_map->map && s_map->map[s_map->rows-1][x] == '1')
		x++;
	if(i+x != tmp)
	{
		printf("wrong X wall char\n");
		exit(1);
	}
}

void	check_map_y_walls(t_map *s_map)
{
	int i;
	int x;
	int tmp;

	i = 0;
	x = 0;
	tmp = 0;
	while(tmp < s_map->rows)
	{
		if (s_map->map[tmp][0] == '1')
			i++;
		if (s_map->map[tmp][s_map->line_length-1] == '1')
			x++;
		tmp++;
	}
	tmp = s_map->rows * 2;
	if(i+x != tmp)
	{
		printf("wrong Y wall char\n");
		exit(1);
	}
}

void	set_up_p(t_map *s_map, int y, int x)
{
	s_map->x_player_pos = x;
	s_map->y_player_pos = y;
	s_map->p_cnt++;
}

void	count_map_chars(t_map *s_map)
{
	int y;
	int x;

	y = 0;
	while (y < s_map->rows)
	{
		x = 0;
		while (s_map->map && s_map->map[y][x] != '\0')
		{
			if (s_map->map[y][x] == 'P')
				set_up_p(s_map, y, x);
			if (s_map->map[y][x] == 'E')
				s_map->e_cnt++;
			if (s_map->map[y][x] == 'C')
				s_map->c_cnt++;
			if (s_map->map[y][x] == '0')
				s_map->zero_cnt++;
			if (s_map->map[y][x] == '1')
				s_map->one_cnt++;
			x++;
		}
		y++;
	}
	//printf("P counter = %d\n", s_map->p_cnt);
}

void	check_map_valid_chars(t_map *s_map)
{
	int i;
	int x;

	x = 0;
	i = s_map->c_cnt + s_map->p_cnt + s_map->e_cnt + s_map->one_cnt + s_map->zero_cnt;
	//printf("total chars: %i\n", i);
	printf("P: %i\n", s_map->p_cnt);
	printf("E: %i\n", s_map->e_cnt);

	x = s_map->line_length * s_map->rows;
	//printf("total chars (multiplied): %i\n", x);

	if (s_map->p_cnt != 1 || s_map->e_cnt != 1 || s_map->c_cnt < 1)
	{
		printf("invalid amount of P, E or C\n");
		exit(1);
	}
	if (i != x)
	{
		printf("invalid map content\n");
		exit(1);
	}
}


int	main(int ac, char **av)
{
	t_map s_map;
	initializer(&s_map);

	if (ac != 2)
		perror("invalid input");

	s_map.rows = map_row_count(av[1]); //printf("lines = %d\n", s_map.rows);

	store_in_map_s(av[1], &s_map); //ft_two_d_array_printer(s_map.map);
	//store_in_map_v(av[1], &s_map); //ft_two_d_array_printer(s_map.valid_map);


	check_map_length(&s_map);
	check_map_x_walls(&s_map);
	check_map_y_walls(&s_map);
	count_map_chars(&s_map);
	check_map_valid_chars(&s_map);

	//pathfinder(&s_map);
	
	printf("x = %d\n", s_map.line_length);
	printf("y = %d\n", s_map.rows);
	free_2d_map(s_map.map);
	return (0);
}