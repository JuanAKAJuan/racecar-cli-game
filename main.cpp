// NOTE: Y coordinates = Rows, X coordinates = Columns.
// NOTE: Speed and Handle cars will move the max spaces possible, the only
// difference between them is that the handle car will avoid hitting cars and
// walls, whilst the speed car will not.

#include "Application.h"

int main()
{
	Application app;

	app.Run();

	return 0;
}
