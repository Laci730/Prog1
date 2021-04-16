#include "Graph.h"
#include "Simple_Window.h"

double efix(double)
{
	return 1;
}

double gix(double x)
{
	return x / 2;
}
double hix(double x) 
{ 
	return x * x; 
}

double sloping_cos(double x)
{
	return cos(x) + gix(x);
}

int main()
{
	Point p{ 100, 100 };
	Simple_window win{ p, 600, 600, "Function graphs" };

	Axis xa{ Axis::x, Point{100, 300}, 400, 20, "x" };
	Axis ya{ Axis::y, Point{300, 500}, 400, 20, "y" };

	xa.set_color(Color::red);
	ya.set_color(Color::red);
	
	Point orig { 300, 300};
	double r_min = -10;
	double r_max = 11;
	int n_points = 400;
	double x_scale = 20;
	double y_scale = 20;

	
	Function fx{ efix, r_min, r_max, orig, n_points, x_scale, y_scale};
	Function gx{ gix, r_min, r_max, orig, n_points, x_scale, y_scale };
	Function hx{ hix, r_min, r_max, orig, n_points, x_scale, y_scale };
	Function jx{ cos, r_min, r_max, orig, n_points, x_scale, y_scale };
	Function kex{ sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale };
	Text t{ Point{100, 380}, "x/2" };
	jx.set_color(Color::blue);

	win.attach(xa);
	win.attach(ya);
	win.attach(fx);
	win.attach(gx);
	win.attach(hx);
	win.attach(t);
	win.attach(jx);
	win.attach(kex);
	win.wait_for_button();
}
