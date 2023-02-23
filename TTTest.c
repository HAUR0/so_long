#include <stdio.h>
#include <stdlib.h>

//start position must be player location
//end position must be exit location

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

typedef struct s_point
{
	int	x;
	int	y;
	int	*counter;
}		t_point;

char	**make_area(char **zone, t_point size);
void	fill(char **tab, t_point size, t_point *cur, char to_fill);
void	flood_fill(char **tab, t_point size, t_point *begin);

int	main(void)
{
	char	**area;
	int		x;
	t_point	quickfix;
	t_point	*begin;
	
	t_point size;
	size.x = 39;
	size.y = 13;
	size.counter = 0;
	char *zone[] =
		{
			"000001111111111111111111111111111111111",
			"P00001111111111111111111111111111111111",
			"111111111111111111111111111111111111111",
			"111111111111111110001111111111111111111",
			"111111111111000000000000111111111111111",
			"111111111100C00000000000001111111111111",
			"1111111100000000000000000000C1111111111",
			"111111111111000000000000001111111111111",
			"111111111111111000000000000000000000000",
			"111111111111111111000111111111000000000",
			"11111111111111111111111111111111000E000",
			"111111111111111111111111111111100000000",
			"11111111111111111111110000C000000000000",
		};
/* 	
	t_point size; // = {39, 12};
	size.x = 13;
	size.y = 5;
	size.counter = 0;
    
	char *zone[] = 
    {
		"1111111111111",
		"10010000C0001",
		"1000011111001",
		"100011E000001",
		"1111111111111",
	}; */

	area = make_area(zone, size);
	//area has now a memory allocated copy of "zone"
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
	//----------------------------------------------


	x = 0;
	begin = &quickfix;
	begin->x = 18; // <- insert X player position here
	begin->y = 7;  // <- insert Y player position here
	begin->counter = &x;


	flood_fill(area, size, begin);

	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	//int number = *begin->counter;
	printf("\n%i", *begin->counter);
	return (0);
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

//allocating space for the 2D-array given in the "main" according to the size of struct t_point size Y
char	**make_area(char **zone, t_point size)
{
	char	**new;

	new = malloc(sizeof(char *) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

void	flood_fill(char **tab, t_point size, t_point *begin)
{
	fill(tab, size, begin, '0');
}

void	fill(char **tab, t_point size, t_point *begin, char to_fill)
{
	if (begin->y < 0 || begin->y >= size.y || begin->x < 0 || begin->x >= size.x
		|| begin->x >= size.x || (tab[begin->y][begin->x] != to_fill
			&& tab[begin->y][begin->x] != 'C' && tab[begin->y][begin->x] != 'E'))
	{
		return ;
	}
	if(tab[begin->y][begin->x] == 'C')
	{
		*begin->counter += 1;
		printf("\ncollectable found\n");
	}
	if(begin->counter > 0 && tab[begin->y][begin->x] == 'E')
	{
		printf("\nWin\n\n");
		//exit (0);
	}
	tab[begin->y][begin->x] = '-';
	fill(tab, size, &(t_point){begin->x - 1, begin->y, begin->counter}, to_fill);
	fill(tab, size, &(t_point){begin->x + 1, begin->y, begin->counter}, to_fill);
	fill(tab, size, &(t_point){begin->x, begin->y - 1, begin->counter}, to_fill);
	fill(tab, size, &(t_point){begin->x, begin->y + 1, begin->counter}, to_fill);
}
