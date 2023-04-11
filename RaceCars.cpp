#include "RaceCars.h"

void RaceCars::DisplayStats() const
{
	std::cout << "Car ID: " << this->GetIDNumber()
			  << " Coordinates: " << this->GetColumnNumber() << ","
			  << this->GetRowNumber() << " Max Speed: " << this->GetMaxSpeed()
			  << " Velocity: " << this->GetColumnVelocity() << ","
			  << this->GetRowVelocity() << std::endl;
}
