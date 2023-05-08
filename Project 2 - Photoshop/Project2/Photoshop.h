#include <iostream>
#include <fstream>
#include <vector>
#pragma once

using namespace std;

class Header {

public:

	Header();

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

};

class Pixel {

public:

	Pixel();
	Pixel(unsigned char b, unsigned char g, unsigned char r);
	unsigned char returnColor(int c);

private:

	unsigned char blue;
	unsigned char green;
	unsigned char red;

};

class Image {

public:

	Image();
	Image(Header h);

	void Add(Pixel& p);

	Header returnHeader();
	int returnSize();
	Pixel returnPixelAt(int x);
	void replacePixels(vector<Pixel> rp);

	Image readImage(string filepath);
	//		void copyImage(string filepath, Image& im);

private:

	vector<Pixel> pixels;

	Header head;
	short width;
	short height;

};

void copyImage(string filepath, Image& im);

bool checkInt(string input);
bool checkTGA(string file, string ending);

Image multiply(Image& top, Image& bottom);
Image subtract2(Image& top, Image& bottom);
Image subtract(Image& top, Image& bottom);
Image addBGR(Image& top, unsigned char blue, unsigned char green, unsigned char red);
Image multiplyBGR(Image& top, unsigned char blue, unsigned char green, unsigned char red);
Image screen(Image& top, Image& one, Image& two);
Image overlay(Image& top, Image& bottom);
vector<Image> seperate(Image& top);
Image combine(Image& blue, Image& green, Image& red);
Image flip(Image& top);




