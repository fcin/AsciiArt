#pragma once
#include<vector>
#include "../Image.h"

class ImageLoader {

public:
	int width;
	int height;
	int size;
	unsigned char* pixels;

public:
	virtual Image loadImage() = 0;
};
