#include "TxtImageSaver.h"

void TxtImageSaver::save(std::string filePath, Image& image)
{
	std::ofstream stream(filePath);

	char* row = new char[image.width];

	for (int y = 0; y < image.height; y++)
	{
		char* startOffset = (char*)image.pixels + (y * image.width);
		std::strncpy(row, startOffset, image.width);

		stream << row << "\n";
	}

	delete[] row;
	stream.close();
}