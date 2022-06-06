#include <ncurses.h>
#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int main()
{
	
	string Snake;
	Snake = "@ooo";

	initscr();
	resize_term(50, 120);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_WHITE);

	bkgd(COLOR_PAIR(1));
	border('*', '*', '*', '*', '*', '*', '*', '*');
	mvprintw(1, 50, "Snake Game");
	mvprintw(2, 45, "Press Enter to Start");
	refresh();
	getch(); 

	
	//game window
	WINDOW *win1 = newwin(30, 70, 4, 2);
	wbkgd(win1, COLOR_PAIR(2));
	wattron(win1, COLOR_PAIR(2));
	wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');
	mvwprintw(win1, 14, 34, "@ooo");
	wrefresh(win1);
	
	//score window
	WINDOW *scorewin = newwin(13, 32, 4, 75);
	wbkgd(scorewin, COLOR_PAIR(2));
	wattron(scorewin, COLOR_PAIR(2));
	wborder(scorewin, '*','*','*','*','*','*','*','*');
	mvwprintw(scorewin, 2,10, "Score Board");
	mvwprintw(scorewin, 4,3, "B: ");
	mvwprintw(scorewin, 6,3, "+: ");
	mvwprintw(scorewin, 8,3, "-: ");
	mvwprintw(scorewin, 10,3, "G: ");
	wrefresh(scorewin);
	
	//mission window
	WINDOW *missionwin = newwin(13, 32, 20, 75);
	wbkgd(missionwin, COLOR_PAIR(2));
	wattron(missionwin, COLOR_PAIR(2));
	wborder(missionwin, '*','*','*','*','*','*','*','*');
	mvwprintw(missionwin, 2,9, "Mission Board");
	mvwprintw(missionwin, 4,3, "B: ");
	mvwprintw(missionwin, 6,3, "+: ");
	mvwprintw(missionwin, 8,3, "-: ");
	mvwprintw(missionwin, 10,3, "G: ");
	wrefresh(missionwin);

	getch();
	delwin(win1);
	delwin(scorewin);
	delwin(missionwin);
	endwin();

	return 0;
}

