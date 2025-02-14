#include "snake_functions.h"


// I wantt to understand why the field isnt being shown
// the problem I have is that the characters in the field aren't being shown
void show_field(struct element *list, int size, int xpos, int ypos){
    char field [size][size + 1];

    for(int i = 0; i < size; i++){
        for(int k = 0; k < size; k++){
            field[i][k] = '-';
        }
        field[i][size] = '\0';
    }

    field[list->x][list->y] = '@';
    list = list->next;

    while(list != NULL){
        field[list->x][list->y] = 'S';
    }

    char string[size];

    for(int i = 0; i < size; i++){
            /*string[i] = field[i];*/
        mvprintw(xpos, ypos + i, field[i]);
        /*mvprintw(xpos + i, ypos + k, string);*/
    }
    /*mvprintw(0, 0, "here");*/
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

    while(list.next != NULL){
        list = *(list.next);
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
    int x = getch();
    return x;
}
