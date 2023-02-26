
#include <stdlib.h>
#include <stdio.h>

//start position must be player location
//end position must be exit location

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

typedef struct  s_point
{
    int           length;
    int           height;

	int X_pos;
	int Y_pos;

	int counter;
}               t_point;

char** make_area(char** zone, t_point size);
void	fill(char **map, t_point begin, int *counter);
void	flood_fill(char **tab, t_point begin, int *counter);

int main(void)
{
	t_point size;
	size.length = 13;
	size.height = 5;
	size.X_pos = 1;
	size.Y_pos = 1;

	char *zone[] = 
    {
		"1111111111111",
		"10010C0000001",
		"1000011111CC1",
		"1P0011C000001",
		"1111111111111",
	};

	char**  area = make_area(zone, size);
//area has now a memory allocated copy of "zone"
	for (int i = 0; i < size.height; ++i)
		printf("%s\n", area[i]);
	printf("\n");
//----------------------------------------------

	//t_point begin = {1, 1};
	t_point begin;
	begin.length = 13;
	begin.height = 5;
	begin.X_pos = 1;
	begin.Y_pos = 1;
	begin.counter = 0;

	fill(area, begin, &begin.counter);

//----------------------------------------------
	for (int i = 0; i < size.height; ++i)
		printf("%s\n", area[i]);

	printf("\nbegin.counter: %i\n", begin.counter);

	return (0);
}


char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.height);
	for (int i = 0; i < size.height; ++i)
	{
		new[i] = malloc(size.length + 1);
		for (int j = 0; j < size.length; ++j)
			new[i][j] = zone[i][j];
		new[i][size.length] = '\0';
	}
	return new;
}



void	fill(char **map, t_point begin, int *counter)
{
	if (begin.Y_pos < 0 || begin.Y_pos >= begin.height || begin.X_pos < 0 || begin.X_pos >= begin.length || (map[begin.Y_pos][begin.X_pos] != 'C' && map[begin.Y_pos][begin.X_pos] != '0' && map[begin.Y_pos][begin.X_pos] != 'E'))
	{	
		return;
	}
	if (map[begin.Y_pos][begin.X_pos] == 'C' || map[begin.Y_pos][begin.X_pos] == 'E')
	{
		(*counter)++;
		printf("\nvalid %i\n", *counter);
	}
	map[begin.Y_pos][begin.X_pos] = '-';
	fill(map, (t_point){begin.length, begin.height, begin.X_pos - 1, begin.Y_pos, *counter}, counter);
	fill(map, (t_point){begin.length, begin.height, begin.X_pos + 1, begin.Y_pos, *counter}, counter);
	fill(map, (t_point){begin.length, begin.height, begin.X_pos, begin.Y_pos - 1, *counter}, counter);
	fill(map, (t_point){begin.length, begin.height, begin.X_pos, begin.Y_pos + 1, *counter}, counter);
}

