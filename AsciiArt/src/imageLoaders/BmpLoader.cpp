#include "BmpLoader.h"
#include <iostream>
#include <algorithm>
#include <iterator>  

BmpLoader::BmpLoader(std::string filePath) : m_FilePath(filePath) { }

Image BmpLoader::loadImage()
{
	std::ifstream fileStream(m_FilePath, std::ios_base::in | std::ios_base::binary);

	fileStream.ignore(std::numeric_limits<std::streamsize>::max());
	std::streamsize streamSize = fileStream.gcount();
	
	fileStream.clear();
	fileStream.seekg(0, std::ios::beg);

	char info[54];
	fileStream.read(info, 54);

	// Todo Store only luminocity for each pixel not rgb and then replace with characters is super easy

	width = *((int*)&info[18]) * 3; // r g b
	height = *((int*)&info[22]);
	size = width * height;

	char* tempPixels = new char[(unsigned int)(width * height)];
	fileStream.seekg(m_HeaderOffset);
	int trailingZeros = width % 4 == 0 ? 0 : 4 - (width % 4);
	for (int rowIndex = 0; rowIndex < height; rowIndex++)
	{
		fileStream.read((tempPixels + width * rowIndex), width + trailingZeros);
	}

	// BMP is stored upside down. Flip it vertically.
	char* temp = new char[width];
	for (int index = 0; index < height / 2; index++)
	{
		char* up = (char*)&tempPixels[index * width];
		char* down = (char*)&tempPixels[(height - index - 1) * width];
		std::copy(down, down + width, stdext::checked_array_iterator<char *>(temp, width));
		std::copy(up, up + width, stdext::checked_array_iterator<char *>(down, width));
		std::copy(temp, temp + width, stdext::checked_array_iterator<char *>(up, width));
	}
	delete[] temp;

	pixels = reinterpret_cast<unsigned char*>(tempPixels);
	return {pixels, size, width, height};
}