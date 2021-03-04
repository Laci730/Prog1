#include "Graph.h"
#include "Simple_window.h"

int main()
{
	Point tl{ 100, 100 };

	Simple_window win{ tl, 900, 700, "Nice" };

	Graph_lib::Polygon poly;

	poly.add(Point{ 300, 200 });
	poly.add(Point{ 300, 100 });
	poly.add(Point{ 400, 100 });
	poly.add(Point{ 400, 200 });
	
	poly.set_fill_color(Color::magenta);
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dot, 10));

	Axis xa{ Axis::x, Point{20,300}, 280, 0, "X" };
	Axis ya{ Axis::y, Point{20, 300}, 280, 0, "y" };
	xa.set_color(Color::red);
	ya.set_color(Color::red);

	Point center = { 250, 200 };
	Circle cir{ center, 50 };
	Mark o{ center, 'o' };

	Function cosine{ cos, 0, 100, Point{20, 150}, 1000, 50, 50 };
	Text text{ Point{150, 150}, "NiCe" };

	Image nice{ Point{400, 300}, "Nice.jpg" };
	
	win.attach(nice);
	win.attach(xa);
	win.attach(ya);
	win.attach(cosine);
	win.attach(poly);
	win.attach(text);
	win.attach(cir);
	win.attach(o);

	win.wait_for_button();
}