#ifndef COLOR_H
#define COLOR_H

#include "Vector3.h"

using Color = Vector3;

void printColor(std::ostream& out, Color& pixelColor)
{
	auto r = pixelColor.x();
	auto g = pixelColor.y();
	auto b = pixelColor.z();

	int rByte = static_cast<int>(255.999 * r);
	int gByte = static_cast<int>(255.999 * g);
	int bByte = static_cast<int>(255.999 * b);

	out << rByte << " " << gByte << " " << bByte << std::endl;
}

#endif