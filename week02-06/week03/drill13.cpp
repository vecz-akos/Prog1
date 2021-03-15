//  To compile:
//  g++ drill13.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`

#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main()
try {
    using namespace Graph_lib;

    // 01

    int width = 1000;
    int height = 800;

    Simple_window win {Point{50, 50}, width, height, "Canvas"};
    win.set_label("Drill ch13");

    // 02

    constexpr int grid_size = 8;
    constexpr int square = 100;
    Vector_ref<Rectangle> grid;

    for (int i = 0; i < grid_size; ++i)
    {
        for (int j = 0; j < grid_size; ++j)
        {
            grid.push_back(new Rectangle{Point{square * i, square * j}, square, square});
            win.attach(grid[i * grid_size + j]);
        }
    }

    win.wait_for_button();

    // 03

    int gridlength = grid.size();

    for (int i = 0; i < grid_size; ++i)
    {
        grid.push_back(new Rectangle{Point{square * i, square * i}, square, square});
        grid[gridlength + i].set_fill_color(Color::red);
        win.attach(grid[gridlength + i]);
    }

    win.wait_for_button();

    // 03

    Vector_ref<Image> imgs;

    for (int i = 0; i < grid_size; i += 2)
    {
        imgs.push_back(new Image{Point{i * square, i * square},"debrecen.jpg"});
        win.attach(imgs[i / 2]);
    }

    win.wait_for_button();

    // 05

    Image img {Point{-square, 0}, "debrecen.jpg"};
    img.set_mask(Point{0, 0}, square, square);
    win.attach(img);

    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
        	img.move(square, 0);
            //img.moveToPoint(Point {j * square, i * square});
    		win.wait_for_button();
        }
        img.move(-grid_size * square, square);
        //img.moveToPoint(Point {0, i * square});
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
