#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

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


void show_field(struct element *list, int size, int xpos, int ypos);
int check_finish(struct element list, int size);

struct element snake_move(struct element list, int d);
int change_direction(int d);
