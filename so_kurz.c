
#include "solong.h"
#include "so_long.h"

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

void	store_in_map(char *file_name, t_map *s_map)
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

int		line_length(char **map)
{
	int i;

	i = 0;
	while((map && map[0][i] != '\0') && (map && map[0][i] != '\n'))
		i++;
	return (i);
}

void	check_map_length(t_map *s_map)
{
	int i;
	int x;

	i = 0;
	x = 0;
	s_map->line_length = line_length(s_map->map);
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
		printf("wrong line wall char\n");
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
		printf("wrong row wall char\n");
}

void	count_map_chars(t_map *s_map)
{
	int i;
	int x;

	i = 0;
	s_map->one = 0;
	s_map->zero = 0;
	while (i < s_map->rows)
	{
		x = 0;
		while (s_map->map && s_map->map[i][x] != '\0')
		{
			if (s_map->map[i][x] == 'P')
				s_map->p_layer++;
			if (s_map->map[i][x] == 'E')
				s_map->e_xit++;
			if (s_map->map[i][x] == 'C')
				s_map->c_ollectable++;
			if (s_map->map[i][x] == '0')
				s_map->zero++;
			if (s_map->map[i][x] == '1')
				s_map->one++;
			x++;
		}
		i++;
	}
}

void	check_map_valid_chars(t_map *s_map)
{
	int i;
	int x;

	x = 0;
	i = s_map->c_ollectable + s_map->p_layer + s_map->e_xit + s_map->one + s_map->zero;
	//printf("total chars: %i\n", i);

	x = s_map->line_length * s_map->rows;
	//printf("total chars (multiplied): %i\n", x);

	if (s_map->p_layer != 1 || s_map->c_ollectable != 1)
		exit(1);
	if (i != x)
		exit (1);
}

int	pathfinder(int y, int x, int size, t_map *s_map)
{
	if(y == size-1 && x == size-1)
		return(1);

	if(s_map->map[y][x] == 1)
	{
		
		if (pathfinder(y, x+1, size, s_map->map) == 1) return 1;
		if (pathfinder(y+1, x, size, s_map->map) == 1) return 1;
	}
}

int	main(int ac, char **av)
{
	t_map s_map;

	if (ac != 2)
		perror("invalid input");

	s_map.rows = map_row_count(av[1]);
	//printf("lines = %d\n", map.rows);

	store_in_map(av[1], &s_map);
	//ft_two_d_map_printer(map.map);

	check_map_length(&s_map);//<-change/store value in fnc:"line_length"???
	check_map_x_walls(&s_map);
	check_map_y_walls(&s_map);
	count_map_chars(&s_map);
	check_map_valid_chars(&s_map);

	printf("x = %d\n", s_map.line_length);
	printf("y = %d\n", s_map.rows);
	free_2d_map(s_map.map);
	return (0);
}
