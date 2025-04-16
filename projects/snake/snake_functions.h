#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <unistd.h>
#include <math.h>

#define DELAY 5
#define SCREEN_SIZE 20
/* I think that the best data structure for the snake is a list where every element is a coordinate representing a part of the body. The head is the first element
 * The boyd part n is going to the place of the bodypart n+1
 * The head can go left, right or straight
 * if the head touches the body or the border then the game finishes
 * */

struct element {
    struct element *next;
    int x;
    int y;
};


void show_field(struct element *list, int fruits[SCREEN_SIZE][SCREEN_SIZE], int size, int xpos, int ypos);
int check_finish(struct element list, int size);
void create_fruit(int fruits[SCREEN_SIZE][SCREEN_SIZE]);
int fruit_eaten(int fruits[SCREEN_SIZE][SCREEN_SIZE], struct element head);
void longer_tail(struct element * snake, int x, int y);
void fruit_remove(int fruits[SCREEN_SIZE][SCREEN_SIZE], int x, int y);

struct element snake_move(struct element * list, int d, int fruits[SCREEN_SIZE][SCREEN_SIZE], int* x);
int change_direction();
char * int_to_str(int n);
