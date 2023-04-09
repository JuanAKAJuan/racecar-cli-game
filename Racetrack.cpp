#include "Racetrack.h"
#include <iostream>
#include <string>

Racetrack::Racetrack() : m_Track()
{
    // Let the initializer list construct the m_Track vector
    // m_Weights can not be created until the size of the m_Track is known
    m_Weights = NULL;
}

/**
 *Destroy object and m_Weights pointer
 */
Racetrack::~Racetrack()
{
    // I can not delete an array if it has not yet been created
    if (m_Weights != NULL)
    {
        // delete each row
        for (int i = 0; i < this->Height(); i++)
        {
            delete[] m_Weights[i];
        }

        // delete the array of pointers
        delete[] m_Weights;
    }
}

/**
 *Read m_Track and add elements to vector and m_Weights to weight array
 */
void Racetrack::Read(std::istream &ins)
{
    std::string element;
    while (ins >> element)
    {
        for (int i = 0; i < element.size(); i++)
        {
            // Replace the T's with blank/m_Track spaces
            element = ReplaceStrChar(element, "T", ' ');
        }
        // Add current element to the m_Track vector
        m_Track.push_back(element);
    }
    // Initialize m_Weights after m_Track has been created
    this->InitWeights();
}

/**
 *Convert string into character
 */
std::string Racetrack::ReplaceStrChar(std::string str,
                                      const std::string &replace, char ch)
{
    // set our locator equal to the first appearance of any character in replace
    size_t found = str.find_first_of(replace);

    while (found != std::string::npos)
    {
        // While our position in the sting is in range.
        str[found] = ch; // Change the character at position.
        found = str.find_first_of(replace, found + 1); // Relocate again.
    }

    return str; // return our new string.
}

/**
 *Access an element from the m_Track
 */
char Racetrack::GetTrack(int y, int x)
{ return m_Track[y][x]; }

/**
 *Update an element from the m_Track
 */
void Racetrack::SetTrack(int y, int x, char value)
{ m_Track[y][x] = value; }

/**
 *Get value of weight location
 **/
int Racetrack::GetWeight(int y, int x)
{ return m_Weights[y][x]; }

/**
 *Update a weight from the weight m_Track
 */
void Racetrack::SetWeight(int y, int x, int value)
{ m_Weights[y][x] = value; }

/**
 *Displays Track in Game Mode
 */
void Racetrack::DisplayTrack()
{
    for (int i = 0; i < Height(); i++)
    {
        for (int j = 0; j < Width(); j++)
        {
            std::cout << std::setw(3) << m_Track[i][j];
        }
        std::cout << std::endl;
    }
}

/**
 *Displays the m_Weights of the current m_Track.  Used for Testing/Debugging
 *Purposes
 */
void Racetrack::DisplayWeights()
{
    std::cout << "********************TRACK WEIGHTS***********************"
              << std::endl;
    for (int i = 0; i < Height(); i++)
    {
        for (int j = 0; j < Width(); j++)
        {
            if (m_Weights[i][j] > 100)
            {
                std::cout << std::setw(3) << "X";
            }
            else
            {
                std::cout << std::setw(3) << m_Weights[i][j];
            }
        }
        std::cout << std::endl;
    }
    std::cout << "********************TRACK WEIGHTS***********************"
              << std::endl
              << std::endl;
}

/**
 *Initialize weight values
 */
void Racetrack::InitWeights()
{
    // Allocate the number of required rows (pointers)
    m_Weights = new int *[Height()];

    // Allocate each row
    for (int i = 0; i < Height(); i++)
    {
        m_Weights[i] = new int[Width()];

        // Set each cell as uninitialized
        for (int j = 0; j < Width(); j++)
        {
            m_Weights[i][j] = m_W_UNINIT;

            // Set wall m_Weights
            if (toupper(m_Track[i][j]) == 'X')
            {
                m_Weights[i][j] = m_W_WALL;
            }
            else if (toupper(m_Track[i][j]) == 'F')
            {
                // Set finish line weight
                m_Weights[i][j] = m_W_FINISH;
            }
        }
    }
    /**Assign Weights to blank spaces here**/

    /**
     *PLEASE READ
     *The m_Weights below are specific to the current m_Track ONLY
     *You will need to develop an algorithm to dynamically
     *initialize m_Weights to any m_Track
     **/

    // all coords for weight of 11
    m_Weights[1][1] = 11;
    m_Weights[1][2] = 11;
    m_Weights[1][3] = 11;
    m_Weights[1][4] = 11;
    m_Weights[1][5] = 11;
    m_Weights[1][6] = 11;
    m_Weights[2][6] = 11;

    // all coords for weight of 10
    m_Weights[2][1] = 10;
    m_Weights[2][2] = 10;
    m_Weights[2][3] = 10;
    m_Weights[2][4] = 10;
    m_Weights[2][5] = 10;
    m_Weights[3][1] = 10;
    m_Weights[3][5] = 10;
    m_Weights[4][1] = 10;
    m_Weights[5][1] = 10;
    m_Weights[6][1] = 10;
    m_Weights[7][1] = 10;

    // all coords for weight of 9

    m_Weights[3][2] = 9;
    m_Weights[3][3] = 9;
    m_Weights[3][4] = 9;
    m_Weights[4][2] = 9;
    m_Weights[5][2] = 9;
    m_Weights[6][2] = 9;
    m_Weights[7][2] = 9;

    // all coords for weight of 8
    m_Weights[4][3] = 8;
    m_Weights[5][3] = 8;
    m_Weights[6][3] = 8;
    m_Weights[7][3] = 8;

    // all coords for weight of 7
    m_Weights[5][4] = 7;
    m_Weights[6][4] = 7;
    m_Weights[7][4] = 7;

    // all coords for weight of 6
    m_Weights[5][5] = 6;
    m_Weights[6][5] = 6;
    m_Weights[7][5] = 6;
    m_Weights[7][6] = 6;
    m_Weights[7][7] = 6;
    m_Weights[7][8] = 6;
    m_Weights[7][9] = 6;

    // all coords for weight of 5
    m_Weights[5][6] = 5;
    m_Weights[6][6] = 5;
    m_Weights[6][7] = 5;
    m_Weights[6][8] = 5;
    m_Weights[6][9] = 5;

    // all coords for weight of 4
    m_Weights[5][7] = 4;
    m_Weights[5][8] = 4;
    m_Weights[5][9] = 4;
    m_Weights[4][8] = 4;
    m_Weights[4][9] = 4;

    // all coords for weight of 3
    m_Weights[4][8] = 3;
    m_Weights[4][9] = 3;

    // all coords for weight of 2
    m_Weights[3][8] = 2;
    m_Weights[3][9] = 2;

    // all coords for weight of 1
    m_Weights[2][8] = 1;
    m_Weights[2][9] = 1;
}

void Racetrack::PutUserCarOnTrack()
{
    for (int row = 1; row < Height(); row++)
    {
        for (int column = 1; column < Width(); column++)
        {
            if (m_Weights[row][column] == 11)
            {
                user.SetRowNumber(row);
                user.SetColumnNumber(column);
                m_Track[user.GetRowNumber()][user.GetColumnNumber()] =
                        user.GetIDNumber();
                break;
            }
        }
        break;
    }
}

void Racetrack::PutCPUSpeedCarOnTrack()
{
    for (int row = 1; row < Height(); row++)
    {
        for (int column = 1; column < Width(); column++)
        {
            if (m_Weights[row][column] == 11 && m_Track[row][column] == ' ')
            {
                speed.SetRowNumber(row);
                speed.SetColumnNumber(column);
                m_Track[speed.GetRowNumber()][speed.GetColumnNumber()] =
                        speed.GetIDNumber();
                return;
            }
        }
    }
}

void Racetrack::PutCPUHandleCarOnTrack()
{
    for (int row = 1; row < Height(); row++)
    {
        for (int column = 1; column < Width(); column++)
        {
            if (m_Weights[row][column] == 11 && m_Track[row][column] == ' ')
            {
                handle.SetRowNumber(row);
                handle.SetColumnNumber(column);
                m_Track[handle.GetRowNumber()][handle.GetColumnNumber()] =
                        handle.GetIDNumber();
                return;
            }
        }
    }
}

void Racetrack::MoveUserCar()
{
    // Get the users current coordinates
    m_OldXCoordinate = user.GetColumnNumber();
    m_OldYCoordinate = user.GetRowNumber();

    std::cout << "Enter X Coordinate: ";
    while (!(std::cin >> m_XCoordinate) ||
           m_XCoordinate > user.GetColumnVelocity() ||
           m_XCoordinate < -(user.GetColumnVelocity()))
    {
        std::cout << "Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    // As long as the user's input is not 0, and their velocity hasn't reached its
    // max, the column velocity will increase by 1.
    if (m_XCoordinate != 0)
    {
        if (user.GetColumnVelocity() < user.GetMaxSpeed())
        {
            user.SetColumnVelocity(user.GetColumnVelocity() + 1);
        }
    }

    std::cout << "Enter Y Coordinate: ";
    while (!(std::cin >> m_YCoordinate) ||
           m_YCoordinate > user.GetRowVelocity() ||
           m_YCoordinate < -(user.GetRowVelocity()))
    {
        std::cout << "Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    // As long as the user's input is not 0, and their velocity hasn't reached its
    // max, the row velocity will increase by 1.
    if (m_YCoordinate != 0)
    {
        if (user.GetRowVelocity() < user.GetMaxSpeed())
        {
            user.SetRowVelocity(user.GetRowVelocity() + 1);
        }
    }

    // Update new positions based on the coordinates the user typed in
    m_NewXCoordinate = user.GetColumnNumber() + m_XCoordinate;
    m_NewYCoordinate = user.GetRowNumber() + m_YCoordinate;
    m_XSlope = (float(m_OldXCoordinate) - float(m_NewXCoordinate)) / 10;
    m_YSlope = (float(m_OldYCoordinate) - float(m_NewYCoordinate)) / 10;
    bool checkFinish =
            m_Weights[int(round(m_OldYCoordinate))][int(round(m_OldXCoordinate))] ==
            m_W_FINISH;
    bool checkWall =
            m_Weights[int(round(m_OldYCoordinate))][int(round(m_OldXCoordinate))] ==
            m_W_WALL;

    // TODO: Setup wall and car collision for diagonal movements
    // Go from old coordinates to new ones while showing the slanted path
    for (int i = 0; i < 10; i++)
    {
        m_OldXCoordinate = m_OldXCoordinate - m_XSlope;
        m_OldYCoordinate = m_OldYCoordinate - m_YSlope;

        // Check to see if the user has won
        if (checkFinish)
        {
            WinningScreen();
            DeleteOldUserCar();
            UpdateUserPosition();
            DisplayTrack();
            std::cin.ignore();
            std::cin.get();
            exit(0);
        }
        else if (checkWall)
        {
            // Notifies the user they hit a wall, resets their velocities, and lowers
            // their max speed by 1
            std::cout << "You hit a wall! Your velocity has been reset and max speed has been decreased." << std::endl;
            m_XCoordinate = 0;
            m_YCoordinate = 0;
            user.SetMaxSpeed(user.GetMaxSpeed() - 1);
            user.SetColumnVelocity(1);
            user.SetRowVelocity(1);
            break;
        }
    }

    DeleteOldUserCar();
    UpdateUserPosition();
}

void Racetrack::UpdateUserPosition()
{
    // Use player's input to move the car
    // Reversed the x and y Coordinates since they make more sense for x to be
    // associated with columns and y to be associated with rows when it comes to
    // movement.
    user.SetRowNumber(user.GetRowNumber() + m_YCoordinate);
    user.SetColumnNumber(user.GetColumnNumber() + m_XCoordinate);
    m_Track[user.GetRowNumber()][user.GetColumnNumber()] = user.GetIDNumber();
}

void Racetrack::DeleteOldUserCar()
{
    // Delete old position from track.
    m_Track[user.GetRowNumber()][user.GetColumnNumber()] = ' ';
}

void Racetrack::DisplayAllStats()
{
    user.DisplayStats();
    speed.DisplayStats();
    handle.DisplayStats();
}

void Racetrack::CheckUserCollision()
{
    m_NewXCoordinate = user.GetColumnNumber() + m_XCoordinate;
    m_NewYCoordinate = user.GetRowNumber() + m_YCoordinate;

    // Turn collisions into boolean (better readability)
    bool speedCollision = m_Track[m_NewYCoordinate][m_NewXCoordinate] ==
                          m_Track[speed.GetRowNumber()][speed.GetColumnNumber()];
    bool handleCollision =
            m_Track[m_NewYCoordinate][m_NewXCoordinate] ==
            m_Track[handle.GetRowNumber()][handle.GetColumnNumber()];
    bool userWallCollision =
            m_Weights[m_NewYCoordinate][m_NewXCoordinate] == m_W_WALL;

    if (speedCollision || handleCollision)
    {
        // Notifies the user they hit a car, resets their velocities, and lowers
        // their max speed by 1
        std::cout << "You hit a car! Your velocity has been reset and max speed "
                     "has been decreased."
                  << std::endl;
        m_XCoordinate = 0;
        m_YCoordinate = 0;
        user.SetColumnVelocity(1);
        user.SetRowVelocity(1);
        user.SetMaxSpeed(user.GetMaxSpeed() - 1);
    }
    else if (userWallCollision)
    {
        // Notifies the user they hit a wall, resets their velocities, and lowers
        // their max speed by 1
        std::cout << "You hit a wall! Your velocity has been reset and max speed "
                     "has been decreased."
                  << std::endl;
        m_XCoordinate = 0;
        m_YCoordinate = 0;
        user.SetMaxSpeed(user.GetMaxSpeed() - 1);
        user.SetColumnVelocity(1);
        user.SetRowVelocity(1);
    }
    else
    {
        DeleteOldUserCar();
        UpdateUserPosition();
    }
}

void Racetrack::WinningScreen()
{
    std::cout << "__   _____  _   _  __        _____  _   _ _" << std::endl;
    std::cout << "\\ \\ / / _ \\| | | | \\ \\      / / _ \\| \\ | | |"
              << std::endl;
    std::cout << " \\ V / | | | | | |  \\ \\ /\\ / / | | |  \\| | |" << std::endl;
    std::cout << "  | || |_| | |_| |   \\ V  V /| |_| | |\\  |_|" << std::endl;
    std::cout << "  |_| \\___/ \\___/     \\_/\\_/  \\___/|_| \\_(_)"
              << std::endl;
}
