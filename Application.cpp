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
		track.MoveCPUSpeedCar();
	}
}
void Application::Title()
{
	std::cout << " ▄████▄   ██████  ▄████▄      ██▀███   ▄▄▄      ▄████▄   ██ ███▄    █    ▄████" << std::endl;
	std::cout << "▒██▀ ▀█ ▒██    ▒ ▒██▀ ▀█     ▓██ ▒ ██▒▒████▄   ▒██▀ ▀█ ▒▓██ ██ ▀█   █ ▒ ██▒ ▀█▒" << std::endl;
	std::cout << "▒▓█    ▄░ ▓██▄   ▒▓█    ▄    ▓██ ░▄█ ▒▒██  ▀█▄ ▒▓█    ▄░▒██▓██  ▀█ ██▒░▒██░▄▄▄░" << std::endl;
	std::cout << "▒▓▓▄ ▄██  ▒   ██▒▒▓▓▄ ▄██    ▒██▀▀█▄  ░██▄▄▄▄██▒▓▓▄ ▄██ ░██▓██▒  ▐▌██▒░░▓█  ██▓" << std::endl;
	std::cout << "▒ ▓███▀ ▒██████▒▒▒ ▓███▀     ░██▓ ▒██▒ ▓█   ▓██▒ ▓███▀  ░██▒██░   ▓██░░▒▓███▀▒░" << std::endl;
	std::cout << "░ ░▒ ▒  ▒ ▒▓▒ ▒ ░░ ░▒ ▒      ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░ ░▒ ▒   ░▓ ░ ▒░   ▒ ▒  ░▒   ▒" << std::endl;
	std::cout << "░  ▒  ░ ░▒  ░    ░  ▒        ░▒ ░ ▒░  ░   ▒▒   ░  ▒    ▒ ░ ░░   ░ ▒░  ░   ░" << std::endl;
	std::cout << "░       ░  ░  ░  ░              ░   ░   ░   ▒  ░         ▒    ░   ░ ░ ░ ░   ░ ░" << std::endl;
	std::cout << "░ ░           ░  ░ ░            ░           ░  ░ ░       ░          ░       ░" << std::endl;
}
void Application::PromptTrackChoice()
{
	int userInputNumber;

	do
	{
		std::cout << "Pick a track:" << std::endl;
		std::cout << "(1) track1.txt" << std::endl;
		std::cout << "(2) track2.txt" << std::endl;
		std::cout << "(3) track3.txt" << std::endl;
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
		default:
			std::cout << "Please enter a number between 1-3" << std::endl;
			break;
		}
	} while (userInputNumber < 1 || userInputNumber > 3);
}
