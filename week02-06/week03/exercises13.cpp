//  To compile:
//  g++ exercises13.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o exercises13 `fltk-config --ldflags --use-images`

#include <vector>
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main()
try {
    using namespace Graph_lib;

    int width = 800;
    int height = 600;

    Simple_window win {Point{50, 50}, width, height, "Canvas"};
    win.set_label("Exercises ch13");

    // 01

    Graph_lib::Arc arc1(Point(150, 100), 100, 50, 45, 175);
    arc1.set_color(Color::dark_red);
    arc1.set_angle1(-15);
    arc1.set_angle2(270);
    arc1.set_angles(-175, -5);

    win.attach(arc1);

    // 02

    Box box1 (Point(260, 100), 80, 120);
    box1.set_style(Line_style(Line_style::dashdot, 4));
    win.attach(box1);

    Box box2 (Point(340, 100), 80, 120, 40);
    box2.set_fill_color(Color::green);
    win.attach(box2);

    // 03

    Arrow arrow {Point{500, 50}, Point{460, 200}};

    win.attach(arrow);

    // 06

    Textbox txtbox {Point{440, 210}, 140, "I'm Textbox"};

    win.attach(txtbox);

    // 07

    Vector_ref<Rectangle> colorChart;
    int rectSize = 20;
    int chartWidth = 16;
    int chartHeight = chartWidth;
    Point topRightCorner {30, height - (rectSize * chartWidth) - 30};
    int color = 0x0;

    for (int i = 0; i < chartHeight; ++i)
    {
        for (int j = 0; j < chartWidth; ++j)
        {
            colorChart.push_back(new Rectangle{Point{topRightCorner.x + j * rectSize,
                topRightCorner.y + i * rectSize}, rectSize, rectSize});
            colorChart[i * chartWidth + j].set_fill_color(color);
            win.attach(colorChart[colorChart.size() - 1]);
            color += 0x1;
        }
    }

    win.wait_for_button();

    return 0;


} catch(exception& e) {
    cerr << "exception\t" << e.what() << endl;
    return 1;
} catch(...) {
    cerr << "error\n";
    return 2;
}
