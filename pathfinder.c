
#include "solong.h"


typedef struct s_path
{
	int x;
	int y;
}	t_path;


void	flood_fill(char **map, t_map maze, t_path path, int *counter)
{
	if(path.y < 0 || path.y >= maze.m_height || path.x < 0 || path.x >= maze.m_length || (map[path.y][path.x] != '0' && map[path.y][path.x] != 'C' && map[path.y][path.x] != 'E' && map[path.y][path.x] != 'P'))
	{
		return;
	}
	if(map[path.y][path.x] == 'C' || map[path.y][path.x] == 'E')
	{
		(*counter)++;
	}
	map[path.y][path.x] = '.';
	flood_fill(map, maze, (t_path){path.x - 1, path.y}, counter);
	flood_fill(map, maze, (t_path){path.x + 1, path.y}, counter);
	flood_fill(map, maze, (t_path){path.x, path.y - 1}, counter);
	flood_fill(map, maze, (t_path){path.x, path.y + 1}, counter);
}


int		pathfinder(t_map any_struct)
{
	t_path s_path;
	s_path.x = any_struct.x_pos;
	s_path.y = any_struct.y_pos;
	int cnt;

	cnt = 0;
	flood_fill(any_struct.map, any_struct, s_path, &cnt);

	if(cnt != (any_struct.e_cnt + any_struct.c_cnt))
	{
		printf("\nnot playable \n");
	}
	return(cnt);
}
