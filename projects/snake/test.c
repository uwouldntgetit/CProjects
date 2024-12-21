#include <ncurses.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	initscr();
	noecho();
	curs_set(FALSE);

  mvprintw(0, 0, "Hi");
  refresh();
	sleep(1);

  mvprintw(0, 0, "Hey");
  refresh();
  sleep(1);

	endwin();
}
