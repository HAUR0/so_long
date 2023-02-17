
#ifndef SOLONG_H
# define SOLONG_H
# include "./libft/libft.h"


typedef struct s_map
{
    char **array;
    int line_length;
    int line_count;
    int row;
    int valid;

    int x;
    int y;
} t_map;

#endif
