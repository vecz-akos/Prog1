// To compile, run this:
// g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>
#include <vector>

using namespace Graph_lib;

int main()
try {

	Point t1 (0, 0);
    Simple_window win (t1, 600, 400, "My window");
    win.set_label("My window");

    Axis xa {Axis::x, Point{30,300}, 280, 10, "x axis"};
    xa.label.set_color(Color::dark_red);
    Axis ya {Axis::y, Point{30,300}, 280, 10, "y axis"};
    win.attach(xa);
    win.set_label("Canvas #01");
    win.wait_for_button();

    ya.set_color(Color::green);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #02");
    win.wait_for_button();

    Function sine {sin,0,100,Point{30,150}, 500,50,50};
    win.attach(sine);
    win.set_label("Canvas #03");
    win.wait_for_button();

    Polygon poly;
    poly.add(Point{100, 30});
    poly.add(Point{100, 200});
    poly.add(Point{150, 190});
    poly.set_style(Line_style(Line_style::dash, 15));
    poly.set_color(Color::dark_yellow);
    poly.set_fill_color(Color::yellow);
    win.attach(poly);
    win.set_label("Canvas #04");
    win.wait_for_button();

    Rectangle rect {Point{200,200}, 100, 50};
    rect.set_fill_color(0x44a300);
    rect.set_color(Color::red);
    win.attach(rect);
    win.set_label("Canvas #05");
    win.wait_for_button();

    Text t {Point{50,300}, "Hello, graphical world!"};
    t.set_font(Font::courier);
    t.set_font_size(40);
    win.attach(t);
    win.set_label("Canvas #06");
    win.wait_for_button();

    Image ii {Point{400, 0},"badge.jpg"};
    win.attach(ii);
    win.set_label("Canvas #07");
    win.wait_for_button();

    Circle c {Point{200,300}, 50};
    Mark m {Point{200, 320}, 'x'};
    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100,20},oss.str()};
    win.attach(c);
    win.attach(m);
    win.attach(sizes);
    win.set_label("Canvas #08");
    win.wait_for_button();

} catch(exception& e) {
    cerr << "exception\t" << e.what() << endl;
    return 1;
} catch(...) {
    cerr << "error\n";
    return 2;
}
