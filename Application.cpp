#include "Application.h"

void Application::Run()
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

	int userInputNumber;
	std::string trackTextFile;

	do
	{

		std::cout << "Pick a trackTextFile:" << std::endl;
		std::cout << "(1) track1.txt" << std::endl;
		std::cout << "(2) track2.txt" << std::endl;
		std::cout << "(3) track3.txt" << std::endl;
		std::cin >> userInputNumber;

		switch (userInputNumber)
		{
		case 1:
			trackTextFile = "track1.txt";
			break;
		case 2:
			trackTextFile = "track2.txt";
			break;
		case 3:
			trackTextFile = "track3.txt";
			break;
		default:
			std::cout << "Please enter a number between 1-3" << std::endl;
			break;
		}
	} while (userInputNumber < 1 || userInputNumber > 3);

	// Create input object using a sample m_Track
	std::ifstream trackFile(trackTextFile);
	// Using text file to create m_Track and m_Weights
	track.Read(trackFile);
	track.DisplayWeights();

	track.PutUserCarOnTrack();
	track.PutCPUSpeedCarOnTrack();
	track.PutCPUHandleCarOnTrack();

	while (true)
	{
		track.DisplayTrack();
		std::cout << std::endl;
		track.DisplayAllStats();
		track.MoveUserCar();
		track.MoveCPUSpeedCar();
	}
}
