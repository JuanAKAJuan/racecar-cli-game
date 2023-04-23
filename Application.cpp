#include "Application.h"

void Application::Run()
{
	Title();
	PromptTrackChoice();

	// Create input object using a sample m_Track
	std::ifstream trackFile(m_TrackTextFile);
	// Using text file to create m_Track and m_Weights
	track.Read(trackFile);
	track.DisplayWeights();

	track.PutCarsOntoTrack();
	while (true)
	{
		track.DisplayTrack();
		std::cout << std::endl;
		track.DisplayAllStats();
		track.MoveUserCar();
//		track.MoveCPUSpeedCar();
//		track.MoveCPUHandleCar();
	}
}

void Application::Title()
{
	std::cout << " ▄████▄   ██████  ▄████▄      ██▀███   ▄▄▄      ▄████▄   ██ "
				 "███▄    █    ▄████"
			  << std::endl;
	std::cout << "▒██▀ ▀█ ▒██    ▒ ▒██▀ ▀█     ▓██ ▒ ██▒▒████▄   ▒██▀ ▀█ ▒▓██ ██ "
				 "▀█   █ ▒ ██▒ ▀█▒"
			  << std::endl;
	std::cout << "▒▓█    ▄░ ▓██▄   ▒▓█    ▄    ▓██ ░▄█ ▒▒██  ▀█▄ ▒▓█    ▄░▒██▓██ "
				 " ▀█ ██▒░▒██░▄▄▄░"
			  << std::endl;
	std::cout << "▒▓▓▄ ▄██  ▒   ██▒▒▓▓▄ ▄██    ▒██▀▀█▄  ░██▄▄▄▄██▒▓▓▄ ▄██ "
				 "░██▓██▒  ▐▌██▒░░▓█  ██▓"
			  << std::endl;
	std::cout << "▒ ▓███▀ ▒██████▒▒▒ ▓███▀     ░██▓ ▒██▒ ▓█   ▓██▒ ▓███▀  "
				 "░██▒██░   ▓██░░▒▓███▀▒░"
			  << std::endl;
	std::cout << "░ ░▒ ▒  ▒ ▒▓▒ ▒ ░░ ░▒ ▒      ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░ ░▒ ▒   ░▓ ░ "
				 "▒░   ▒ ▒  ░▒   ▒"
			  << std::endl;
	std::cout << "░  ▒  ░ ░▒  ░    ░  ▒        ░▒ ░ ▒░  ░   ▒▒   ░  ▒    ▒ ░ ░░  "
				 " ░ ▒░  ░   ░"
			  << std::endl;
	std::cout << "░       ░  ░  ░  ░              ░   ░   ░   ▒  ░         ▒    "
				 "░   ░ ░ ░ ░   ░ ░"
			  << std::endl;
	std::cout << "░ ░           ░  ░ ░            ░           ░  ░ ░       ░     "
				 "     ░       ░"
			  << std::endl;
}

void Application::PromptTrackChoice()
{
	int userInputNumber;

	do
	{
		std::cout << "Pick a track:" << std::endl;
		std::cout << "(1) Mushroom Cup" << std::endl;
		std::cout << "(2) Flower Cup" << std::endl;
		std::cout << "(3) Banana Cup" << std::endl;
		std::cout << "(4) Special Cup (Custom Track)" << std::endl;
		std::cin >> userInputNumber;

		switch (userInputNumber)
		{
		case 1:
			m_TrackTextFile = "track1.txt";
			break;
		case 2:
			m_TrackTextFile = "track2.txt";
			break;
		case 3:
			m_TrackTextFile = "track3.txt";
			break;
		case 4:
			m_TrackTextFile = "track4.txt";
		default:
			std::cout << "Please enter a number between 1-4" << std::endl;
			break;
		}
	} while (userInputNumber < 1 || userInputNumber > 4);
}
