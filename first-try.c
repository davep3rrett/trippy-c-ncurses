#include <ncurses.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	// some vars we'll be using
	int max_y = 0;
	int max_x = 0;
	int counter = 0;
	
	int y = 0;
	int x = 0;

	// init boilerplate
	initscr();
	noecho();
	curs_set(FALSE);

	// color stuff
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_CYAN);
	init_pair(2, COLOR_CYAN, COLOR_MAGENTA);

	while(1) {
		getmaxyx(stdscr, max_y, max_x);

		char forward[max_x];
		char backward[max_x];

		for(int i = 0; i < max_x - 2; i++) {
			forward[i] = '/';
			backward[i] = '\\';
		}

		forward[max_x - 1] = '\0';
		backward[max_x - 1] = '\0';

		for(int i = 0; i < max_y; i++) {
			if(i % 2 == 0 && counter % 2 == 0) {
				attron(COLOR_PAIR(1));
				mvprintw(i, 0, forward);
			} else if(i % 2 == 0 && counter % 2 == 1) {
				attron(COLOR_PAIR(2));
				mvprintw(i, 0, backward);
			} else if(i % 2 == 1 && counter % 2 == 0) {
				attron(COLOR_PAIR(2));
				mvprintw(i, 0, backward);
			} else if (i % 2 == 1 && counter % 2 == 1) {
				attron(COLOR_PAIR(1));
				mvprintw(i, 0, forward);
			}
		}

		usleep(89000);

		refresh();

		counter++;
	}

	endwin();
}
