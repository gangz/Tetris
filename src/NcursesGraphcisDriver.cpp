#include "NcursesGraphcisDriver.h"
#include  <ncurses.h>
#include <assert.h>
NcursesGraphcisDriver::NcursesGraphcisDriver() {
	initscr();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	keypad(stdscr,true);
	box(stdscr,ACS_VLINE,ACS_HLINE);
}

NcursesGraphcisDriver::~NcursesGraphcisDriver() {
	clear();
	endwin();
}

void NcursesGraphcisDriver::drawBox(Point left_top, Point right_bottom){
	assert(left_top.x<right_bottom.x);
	assert(left_top.y<right_bottom.y);
	assert(left_top.x>0);
	assert(left_top.y>0);

	int width = 2*(right_bottom.y-left_top.y)+1;
	int height = (right_bottom.x-left_top.x+1);

	move(left_top.x, 2*left_top.y+1);
	hline('_',width);

	move(left_top.x+1, 2*left_top.y);
	vline(ACS_VLINE,height);

	move(left_top.x+1, 2*right_bottom.y+2);
	vline(ACS_VLINE,height);

	move(right_bottom.x+1, 2*left_top.y+1);
	hline('_',width);

	refresh();
	;
}

void NcursesGraphcisDriver::writeText(Point pos, std::string text){
	move(pos.x, 2*pos.y); /*move the cursor to the center*/
	waddstr(stdscr, text.c_str());
}

void NcursesGraphcisDriver::drawCell(Point pos){
	move(pos.x, 2*pos.y);
	waddstr(stdscr, "[]");
}
