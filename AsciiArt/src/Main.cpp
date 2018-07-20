#include <iostream>
#include <vector>
#include "Image.h"
#include <cstdio>
#include <cwchar>
#include <windows.h>
#include <algorithm>
#include "Settings.h"
#include "AsciiImageConverter.h"
#include "imageLoaders\ImageLoader.h"
#include "imageLoaders\BmpLoader.h"
#include "imageSavers\TxtImageSaver.h"

void setupConsole(int width, int height, int fontSize);

int main(int argc, char* argv[])
{
	Settings settings(argv, argc);

	std::string result = settings.loadSettings();

	if (result.compare("") != 0)
	{
		std::cout << "ERROR: " << result.c_str() << std::endl;
		std::cin.get();
		return 0;
	}

	if (!settings.hasSetting("src"))
	{
		std::cout << "You did not provide source file path. Use '-src' to specify source file path." << std::endl;
		std::cin.get();
		return 0;
	}

	BmpLoader loader(settings.getSetting("src"));
	Image image = loader.loadImage();

	AsciiImageConverter converter;
	Image ascii = converter.toAscii(image);

	int fontSize = std::max<int>(std::floor(1200 / (ascii.width * 1.5)), 1);
	setupConsole(1200, 600, fontSize);

	for (int y = 0; y < ascii.height; y++)
	{
		for (int x = 0; x < ascii.width; x++)
		{
			std::cout << ascii.pixels[y * ascii.width + x];
		}
		std::cout << std::endl;
	}

	if (settings.hasSetting("out"))
	{
		TxtImageSaver saver;
		saver.save(settings.getSetting("out"), ascii);

		std::cout << "Image saved in " << settings.getSetting("out").c_str() << std::endl;
	}

	std::cin.get();
	return 0;
}

void setupConsole(int width, int height, int fontSize)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = fontSize;
	cfi.dwFontSize.Y = fontSize;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	MoveWindow(GetConsoleWindow(), 100, 100, width, height, TRUE);
}

//for (int y = 0; y < image.height; y++)
//{
//	for (int x = 0; x < image.width; x++)
//	{
//		std::cout << std::hex << +(unsigned char)image.pixels[y * image.width + x] << " ";
//	}
//	std::cout << std::endl;
//}