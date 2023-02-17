
#include "solong.h"
#include "so_long.h"

void	free_2d_array(char **str)
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

void	safe_exit(int error, int *array)
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
		free(array);
		ft_printf("Error\n");
		exit(1);
	}
	else if (error == 3)
		free(array);
	else if (error == 4)
	{
		free(array);
		exit(1);
	}
}

void	safe_exit_2d(int error, char **array)
{
	if(error == 1)
	{
		free_2d_array(array);
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

void	store_in_array(char *file_name, t_map *map)
{
	int i;
	int fd;

	fd = open(file_name, O_RDONLY);
	map->array = ft_calloc (map->line_count + 1, sizeof(char*));
	i = 0;
	while (i != map->line_count)
	{
		map->array[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return ;
}

int		line_length(char **array)
{
	int i;

	i = 0;
	while((array[0][i] != '\0') && (array[0][i] != '\n'))
		i++;
	return (i);
}

void	check_map_line_length(t_map *map)
{
	int i;
	int x;

	i = 0;
	x = 0;
	map->line_length = line_length(map->array);
	while (map->array && map->array[x])
	{
		i = 0;
		while((map->array[x][i] != '\0') && (map->array[x][i] != '\n'))
			i++;
		if(map->line_length != i)
			safe_exit_2d(1, map->array);//use: struct: map->array ???
		x++;
	}
} 

void	check_map_x_walls(t_map *map)
{
	int i;
	int x;
	int tmp;

	i = 0;
	x = 0;
	tmp = map->line_length * 2;
	while(map->array && map->array[0][i] == '1')
		i++;
	while(map->array && map->array[map->line_count-1][x] == '1')
		x++;
	if(i+x != tmp)
		printf("wong X= %d\n", map->valid);
}

void	check_map_y_walls(t_map *map)
{
	int i;
	int x;
	int tmp;

	i = 0;
	x = 0;
	tmp = 0;
	while(tmp < map->line_count)
	{
		if (map->array[tmp][0] == '1')
			i++;
		if (map->array[tmp][map->line_length-1] == '1')
			x++;
		tmp++;
	}
	tmp = map->line_count * 2;
	if(i+x != tmp)
		printf("wong Y= %d\n", map->valid);
}


int	main(int ac, char **av)
{
	t_map map;

	if (ac != 2)
		perror("invalid input"); //return (1);

	map.line_count = map_row_count(av[1]);
	//printf("lines = %d\n", map.line_count);

	store_in_array(av[1], &map);
	//ft_two_d_array_printer(map.array);

	check_map_line_length(&map);//<-change/store value in fnc:"line_length"???
	check_map_x_walls(&map);
	check_map_y_walls(&map);

	printf("x = %d\n", map.line_length);
	printf("y = %d\n", map.line_count);
	free_2d_array(map.array);
	return (0);
}
