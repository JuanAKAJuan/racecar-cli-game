#pragma once

#include <iostream>

class RaceCars
{
public:
	void DisplayStats() const;

	/* Getters */
	[[nodiscard]] char GetIDNumber() const
	{
		return m_IDNumber;
	}

	[[nodiscard]] int GetRowNumber() const
	{
		return m_RowNumber;
	}

	[[nodiscard]] int GetColumnNumber() const
	{
		return m_ColumnNumber;
	}

	[[nodiscard]] int GetMaxSpeed() const
	{
		return m_MaxSpeed;
	}

	[[nodiscard]] int GetRowVelocity() const
	{
		return m_RowVelocity;
	}

	[[nodiscard]] int GetColumnVelocity() const
	{
		return m_ColumnVelocity;
	}

	/* Setters */
	void SetIDNumber(char idNumber)
	{
		m_IDNumber = idNumber;
	}

	void SetRowNumber(int rowNumber)
	{
		m_RowNumber = rowNumber;
	}

	void SetColumnNumber(int columnNumber)
	{
		m_ColumnNumber = columnNumber;
	}

	void SetMaxSpeed(int maxSpeed)
	{
		m_MaxSpeed = maxSpeed;
	}

	void SetRowVelocity(int rowVelocity)
	{
		m_RowVelocity = rowVelocity;
	}

	void SetColumnVelocity(int columnVelocity)
	{
		m_ColumnVelocity = columnVelocity;
	}

private:
	char m_IDNumber;
	int m_RowNumber = 0;
	int m_ColumnNumber = 0;
	int m_MaxSpeed = 5;
	int m_RowVelocity = 1;
	int m_ColumnVelocity = 1;
};
