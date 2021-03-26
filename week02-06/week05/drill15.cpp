//  To compile:
//  g++ drill15.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images`

#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include <cmath>

double one(double x) {return 1;};
double slope(double x) {return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return slope(x) + cos(x); }

int main()
try {
	using namespace Graph_lib;

	constexpr int width = 600;
    constexpr int height = width;
    constexpr int scale = 20;
    constexpr int axislength = 400;
    Point origo (width / 2, height / 2);

    Simple_window win {Point{100, 100}, width, height, "Canvas"};
    win.set_label("Drill Ch15");

    // A/4
    Axis x_axis (Axis::x, Point(origo.x - axislength / 2, origo.y), axislength, scale, "1 = = 20 pixels");
    Axis y_axis (Axis::y, Point(origo.x, origo.y + axislength / 2), axislength, scale, "1 = = 20 pixels");

    // A/5
    x_axis.set_color(Color::red);
    y_axis.set_color(Color::red);
    win.attach(x_axis);
    win.attach(y_axis);

    win.wait_for_button();

    // B/1
    Flex_function one_function (one, -10, 11, origo, axislength);

    // B/2
    one_function.reset_xscale(scale);
    one_function.reset_yscale(scale);
    win.attach(one_function);

    win.wait_for_button();

    // B/4
    Flex_function slope_function (slope, -10, 11, origo, axislength, scale, scale);
    win.attach(slope_function);

    // B/5
    Text slope_text (Point(origo.x - axislength / 2, origo.y - slope(-10) * scale - 30), "x/2");
    win.attach(slope_text);

    win.wait_for_button();

    // B/6
    Flex_function square_function (square, -10, 11, origo, axislength, scale, scale);
    win.attach(square_function);

    win.wait_for_button();

    // B/7
    Flex_function cos_function (cos, -10, 11, origo, axislength, scale, scale);
    cos_function.set_color(Color::blue);
    win.attach(cos_function);

    win.wait_for_button();

    // B/8
    Flex_function sloping_cos_function (sloping_cos, -10, 11, origo, axislength, scale, scale);
    win.attach(sloping_cos_function);

    win.wait_for_button();

	return 0;
} catch (exception& e) {
	cerr << "exception:\t" << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "error :(" << endl;
}