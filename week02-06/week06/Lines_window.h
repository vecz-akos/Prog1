#include "../GUI/GUI.h"

using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
private:
	Open_polyline lines;

	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	Menu color_menu;
	Button color_menu_button;
	bool colorMenuVisible = false;

	Menu line_menu;
	Button line_menu_button;
	bool lineMenuVisible = false;

	void change(Color c) { lines.set_color(c); }
	void changeLine(Line_style l) {lines.set_style(l); }
	void hide_color_menu();
	void hide_line_menu();

	void red_pressed() { change(Color::red); hide_color_menu(); }
	void blue_pressed() { change(Color::blue); hide_color_menu(); }
	void black_pressed() { change(Color::black); hide_color_menu(); }
	void color_menu_pressed() { hide_color_menu(); }

	void solid_pressed() { changeLine(Line_style::solid); hide_line_menu(); }
	void dash_pressed() { changeLine(Line_style::dash); hide_line_menu(); }
	void dot_pressed() { changeLine(Line_style::dot); hide_line_menu(); }
	void line_menu_pressed() { hide_line_menu(); }

	void next();
	void quit();

	// callback functions:
	static void cb_red(Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}
	static void cb_blue(Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}
	static void cb_black(Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();}
	static void cb_color_menu(Address, Address pw) {reference_to<Lines_window>(pw).color_menu_pressed();}

	static void cb_solid(Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();}
	static void cb_dash(Address, Address pw) {reference_to<Lines_window>(pw).dash_pressed();}
	static void cb_dot(Address, Address pw) {reference_to<Lines_window>(pw).dot_pressed();}
	static void cb_line_menu(Address, Address pw) {reference_to<Lines_window>(pw).line_menu_pressed();}

	static void cb_next(Address, Address pw) {reference_to<Lines_window>(pw).next();}
	static void cb_quit(Address, Address pw) {reference_to<Lines_window>(pw).quit();}
};
