#pragma once
class MyColor
{
public:
	MyColor();
	MyColor(int red, int green, int blue, int alpha);

	int r;
	int g;
	int b;
	int a = 256;

	MyColor operator+(const MyColor &rhs) const;
	MyColor operator-(const MyColor &rhs) const;
	MyColor operator*(const MyColor &rhs) const;
	MyColor operator/(const MyColor &rhs) const;

	MyColor& operator+=(const MyColor &rhs);
	MyColor& operator-=(const MyColor &rhs);
	MyColor& operator*=(const MyColor &rhs);
	MyColor& operator/=(const MyColor &rhs);

	bool operator==(const MyColor &rhs) const;
	bool operator!=(const MyColor &rhs) const;

	MyColor operator!() const;

};

