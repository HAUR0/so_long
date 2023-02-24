/* 
#include "solong.h"


void	fill(char **valid_map, t_map *s_map, char change)
{
	if(s_map->y < 0 || s_map->y >= s_map->rows || s_map->x < 0 || s_map->x >= s_map->line_length || (valid_map[s_map->y][s_map->x] != change && valid_map[s_map->y][s_map->x] != 'C' && valid_map[s_map->y][s_map->x] != 'E'))
	{
		return;
	}
	if(valid_map[s_map->y][s_map->x] == 'C')
	{
		*s_map->counter += 1;
		printf("\ncollectable found\n");
	}
	if (s_map->counter > 0 && valid_map[s_map->y][s_map->x] == 'E')
	{
		printf("\nvalid\n");
	}
	valid_map[s_map->y][s_map->x] = 'x';
	fill(valid_map, &(t_map){s_map->x - 1, s_map->y, s_map->counter}, change);
	fill(valid_map, &(t_map){s_map->x + 1, s_map->y, s_map->counter}, change);
	fill(valid_map, &(t_map){s_map->x, s_map->y - 1, s_map->counter}, change);
	fill(valid_map, &(t_map){s_map->x, s_map->y + 1, s_map->counter}, change);
}


void	flood(char **valid_map, t_map *s_map)
{
	printf("\nXX: %d\n", map.y);
	//fill(valid_map, s_map, '0');
}


void	pathfinder(t_map *s_map)
{
	s_map.x = s_map->x_player_pos;
	s_map.y = s_map->y_player_pos;

	printf("\nXX: %d\n", map.y);
	flood(s_map, s_map->c_cnt);

}
 */