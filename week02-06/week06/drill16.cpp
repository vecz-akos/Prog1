//  To compile:
//  g++ drill16.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ./Lines_window.cpp -o drill16 `fltk-config --ldflags --use-images`

#include "Lines_window.h"
#include "../GUI/Graph.h"

int main()
try {
	using namespace Graph_lib;

	Lines_window win {Point{100,100}, 600, 400, "lines"};

	return gui_main();
}


catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}