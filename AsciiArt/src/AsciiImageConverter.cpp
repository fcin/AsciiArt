#include "AsciiImageConverter.h"

Image AsciiImageConverter::toAscii(Image& image)
{
	unsigned char *ascii = new unsigned char[image.size / 3];

	for (int index = 0; index < image.size; index += 3)
	{
		unsigned char r = image.pixels[index + 2];
		unsigned char g = image.pixels[index + 1];
		unsigned char b = image.pixels[index + 0];
		double luminance = (0.2126 * r + 0.7152 * g + 0.0722 * b);
		int fontIndex = (int)std::floor(luminance / 255 * 10);
		ascii[index / 3] = fonts[fontIndex];
	}

	return {ascii, image.size / 3, image.width / 3, image.height};

	//Image ascii;
	//ascii.pixels = new unsigned char[image.size];
	//ascii.size = image.size;
	//ascii.width = image.width;
	//ascii.height = image.height;
	//for (int index = 0; index < image.size; index++)
	//{
	//	int fontIndex = (int)std::floor(image.pixels[index] / 255 * 10);
	//	ascii.pixels[index] = fonts[fontIndex];
	//}

	//return ascii;
}