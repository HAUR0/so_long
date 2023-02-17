
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

/* 
typedef struct node
{
    int age;
    char name;
    struct node *next;
} t_list;

int main()
{
    t_list *A;
    A = malloc(sizeof(t_list));
    
} */


#define MAX_NODES 100

int data[MAX_NODES];
int next[MAX_NODES];
int head = -1;
int free_list = 0;

void init_list() {
    int i;

    for (i = 0; i < MAX_NODES - 1; i++) {
        next[i] = i + 1;
    }
    next[MAX_NODES - 1] = -1;

    head = -1;
    free_list = 0;
}

int get_node() {
    int new_node = free_list;
    if (new_node != -1) {
        free_list = next[free_list];
        next[new_node] = -1;
    }
    return new_node;
}

void insert_node(int new_data) {
    int new_node = get_node();
    if (new_node != -1) {
        data[new_node] = new_data;
        if (head == -1) {
            head = new_node;
        } else {
            next[new_node] = head;
            head = new_node;
        }
    }
}


typedef struct s_map
{
    char **array;
    int line;
    int rows;
    int valid;
} t_map;

typedef struct s_one
{
    char *name;
    int age;
}   t_one;


void add_one(int *anything)
{
    *anything += 1;
}

void add_one_struct(t_one *anyStruct)
{
    anyStruct->age += 1;
}


int main(int ac, char **av)
{
    int x;
    t_one A;
    t_map map;

    if (get_user_input_into_map(ac, av, &map) == 1)
        save_exit();
    check_if_map_valid(&map.valid, map);
    draw_map(map);
    free_all_my_shit(&map);

    x = 0;
    A.age = 30;

    add_one(&x);
    add_one_struct(&A);

    printf("%d\n", x);
    printf("%d\n", A.age);
    return(0);
}