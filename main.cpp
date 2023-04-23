// TODO: Let car 1 go past the finish line and still win.
// TODO: Make cars be able to land in a previous position after colliding with a car or wall instead of just keeping them in their current position and skipping their turn.
// TODO: Make a custom track.
// TODO: Random movement for custom feature.

// NOTE: X coordinates = Columns, Y coordinates = Rows
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
