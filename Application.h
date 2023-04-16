#pragma once

#include "Racetrack.h"

class Application
{
public:
	void Run();

	void Title();

	void PromptTrackChoice();

private:
	// Create RaceTrack object
	Racetrack track;
	std::string m_TrackTextFile;
};
