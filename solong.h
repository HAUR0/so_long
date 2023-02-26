
#ifndef SOLONG_H
# define SOLONG_H
# include "./libft/libft.h"

typedef struct s_map
{
    char **map;
    int m_length;
    int m_height;
    int valid;

    int p_cnt;
    int c_cnt;
    int e_cnt;
    int zero_cnt;
    int one_cnt;

	int x_pos;
	int y_pos;

} t_map;

int		pathfinder(t_map any_struct);

#endif
