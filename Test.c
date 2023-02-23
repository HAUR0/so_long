
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[5][5] = {
	1,1,0,1,0,
	1,0,1,0,1,
	1,1,1,0,0,
	0,0,1,1,0,
	0,1,1,1,0,
};

/* int map[5][5] = {
	1,1,1,1,1,
	0,0,0,1,0,
	1,1,1,1,1,
	0,1,1,0,0,
	1,1,1,1,1,
}; */

int path[5][5] = {
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
};

int path[5][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	0,0,1,1,0,
	0,0,0,1,1,
};

int pathfinder(int i, int j, int n)
{
	if(i == n-1 && j == n-1)
	{
		path[i][j] = 1;
		return (1);
	}
	if(map[i][j] == 1)
	{
		path[i][j] = 1;
		if(pathfinder(i, j+1, n) == 1) return (1);
		if(pathfinder(i+1, j, n) == 1) return (1);
		path[i][j] = 0;
	}
	return 0;
}

/* void	D2_printer(int **path, int n)
{
	int i = 0;
	int x = 0;
	while(i < n)
	{
		x = 0;
		while(x < 5)
		{
			printf("map: %d, %d\n", (int **)(int **)path[i][x]);
			x++;
		}
		i++;
	}
} */

int main()
{
	pathfinder(0, 0, 5);
	for (int i = 0; i < 5;)
	{
		for (int x = 0; x < 5;)
		{
			if (path[i][x])
			{
				printf("path: %i, %i\n", i, x);
			}
			x++;			
		}
		++i;
	}
	printf(">>Done \n");	
}



/* int main()
{
	int i;
	int x;

	i = 0;
	x = 0;
	pathfinder(0, 0, 5);
	while(i < 5)
	{
		x = 0;
		while(x < 5)
		{
			if (path[i][x])
			{
				printf("path: %i, %i\n", i, x);
			}
			x++;
		}
		printf("\n");
		++i;
	}
	return 0;
} */

/* 
int	main(void)
{
	char	arr[][];

	arr[0][0] = {3, 2, 1};




	is_sorted(arr, 3);
	return (0);
} */

/* int	pathfinder(int y, int x, int size, t_map *s_map)
{
	if(y == size-1 && x == size-1)
		return(1);

	if(s_map->map[y][x] == 1)
	{
		
		if (pathfinder(y, x+1, size, s_map->map) == 1) return 1;
		if (pathfinder(y+1, x, size, s_map->map) == 1) return 1;
	}
} */



//int size = sizeof(data) / sizeof(data[0]);
//diff <(./push_swap 8 7 6 5 4 3 45 12 66 809 345 1 22) <(./push_swap "8 7 6 5 4 3 45 12 66 809 345 1 22")

/* bash:
"8 7 6 5 4" == 8 7 6 5 4 -> single arguments for both cases
zsh:
"8 7 6 5 4" != 8 7 6 5 4 -> argumetns as string compared to single arguments */

//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./push_swap
