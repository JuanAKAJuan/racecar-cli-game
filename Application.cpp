#include "Application.h"

void Application::Run() {
  std::cout << "   ___________ ______   ____             _            "
            << std::endl;
  std::cout << "  / ____/ ___// ____/  / __ \\____ ______(_)___  ____ _"
            << std::endl;
  std::cout << " / /    \\__ \\/ /      / /_/ / __ `/ ___/ / __ \\/ __ `/"
            << std::endl;
  std::cout << "/ /___ ___/ / /___   / _, _/ /_/ / /__/ / / / / /_/ / "
            << std::endl;
  std::cout << "\\____//____/\\____/  /_/ |_|\\__,_/\\___/_/_/ /_/\\__, /  "
            << std::endl;
  std::cout << "                                             /____/   "
            << std::endl;

  // Create input object using a sample m_Track
  std::ifstream trackFile("track1.txt");
  // Using text file to create m_Track and m_Weights
  track.Read(trackFile);
  track.DisplayWeights();

  track.PutUserCarOnTrack();
  track.PutCPUSpeedCarOnTrack();
  track.PutCPUHandleCarOnTrack();

  while (true) {
    track.DisplayTrack();
    std::cout << std::endl;
    track.DisplayAllStats();
    track.MoveUserCar();
  }
}
