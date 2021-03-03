// To compile, run this:
// g++ exercises.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o exercises `fltk-config --ldflags --use-images`

#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector>

using namespace Graph_lib;

int main()
try {

    Point t1 (100, 100);
    Simple_window win (t1, 600, 400, "Exercise");

    // Exercise 01

    win.set_label("Exercise 01");

    Rectangle r{Point{10, 10}, 50, 25};
    r.set_color(Color::red);

    Polygon rect;
    rect.add(Point{70, 10});
    rect.add(Point{120, 10});
    rect.add(Point{120, 35});
    rect.add(Point{70, 35});
    rect.set_color(Color::blue);

    win.attach(r);
    win.attach(rect);
    win.wait_for_button();

    // Exercise 02

    Rectangle rt{Point(100, 200), 100, 30};
    win.attach(rt);

    Text t {Point(100, 225), "Howdy!"};
    t.set_font(Font::helvetica_bold);
    t.set_font_size(20);
    win.attach(t);

    win.set_label("Exercise 02");

    win.wait_for_button();

    // Exercise 03

    Text te1 (Point{240, 160}, "O");
    te1.set_font(Font::helvetica_bold);
    te1.set_font_size(150);

    Text te2 (Point{360, 160}, "A");
    te2.set_font(Font::helvetica_bold);
    te2.set_font_size(150);

    te1.set_color(Color::green);
    te2.set_color(Color::red);

    win.attach(te1);
    win.attach(te2);

    win.set_label("Exercise 03");

    win.wait_for_button();

    // Exercise 04

    Vector_ref<Rectangle> squares;
    int a = 50;
    int index = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            squares.push_back(new Rectangle{Point{20 + a * j, 250 + a * i}, a, a});

            index % 2 == 0 ? squares[index].set_fill_color(Color::black) : squares[index].set_fill_color(Color::white);

            win.attach(squares[index]);
            ++index;
        }
    }

    win.set_label("Exercise 04");

    win.wait_for_button();

    // Exercise 05

    Rectangle huge {Point{150, 150}, x_max() * 2 / 3, y_max() * 3 / 4};
    huge.set_fill_color(Color::red);

    win.attach(huge);

    win.set_label("Exercise 05");

    win.wait_for_button();

    // Exercise 06

    Rectangle huge2 {Point{-150, -150}, 3840, 2190};
    huge2.set_fill_color(Color::white);

    win.attach(huge2);

    win.set_label("Exercise 06");

    win.wait_for_button();

    // Exercise 07

    Polygon house;

    house.add(Point{45, 10});
    house.add(Point{70, 60});
    house.add(Point{70, 110});
    house.add(Point{20, 110});
    house.add(Point{20, 60});

    Polygon door;

    door.add(Point{30, 110});
    door.add(Point{38, 110});
    door.add(Point{38, 90});
    door.add(Point{30, 90});

    Rectangle win1{Point(30, 70), 10, 10},
              win2{Point(55, 75), 10, 15},
              chimney{Point(30, 20), 10, 25};

    win.attach(house);
    win.attach(door);
    win.attach(win1);
    win.attach(win2);
    win.attach(chimney);

    win.set_label("Exercise 07");

    win.wait_for_button();

    // Exercise 08

    Vector_ref<Circle> olympic;

    olympic.push_back( new Circle{Point{100,100}, 50});
    olympic.push_back( new Circle{Point{210,100}, 50});
    olympic.push_back( new Circle{Point{320,100}, 50});
    olympic.push_back( new Circle{Point{160,160}, 50});
    olympic.push_back( new Circle{Point{267,160}, 50});
    olympic[0].set_color(Color::blue);
    olympic[1].set_color(Color::black);
    olympic[2].set_color(Color::red);
    olympic[3].set_color(Color::yellow);
    olympic[4].set_color(Color::green);

    for (int i = 0; i < olympic.size(); ++i)
    {
        olympic[i].set_style(Line_style(Line_style::solid, 10));
        win.attach(olympic[i]);
    }

    win.set_label("Exercise 08");

    win.wait_for_button();

    // Exercise 09

    Image ii {Point{400, 200},"debrecen.jpg"};
    win.attach(ii);
    Text deb{Point{440, 220}, "Debrecen"};
    deb.set_font(Font::courier);
    deb.set_font_size(20);
    deb.set_color(Color::white);
    win.attach(deb);

    win.set_label("Debrecen");

    win.wait_for_button();
} catch(exception& e) {
    cerr << "exception\t" << e.what() << endl;
    return 1;
} catch(...) {
    cerr << "error\n";
    return 2;
}
