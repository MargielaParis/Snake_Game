#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>

using namespace std;


char map[21][43] = {
	{"211111111111111111111111111111111111111112"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000344400000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000001"},
	{"211111111111111111111111111111111111111112"},
};

void maploader(int i, int j, WINDOW *win){
	for (int h=0;h<i;h++){
		for (int w=0;w<j;w++){
			if (map[h][w] == '2')
				mvwprintw(win,h,w, "X");
			else if (map[h][w] == '1')
				mvwprintw(win,h,w, "x");
			else if (map[h][w] == '0')
				mvwprintw(win,h,w, " ");
			else if (map[h][w] == '3')
				mvwprintw(win,h,w, "@");
			else if (map[h][w] == '4')
				mvwprintw(win,h,w, "o");
		}
	}
}

void basicWindow()
{
	initscr();
	resize_term(80, 80);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_WHITE);

	bkgd(COLOR_PAIR(1));
	border('*', '*', '*', '*', '*', '*', '*', '*');
	mvprintw(1, 35, "Snake Game");
	refresh(); 

	//score window
	WINDOW *scorewin = newwin(10, 20, 4, 55);
	wbkgd(scorewin, COLOR_PAIR(2));
	wattron(scorewin, COLOR_PAIR(2));
	wborder(scorewin, '*','*','*','*','*','*','*','*');
	mvwprintw(scorewin, 1,3, "Score Board");
	mvwprintw(scorewin, 3,3, "B: ");
	mvwprintw(scorewin, 5,3, "+: ");
	mvwprintw(scorewin, 6,3, "-: ");
	mvwprintw(scorewin, 8,3, "G: ");
	wrefresh(scorewin);
	

	//mission window
	WINDOW *missionwin = newwin(10, 20, 15, 55);
	wbkgd(missionwin, COLOR_PAIR(2));
	wattron(missionwin, COLOR_PAIR(2));
	wborder(missionwin, '*','*','*','*','*','*','*','*');
	mvwprintw(missionwin, 1,3, "Mission Board");
	mvwprintw(missionwin, 3,3, "B: ");
	mvwprintw(missionwin, 5,3, "+: ");
	mvwprintw(missionwin, 6,3, "-: ");
	mvwprintw(missionwin, 8,3, "G: ");
	wrefresh(missionwin);
}

void GameWindow(){
	//game window
	initscr();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_WHITE);

	WINDOW *win1 = newwin(21, 42, 4, 2);
	wbkgd(win1, COLOR_PAIR(2));
	wattron(win1, COLOR_PAIR(2));
	maploader(21,42, win1);
	wrefresh(win1);
}

// 뱀 움직이기
void moveSnake(int x, int y, char dir) {

	char direction;
	direction = dir;
	bool die;
	die = false;
	
	int key = getch();
	
	if (key) {
		switch(key)
		{
			case KEY_LEFT:
				if (direction == 'r') die = true;
				else direction = 'l';
				break;
			case KEY_RIGHT:
				if (direction == 'l') die = true;
				else direction = 'r';
				break;
			case KEY_UP:
				if (direction == 'd') die = true;
				else direction = 'u';
				break;
			case KEY_DOWN:
				if (direction == 'u') die = true;
				else direction = 'd';
				break;
			case KEY_F(1):
				die = true;
				break;

			default:
				break;
		}
	}

	if(die != true) {
		map[y][x] = '4';
		switch(direction)
		{
			case 'l':
				x -= 1;
				break;
			case 'r':
				x += 1;
				break;
			case 'u':
				y -= 1;
				break;
			case 'd':
				y += 1;
				break;
			default:
				break;
		}
	}
	
	if (map[y][x] == '1' or map[y][x] == '2' or map[y][x] == '3' or map[y][x] == '4') die = true;

	map[y][x] = '3';
	GameWindow();

	if (die != true) moveSnake(x,y,direction);

}

void init() {
	char key;
	initscr();
	resize_term(80,80);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	border('*', '*', '*', '*' ,'*', '*', '*', '*');
	bkgd(COLOR_PAIR(1));

	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();

	mvprintw(15,10, "        ####    ##     ##    ##      ##   ##   ####### ");
	mvprintw(16,10, "       ##   #  ####   ##   ## ##    ##  ##    ##       ");
	mvprintw(17,10, "        ##    ## ##  ##   ######   ## ##     #######   ");
	mvprintw(18,10, "     #   ##  ##   ####   ##   ##  ##  ##    ##         ");
	mvprintw(19,10, "     #####  ##     ##   ##    ## ##   ##   #######     ");

	mvprintw(21,26, " Made by. KiYeon Park");
	mvprintw(23,25, " Press Any Key to Start");
	getch();
	clear();
}

int main() {
	int x, y;
	x = 18; y = 10;
	init();
	basicWindow();
	GameWindow();
	moveSnake(x,y,'l');

	getch();

	endwin();
}

