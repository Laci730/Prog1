#include "Graph.h"
#include "Simple_Window.h"


int main()
{
	Point p = { 100, 100 };
	Simple_window win { p, 1000, 800, "Egyszerû ablak" };

	int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x = x_grid; x <= 800; x += x_grid)
		grid.add(Point{ x,0 }, Point{ x,800 });
	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point{ 0,y }, Point{ 800,y });

	Vector_ref<Graph_lib::Rectangle>rect;

	
	for (int i = 0; i < 800; i += 100)
	{
		rect.push_back(new Graph_lib::Rectangle(Point{ i, i }, 101, 101));
		rect[rect.size() - 1].set_fill_color(Color::red);
		win.attach(rect[rect.size() - 1]);
	}

	Image yep1{ Point{0, 200}, "yep.jpg" };
	Image yep2{ Point{500, 100}, "yep.jpg" };
	Image yep3{ Point{200, 600}, "yep.jpg" };
	
	Point pont{ 0, 0 };
	Image pic{ pont, "pic.jpg" };

	win.attach(grid);
	win.attach(yep1);
	win.attach(yep2);
	win.attach(yep3);
	win.attach(pic);

	while (win.wait_for_button())
	{
		if (pont.x > 600)
		{
			pont.x -= 700;
			pic.move(-700, -700);
		}
		else
		{
			pont.x += 100;
			pic.move(100, 100);
		}
	}
}
