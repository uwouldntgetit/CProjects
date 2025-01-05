#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#define DELAY 5
/* I think that the best data structure for the snake is a list where every element is a coordinate representing a part of the body. The head is the first element
 * The boyd part n is going to the place of the bodypart n+1
 * The head can go left, right or straight
 * if the head touches the body or the border then the game finishes
 * */

struct element {
    struct element *next;
    int x;
    int y;
}


void show_field(struct element list, int size, int xpos, int ypos){
    char field [size][size];

    for(int i = 0; i < size; i++){
        for(int k = 0; k < size; k++){
            field[i][k] = '•';
        }
    }

    field[list.x][list.y] = '@';
    list = *(list.next);

    while(list){
        field[list.x][list.y] = 'S';
    }

    for(int i = 0; i < size; i++){
        for(int k = 0; k < size; k++){
            mvprintw(xpos + i, ypos + k, field[i][k]);
        }
    }
}

// I make a function that given the length of the side of the map and some more parameters it returns if the game is finished
// Done
int check_finish(struct element list, int size){
    struct element head = list;

    while(list.next){
        if(list.x == head.x && list.y == head.y)
            return 0;

        list = *(list.next);
    }
    
    if(head.x >= size || head.y >= size || head.x < 0 || head.y < 0)
        return 0;
    return 1;
}

// function that moves the snake. 0 is up, 1 is right, 2 is down, 3 is left
struct element snake_move(struct element list, int d){
    struct element head = list;
    int x, y;
    x = head.x;
    y = head.y;

    if(d == 0)
        head.y++;
    if(d == 1)
        head.x++;
    if(d == 2)
        head.y--;
    if(d == 3)
        head.x--;

    while(list = *(list.next)){
        x += list.x;
        y += list.y;

        list.x = x - list.x;
        list.y = y - list.y;
        
        x -= list.x;
        y -= list.y;
    }

    return head;
}

// The last thing I need is a function that captures the 'd' and 'a' keyboard buttons and changes
// the direction accordingly
int change_direction(int d){
    int x = getch(w);

    
}
