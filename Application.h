#pragma once

#include "Racetrack.h"

class Application
{
public:
	/*
	 * Start the program.
	 * @pre: NONE
	 * @post: The program will start and call the Title() and PromptTrackChoice() functions. It will
	 *        then begin the game loop.
	 */
	void Run();

	/*
	 * Display CSC Racing title screen.
	 * @pre: Run() has been called.
	 * @post: CSC Racing will be displayed into the console with fancy lettering.
	 */
	void Title();

	/*
	 * Asks the user what track they want to play on.
	 * @pre: Run() has been called.
	 * @post: There will be the tracks 1-4 and the user can pick one of them.
	 */
	void PromptTrackChoice();

private:
	Racetrack track;
	std::string m_TrackTextFile;
};
