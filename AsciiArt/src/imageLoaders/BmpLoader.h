#pragma once
#include "ImageLoader.h"
#include<fstream>
#include "../Image.h"

class BmpLoader : public ImageLoader
{

private:
	std::string m_FilePath;
	const int m_HeaderOffset = 54;
	const int m_PixelWidthHeaderOffset = 18;

public:
	BmpLoader(std::string filePath);
	Image loadImage();
};
