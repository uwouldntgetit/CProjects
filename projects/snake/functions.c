#include "snake_functions.h"


// I wantt to understand why the field isnt being shown
// the problem I have is that the characters in the field aren't being shown
void show_field(struct element *list, int fruits[SCREEN_SIZE][SCREEN_SIZE], int size, int xpos, int ypos){
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
        list = list->next;
    }

    // i = y, k = x
    for(int i = 0; i < SCREEN_SIZE; i++){
        for(int k = 0; k < SCREEN_SIZE; k++){
            if(fruits[i][k]){
                field[i][k * 2] = 'F';
                field[i][(k * 2) + 1] = ' ';
            }
        }
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
        list = *(list.next);
        // se entra qui dentro allora vuol dire che list.next esiste
        if(list.x == head.x && list.y == head.y){
            /*mvprintw(0, 0, "WOW");*/
            /*refresh();*/
            /*sleep(1);*/
            return 0;
        }

    }
    
    if(head.x >= size || head.y >= size || head.x < 0 || head.y < 0)
        return 0;
    return 1;
}

struct element snake_move(struct element * list, int d, int fruits[SCREEN_SIZE][SCREEN_SIZE], int* score_cnt){
    struct element * head = list;
    int x, y;
    int c = 0;
    int last_x, last_y;
    x = last_x = head->x;
    y = last_y = head->y;

    // Spaccato
    switch(d) {
        case 's':
            head->y++;
            break;
        case 'w':
            head->y--;
            break;
        case 'd':
            head->x++;
            break;
        case 'a':
            head->x--;
            break;
        default:
            return *head;
    }

    while(list->next != NULL){
        list = list->next;
        x += list->x;
        y += list->y;

        list->x = x - list->x;
        list->y = y - list->y;
        
        x -= list->x;
        y -= list->y;
        c++;
    }
    last_x = x;
    last_y = y;

    if(fruit_eaten(fruits, *head)){
        longer_tail(list, last_x, last_y);
        fruit_remove(fruits, head->x, head->y);
        *score_cnt += 1;
    }

    return *head;
}

/* function that periodically creates fruits on the playing field that when 
 * the serpent's head passes over, add another unit of its tail in the place of the last element
 * before it moved. every element adds 5 to the score
 */
void create_fruit(int fruits[SCREEN_SIZE][SCREEN_SIZE]){
    int x;
    int y;
    do{
        x = rand() % SCREEN_SIZE;
        y = rand() % SCREEN_SIZE;
    }while(fruits[x][y]);
    fruits[x][y] = 1;
}

void fruit_remove(int fruits[SCREEN_SIZE][SCREEN_SIZE], int x, int y){
    fruits[y][x] = 0;
}

int fruit_eaten(int fruits[SCREEN_SIZE][SCREEN_SIZE], struct element head){
    if(fruits[head.y][head.x]){
        return 1;
    }
    return 0;
}

void longer_tail(struct element * snake, int x, int y){
    struct element * t = malloc(sizeof(struct element));
    t->x = x;
    t->y = y;
    t->next = NULL;
    while(snake->next != NULL){
        snake = snake->next;
    }
    snake->next = t;
}

// The last thing I need is a function that captures the 'd' and 'a' keyboard buttons and changes
// the direction accordingly
int change_direction(){
    flushinp();
    sleep(1);
    int x = getch();
    return x;
}

char* int_to_str(int x){
    char * r = malloc(sizeof(char) * 16);
    int i = 0;
    int c = x;
    while(c > 0){
        c /= 10;
        i++;
    }
    r[i] = '\0';
    while(x > 0){
        r[--i] = (x % 10) + 48;
        x /= 10;
    }
    return r;
}
