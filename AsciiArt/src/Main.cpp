#include<iostream>
#include<vector>
#include "AsciiImageConverter.h"
#include "imageLoaders\ImageLoader.h"
#include "imageLoaders\BmpLoader.h"
#include "Image.h"
#include <cstdio>
#include <cwchar>
#include <windows.h>
#include "Settings.h"

void setupConsole(int width, int height, int fontSize);

int main(int argc, char* argv[])
{
	Settings settings(argv, argc);

	std::string result = settings.loadSettings();

	if (result.compare("") != 0)
	{
		std::cout << result.c_str() << std::endl;
		std::cin.get();
		return 0;
	}

	if (!settings.hasSetting("src"))
	{
		std::cout << "You did not provid source file path. Use '-src' to specify source file path." << std::endl;
		std::cin.get();
		return 0;
	}

	//setupConsole(1200, 600, 12);

	BmpLoader loader(settings.getSetting("src"));
	Image image = loader.loadImage();

	AsciiImageConverter converter;
	Image ascii = converter.toAscii(image);

	//for (int y = 0; y < image.height; y++)
	//{
	//	for (int x = 0; x < image.width; x++)
	//	{
	//		std::cout << std::hex << +(unsigned char)image.pixels[y * image.width + x] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	for (int y = 0; y < ascii.height; y++)
	{
		for (int x = 0; x < ascii.width; x++)
		{
			std::cout << ascii.pixels[y * ascii.width + x];
		}
		std::cout << std::endl;
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