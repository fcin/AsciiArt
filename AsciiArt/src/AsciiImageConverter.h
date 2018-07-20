#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
#include "Image.h"

class AsciiImageConverter
{
private:
	std::unordered_map<int, char> fonts = {
		{ 0, '@' },
		{ 1, '@' },
		{ 2, '#' },
		{ 3, '8' },
		{ 4, '&' },
		{ 5, 'o' },
		{ 6, ':' },
		{ 7, '*' },
		{ 8, '_' },
		{ 9, '.' },
		{ 10, ' ' }
	};

public:
	Image toAscii(Image& image);
};
