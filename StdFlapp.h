#ifndef STDFLAPP_H
#define STDFLAPP_H

struct Point {
	int x;
	int y;
};

struct Size {
	int width;
	int height;
};

struct Vector {
	int v_x;
	int v_y;
	Vector operator+(const Vector &);
};

struct Rect {
	Size size;
	Point origin; //left top point
};

#endif // !STDFLAPP_H
