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

	endwin();
    return 0;
}
