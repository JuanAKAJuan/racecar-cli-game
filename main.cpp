// TODO: Setup the Speed car movement.
// TODO: Setup the Handle car movement.
// TODO: Setup a win condition for the Speed Car.
// TODO: Setup a win condition for the Handle Car.
// TODO: Setup an algorithm to set the weights on any track.
// TODO: Setup a way for the user to pick a track.
// TODO: Make cars be able to land in a previous position after colliding with a car or wall instead of just keeping them in their current position and skipping their turn.
// TODO: Implement a custom feature.

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
