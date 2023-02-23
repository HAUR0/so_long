
#include <stdlib.h>
#include <stdio.h>

//start position must be player location
//end position must be exit location

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

char** make_area(char** zone, t_point size);
void	fill(char **tab, t_point size, t_point cur, char to_fill);
void	flood_fill(char **tab, t_point size, t_point begin);

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = 
    {
		"11111111",
		"11111111",
		"10000001",
		"11111111",
		"11111111",
	};

	char**  area = make_area(zone, size);
//area has now a memory allocated copy of "zone"
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
//----------------------------------------------

	t_point begin = {7, 4}; //1 less each because of NULL-Byte

	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

//allocating space for the 2D array given in the "main" according to the size of struct t_point size Y
char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return new;
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}










void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return;
		
	tab[cur.y][cur.x] = '-';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

