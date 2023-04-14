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

	// Create input object using a sample m_Track
	std::ifstream trackFile("track1.txt");
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
