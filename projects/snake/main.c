#include "snake_functions.h"

// the snake can only go left and right

int main(int argc, char* argv[]){
	initscr();
	noecho();
	curs_set(FALSE);
    cbreak();
    halfdelay(DELAY);

    mvprintw(0, 0, "Hi");
    refresh();
    sleep(1);

    mvprintw(0, 0, "Hey");
    refresh();
    sleep(1);

    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);
    struct element snake;
    snake.x = 0;
    snake.y = 0;
    snake.next = NULL;

    while(check_finish(snake, SCREEN_SIZE)){
        show_field(&snake, SCREEN_SIZE, (max_x - SCREEN_SIZE) / 2, (max_y - SCREEN_SIZE) / 2);
        refresh();
        mvprintw(1, 0, "whoa");
        sleep(1);
    }

	endwin();
    return 0;
}
