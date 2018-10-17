#include "MyColor.h"



MyColor::MyColor()
{
	r = 0;
	g = 0;
	b = 0;
	a = 255;
}

MyColor::MyColor(int red, int green, int blue, int alpha)
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}

MyColor MyColor::operator+(const MyColor & rhs) const
{
	MyColor newColor;
	newColor.r = (r + rhs.r);
	newColor.g = (g + rhs.g);
	newColor.b = (b + rhs.b);
	if (newColor.r > 255)
		newColor.r = 255;
	if (newColor.g > 255)
		newColor.g = 255;
	if (newColor.b > 255)
		newColor.b = 255;
	return newColor;
}

MyColor MyColor::operator-(const MyColor & rhs) const
{
	MyColor newColor;
	newColor.r = (r - rhs.r);
	newColor.g = (g - rhs.g);
	newColor.b = (b - rhs.b);
	if (newColor.r < 1)
		newColor.r = 1;
	if (newColor.g < 1)
		newColor.g = 1;
	if (newColor.b < 1)
		newColor.b = 1;
	return newColor;
}

MyColor MyColor::operator*(const MyColor & rhs) const
{
	MyColor newColor;
	newColor.r = (r * rhs.r);
	newColor.g = (g * rhs.g);
	newColor.b = (b * rhs.b);
	if (newColor.r > 255)
		newColor.r = 255;
	if (newColor.g > 255)
		newColor.g = 255;
	if (newColor.b > 255)
		newColor.b = 255;
	return newColor;
}

MyColor MyColor::operator/(const MyColor & rhs) const
{
	MyColor newColor;
	newColor.r = (r / rhs.r);
	newColor.g = (g / rhs.g);
	newColor.b = (b / rhs.b);
	if (newColor.r < 1)
		newColor.r = 1;
	if (newColor.g < 1)
		newColor.g = 1;
	if (newColor.b < 1)
		newColor.b = 1;
	return newColor;
}

MyColor & MyColor::operator+=(const MyColor & rhs)
{
	// TODO: insert return statement here.
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	return *this;
}

MyColor & MyColor::operator-=(const MyColor & rhs)
{
	// TODO: insert return statement here
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;
	return *this;
}

MyColor & MyColor::operator*=(const MyColor & rhs)
{
	// TODO: insert return statement here
	r *= rhs.r;
	g *= rhs.g;
	b *= rhs.b;
	return *this;
}

MyColor & MyColor::operator/=(const MyColor & rhs)
{
	// TODO: insert return statement here
	r /= rhs.r;
	g /= rhs.g;
	b /= rhs.b;
	return *this;
}

bool MyColor::operator==(const MyColor & rhs) const
{
	return false;
}

bool MyColor::operator!=(const MyColor & rhs) const
{
	return false;
}

MyColor MyColor::operator!() const
{
	return MyColor();
}


