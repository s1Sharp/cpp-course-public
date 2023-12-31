#pragma once

#include <string>

class IFigure
{
public:
	virtual std::string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};