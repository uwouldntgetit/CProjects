#include "snake_functions.h"


// I wantt to understand why the field isnt being shown
// the problem I have is that the characters in the field aren't being shown
void show_field(struct element *list, int size, int xpos, int ypos){
    char field [size][size * 2 + 1];

    for(int i = 0; i < size; i++){
        for(int k = 0; k < size * 2; k += 2){
            field[i][k] = '-';
            field[i][k + 1] = ' ';
        }
        field[i][size * 2] = '\0';
    }

    field[list->y][list->x * 2] = '@';
    list = list->next;

    while(list != NULL){
        field[list->y][list->x * 2] = 'S';
    }

    // now it works, the first coordinate of mvprintw is y, the second x
    for(int i = 0; i < size; i++){
        mvprintw(ypos + i, xpos, field[i]);
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

struct element snake_move(struct element list, int d, int fruits[SCREEN_SIZE][SCREEN_SIZE]){
    struct element head = list;
    int x, y;
    int last_x, last_y;
    x = last_x = head.x;
    y = last_y = head.y;

    if(d == 's')
        head.y++;
    if(d == 'w')
        head.y--;
    if(d == 'd')
        head.x++;
    if(d == 'a')
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
    if(fruit_eaten(fruits, head))
       longer_tail(list, last_x, last_y);

    return head;
}

/* function that periodically creates fruits on the playing field that when 
 * the serpent's head passes over, add another unit of its tail in the place of the last element
 * before it moved. every element adds 5 to the score
 */
void create_fruit(int fruits[SCREEN_SIZE][SCREEN_SIZE]){
    int x = 3;
    int y = 3;
    while(fruits[x][y]){
        int x = rand() % SCREEN_SIZE;
        int y = rand() % SCREEN_SIZE;
    }
    mvprintw(0, 5, "hi");
    fruits[x][y] = 1;
}

int fruit_eaten(int fruits[SCREEN_SIZE][SCREEN_SIZE], struct element head){
    if(fruits[head.x][head.y]){
        return 1;
    }
    return 0;
}

void longer_tail(struct element snake, int x, int y){
    struct element t;
    t.x = x;
    t.y = y;
    while(snake.next != NULL){
        snake = * snake.next;
    }
    snake.next = &t;
}

// The last thing I need is a function that captures the 'd' and 'a' keyboard buttons and changes
// the direction accordingly
int change_direction(){
    int x = getch();
    flushinp();
    return x;
}
