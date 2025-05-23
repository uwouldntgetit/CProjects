#include "snake_functions.h"

// the snake can only go left and right

int main(int argc, char* argv[]){
	initscr();
	noecho();
	curs_set(FALSE);
    cbreak();
    // delay is in tenths of a second
    halfdelay(DELAY);


    int max_x, max_y;
    int score = 0, counter = 0;
    int fruits[SCREEN_SIZE][SCREEN_SIZE];
    int l = 0;
    char input = '2';
    getmaxyx(stdscr, max_y, max_x);
    struct element snake;
    snake.x = 0;
    snake.y = 0;
    snake.next = NULL;
    char arr[2];
    arr[1] = 0;
    /*char arr[4] = {'1', '2', '3', '\0'};*/

    for(int i = 0; i < SCREEN_SIZE; i++){
        for(int k = 0; k < SCREEN_SIZE; k++){
            fruits[i][k] = 0;
        }
    }

    // now that show_field() works I need to get change_direction() right
    // the head of the serpent moves, now i'll check with the tail
    // now the things that remain to fix are:
    // create a system that increases tail length
    // get only the last character before the timeout ends
    while(check_finish(snake, SCREEN_SIZE)){
        show_field(&snake, fruits, SCREEN_SIZE, (max_x - SCREEN_SIZE * 2) / 2, (max_y - SCREEN_SIZE) / 2);
        refresh();
        input = change_direction();
        arr[0] = input;
        mvprintw(0, 0, int_to_str(score * l));
        /*mvprintw(0, max_x, );*/
        /*sleep(1);*/

        // create fruits is accessed
        if(0 == counter % 5){
            create_fruit(fruits);
            counter = 0;
        }

        snake = snake_move(&snake, arr[0], fruits, &score);
        counter++;
        l++;
    }
    
    free(snake.next);
	endwin();
    return 0;
}
