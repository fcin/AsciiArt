#pragma once

struct Image
{
	unsigned char *pixels;
	int size;
	int width;
	int height;

	~Image()
	{
		delete[] pixels;
	}
};