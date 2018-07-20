#include<iostream>
#include<vector>
#include "AsciiImageConverter.h"
#include "imageLoaders\ImageLoader.h"
#include "imageLoaders\BmpLoader.h"
#include "Image.h"
#include <cstdio>
#include <cwchar>
#include <windows.h>

int main()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 12;
	cfi.dwFontSize.Y = 12;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	MoveWindow(GetConsoleWindow(), 100, 100, 1200, 600, TRUE);

	BmpLoader loader("C:\\Users\\GreenScreen\\Desktop\\test.bmp");
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