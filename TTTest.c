#include <stdio.h>
#include <stdlib.h>

//start position must be player location
//end position must be exit location

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/



typedef struct s_point
{
	int	x;
	int	y;
	int	counter;
}		t_point;

void test(t_point any_struct, int *counter)
{
	
}

int	main(void)
{
	t_point	size;
	size.x = 15;
	size.y = 15;
	size.counter = 0;

	test(&size, &size.counter);
}