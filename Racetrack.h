#pragma once

#include "CPUHandleCar.h"
#include "CPUSpeedCar.h"
#include "UserCar.h"

#include <array>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Racetrack {
public:
  /**
   * Initialize the racetrack
   */
  Racetrack();

  /**
   * De-construct the racetrack
   */
  ~Racetrack();

  /**
   * Retrieve the m_Track Height
   *@pre m_Track is valid
   *@post return the number of rows in the m_Track
   */
  int Height() const;

  /**
   * Retrieve the m_Track Width
   * @pre m_Track is valid--i.e., all rows are of the same length.
   * @post return the number of columns in the m_Track
   */
  int Width() const;

  /**
   * Read the m_Track from an input stream, istream
   * @param ins input stream from which to Read the m_Track
   * @pre text file is provided using the correct characters for the m_Track
   * @post create m_Track/m_Weights converting m_Track into a 2d character array
   */
  void Read(std::istream &ins);

  /**
   *Display m_Track
   * @pre m_Track has been created
   * @post display m_Track with spacing
   **/
  void DisplayTrack();

  /**
   *Display m_Weights
   * This function exists purely for the purpose of debugging
   * @pre text file is provided and m_Weights have been initialized
   * @post display m_Weights of the current m_Track
   **/
  void DisplayWeights();

  /**
   *Create m_Track spaces
   * @pre text file is provided using the correct characters for the m_Track
   * @post convert string value "T" into a blank space. T's represent the actual
   *m_Track
   **/
  std::string ReplaceStrChar(std::string str, const std::string &replace,
                             char ch);

  /**
   *Initialize m_Weights for the m_Track
   * @pre text file is provided using the correct characters for the m_Track
   * @post return weight array with the proper m_Weights initialized
   */
  void InitWeights();

  /**
   *Access an element from the m_Track
   * @pre numbers are provided that are between the Height and Width ranges
   * @post return the element located in the row/column position
   */
  char GetTrack(int y, int x);

  /**
   *Update an element from the m_Track
   * @pre numbers are provided that are between the
   * Height and Width ranges.  A character is provided as well
   * @post Update the element located in the row/column
   * position using the character provided
   */
  void SetTrack(int y, int x, char value);

  /**
   *Get value of weight location
   * @pre numbers are provided that are between the Height and Width ranges
   * @post return the weight element located in the row/column position
   */
  int GetWeight(int y, int x);

  /**
   *Change value of weight location
   * @pre numbers are provided that are between the
   * Height and Width ranges.  A number is provided as well
   * @post Update the element located in the row/column
   * position using the number provided
   */
  void SetWeight(int y, int x, int value);

  bool GetWonTheGame();

  // My functions
  void CheckUserCollision();

  void DisplayAllStats();

  void PutUserCarOnTrack();

  void PutCPUSpeedCarOnTrack();

  void PutCPUHandleCarOnTrack();

  void MoveUserCar();

  void MoveCPUSpeedCar();

  void MoveCPUHandleCar();

  void UpdateUserPosition();

  void DeleteOldUserCar();

  static void WinningScreen();

private:
  UserCar user;
  CPUSpeedCar speed;
  CPUHandleCar handle;

  int m_XCoordinate = 0;
  int m_YCoordinate = 0;
  int m_NewXCoordinate = 0;
  int m_NewYCoordinate = 0;
  float m_OldXCoordinate = 0.0;
  float m_OldYCoordinate = 0.0;
  float m_XSlope = 0.0;
  float m_YSlope = 0.0;

  /**
   * Weight of a wall
   */
  static const int m_W_WALL = 1000000;

  /**
   * Weight of a finish line
   */
  static const int m_W_FINISH = 0;

  /**
   * Weight assigned to uninitialized cells
   */
  static const int m_W_UNINIT = -1;

  /**
   * The racetrack in printable form
   */
  std::vector<std::string> m_Track;
  /**
   * The race m_Track in the form of integer m_Weights
   */
  int **m_Weights;
};

/**INLINE FUNCTIONS - Used to improve performance in a program
***These functions work better for smaller tasks
***that are repeated frequently**/

/**
 *Return the Height of the m_Track
 */
inline int Racetrack::Height() const { return m_Track.size(); }

/**
 *Return the Width of the m_Track
 */
inline int Racetrack::Width() const { return m_Track[0].size(); }
