#pragma once
#include <iostream>
#include <fstream>
#include "../Image.h"

class TxtImageSaver
{
public:
	void save(std::string filePath, Image& image);
};
