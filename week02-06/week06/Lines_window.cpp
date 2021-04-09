#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
		:Window{xy,w,h,title},
	next_button{Point{x_max()-150,0}, 70, 20, "Next point", cb_next},
	quit_button{Point{x_max()-70,0}, 70, 20, "Quit", cb_quit},
	next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
	next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
	xy_out{Point{100,0}, 100, 20, "current (x,y):"},

	color_menu{Point{x_max()-70,50},70,30,Menu::vertical,"color"},
	color_menu_button{Point{x_max()-80,30}, 80, 20, "color menu", cb_color_menu},
	
	line_menu{Point{x_max()-150,50},70,30,Menu::vertical,"line"},
	line_menu_button{Point{x_max()-160,30}, 80, 20, "line menu", cb_line_menu}
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");

	color_menu.attach(new Button{Point{x_max()-70,90},70,20,"red",cb_red});
	color_menu.attach(new Button{Point{x_max()-70,120},70,20,"blue",cb_blue});
	color_menu.attach(new Button{Point{x_max()-70,150},70,20,"black",cb_black});
	attach(color_menu);
	color_menu.hide();
	attach(color_menu_button);

	line_menu.attach(new Button{Point{x_max()-150,90},70,20,"solid",cb_solid});
	line_menu.attach(new Button{Point{x_max()-150,120},70,20,"dash",cb_dash});
	line_menu.attach(new Button{Point{x_max()-150,150},70,20,"dot",cb_dot});
	attach(line_menu);
	line_menu.hide();
	attach(line_menu_button);

	attach(lines);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{x,y});

	// update current position readout:
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());
	redraw();
}

void Lines_window::hide_color_menu() {
	 if (colorMenuVisible) {
	 	color_menu.hide();
	 	colorMenuVisible = false;
	 } else {
	 	color_menu.show();
	 	colorMenuVisible = true;
	 }
}

void Lines_window::hide_line_menu() {
	 if (lineMenuVisible) {
	 	line_menu.hide();
	 	lineMenuVisible = false;
	 } else {
	 	line_menu.show();
	 	lineMenuVisible = true;
	 }
}