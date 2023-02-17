
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int	main(void)
{
	char	arr[][];

	arr[0][0] = {3, 2, 1};




	is_sorted(arr, 3);
	return (0);
}

//int size = sizeof(data) / sizeof(data[0]);
//diff <(./push_swap 8 7 6 5 4 3 45 12 66 809 345 1 22) <(./push_swap "8 7 6 5 4 3 45 12 66 809 345 1 22")

/* bash:
"8 7 6 5 4" == 8 7 6 5 4 -> single arguments for both cases
zsh:
"8 7 6 5 4" != 8 7 6 5 4 -> argumetns as string compared to single arguments */

//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./push_swap
