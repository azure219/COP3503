#include <iostream>
#include <fstream>
#include <vector>
#include "Photoshop.h"

using namespace std;

// Header Functions

Header::Header() {

	idLength = 0;
	colorMapType = 0;
	dataTypeCode = 0;
	colorMapOrigin = 0;
	colorMapLength = 0;
	colorMapDepth = 0;
	xOrigin = 0;
	yOrigin = 0;
	width = 0;
	height = 0;
	bitsPerPixel = 0;
	imageDescriptor = 0;

}

// Pixel Functions

Pixel::Pixel() {

	blue = 0;
	green = 0;
	red = 0;

}

Pixel::Pixel(unsigned char b, unsigned char g, unsigned char r) {

	blue = b;
	green = g;
	red = r;

}

unsigned char Pixel::returnColor(int c) {

	if (c == 1) {

		return blue;

	}
	else if (c == 2) {

		return green;

	}
	else if (c == 3) {

		return red;

	}
	else {

		return 0;

	}

}

// Image Functions

Image::Image() {

	head = Header();
	width = 0;
	height = 0;

}

Image::Image(Header h) {

	head = h;
	width = h.width;
	height = h.height;

}

void Image::Add(Pixel& p) {

	pixels.push_back(p);

}

Header Image::returnHeader() {

	return head;

}

int Image::returnSize() {

	return pixels.size();

}

Pixel Image::returnPixelAt(int x) {

	return pixels.at(x);

}

void Image::replacePixels(vector<Pixel> rp) {

	pixels = rp;

}

Image Image::readImage(string filepath) {

	ifstream imagefile(filepath, ios_base::binary);

	Header head = Header();

	imagefile.read(&head.idLength, 1);
	imagefile.read(&head.colorMapType, 1);
	imagefile.read(&head.dataTypeCode, 1);

	imagefile.read((char*)&head.colorMapOrigin, 2);
	imagefile.read((char*)&head.colorMapLength, 2);

	imagefile.read(&head.colorMapDepth, 1);

	imagefile.read((char*)&head.xOrigin, 2);
	imagefile.read((char*)&head.yOrigin, 2);
	imagefile.read((char*)&head.width, 2);
	imagefile.read((char*)&head.height, 2);

	imagefile.read(&head.bitsPerPixel, 1);
	imagefile.read(&head.imageDescriptor, 1);

	/*cout << endl << "FILENAME: " << filepath << endl;
	cout << "ID Length: " << (int)head.idLength << endl;
	cout << "Color Map Type: " << (int)head.colorMapType << endl;
	cout << "Data Type Code : " << (int)head.dataTypeCode << endl;
	cout << "Color Map Origin: " << (int)head.colorMapOrigin << endl;
	cout << "Color Map Length: " << (int)head.colorMapLength << endl;
	cout << "Color Map Depth: " << (int)head.colorMapDepth << endl;
	cout << "X Origin: " << (int)head.xOrigin << endl;
	cout << "Y Origin: " << (int)head.yOrigin << endl;
	cout << "Width: " << (int)head.width << endl;
	cout << "Height: " << (int)head.height << endl;
	cout << "Bits Per Pixel: " << (int)head.bitsPerPixel << endl;
	cout << "Image Descriptor: " << (int)head.imageDescriptor << endl;*/

	Image im = Image(head);

	for (int n = 0; n < (head.width * head.height); n++) {

		char blue_;
		char green_;
		char red_;

		imagefile.read(&blue_, sizeof(blue_));
		imagefile.read(&green_, sizeof(green_));
		imagefile.read(&red_, sizeof(red_));

		Pixel pixel = Pixel(blue_, green_, red_);

		im.Add(pixel);

	}

	return im;

}

void copyImage(string filepath, Image& im) {

	ofstream imagefile(filepath, ios_base::binary);

	Header head = im.returnHeader();

	imagefile.write(&head.idLength, 1);
	imagefile.write(&head.colorMapType, 1);
	imagefile.write(&head.dataTypeCode, 1);

	imagefile.write((char*)&head.colorMapOrigin, 2);
	imagefile.write((char*)&head.colorMapLength, 2);

	imagefile.write(&head.colorMapDepth, 1);

	imagefile.write((char*)&head.xOrigin, 2);
	imagefile.write((char*)&head.yOrigin, 2);
	imagefile.write((char*)&head.width, 2);
	imagefile.write((char*)&head.height, 2);

	imagefile.write(&head.bitsPerPixel, 1);
	imagefile.write(&head.imageDescriptor, 1);

	for (int n = 0; n < (head.width * head.height); n++) {

		char blue_ = im.returnPixelAt(n).returnColor(1);
		char green_ = im.returnPixelAt(n).returnColor(2);
		char red_ = im.returnPixelAt(n).returnColor(3);

		imagefile.write((char*)&blue_, sizeof(blue_));
		imagefile.write((char*)&green_, sizeof(green_));
		imagefile.write((char*)&red_, sizeof(red_));

	}

}

// Manipulation Functions

Image multiply(Image& top, Image& bottom) {

	Image t(top.returnHeader());

	for (int n = 0; n < (top.returnSize()); n++) {

		float blueTP = (float(top.returnPixelAt(n).returnColor(1)) / 255.0);
		float greenTP = (float(top.returnPixelAt(n).returnColor(2)) / 255.0);
		float redTP = (float(top.returnPixelAt(n).returnColor(3)) / 255.0);

		float blueBP = (float(bottom.returnPixelAt(n).returnColor(1)) / 255.0);
		float greenBP = (float(bottom.returnPixelAt(n).returnColor(2)) / 255.0);
		float redBP = (float(bottom.returnPixelAt(n).returnColor(3)) / 255.0);

		unsigned char b = (unsigned char)((blueTP * blueBP * 255.0) + 0.5f);
		unsigned char g = (unsigned char)((greenTP * greenBP * 255.0) + 0.5f);
		unsigned char r = (unsigned char)((redTP * redBP * 255.0) + 0.5f);

		Pixel pixel = Pixel(b, g, r);
		t.Add(pixel);

	}

	return t;

}

Image subtract2(Image& bottom, Image& top) {

	Image t(top.returnHeader());

	for (int n = 0; n < (top.returnSize()); n++) {

		float blueTP = ((top.returnPixelAt(n).returnColor(1)));
		float greenTP = ((top.returnPixelAt(n).returnColor(2)));
		float redTP = ((top.returnPixelAt(n).returnColor(3)));

		float blueBP = ((bottom.returnPixelAt(n).returnColor(1)));
		float greenBP = ((bottom.returnPixelAt(n).returnColor(2)));
		float redBP = ((bottom.returnPixelAt(n).returnColor(3)));

		float tempB = (blueBP - blueTP);
		float tempG = (greenBP - greenTP);
		float tempR = (redBP - redTP);

		if (tempB < 0) {

			tempB = 0;

		}

		if (tempG < 0) {

			tempG = 0;

		}

		if (tempR < 0) {

			tempR = 0;

		}

		char b = char(tempB);
		char g = char(tempG);
		char r = char(tempR);

		// Pixel pixel = Pixel(blueBP, greenBP, redBP);

		Pixel pixel = Pixel(b, g, r);
		t.Add(pixel);

	}

	return t;
}

Image subtract(Image& top, Image& bottom) {

	Image t(top.returnHeader());

	for (int n = 0; n < (top.returnSize()); n++) {

		float blueTP = ((top.returnPixelAt(n).returnColor(1)));
		float greenTP = ((top.returnPixelAt(n).returnColor(2)));
		float redTP = ((top.returnPixelAt(n).returnColor(3)));

		float blueBP = ((bottom.returnPixelAt(n).returnColor(1)));
		float greenBP = ((bottom.returnPixelAt(n).returnColor(2)));
		float redBP = ((bottom.returnPixelAt(n).returnColor(3)));

		float tempB = (blueBP - blueTP);
		float tempG = (greenBP - greenTP);
		float tempR = (redBP - redTP);

		if (tempB < 0) {

			tempB = 0;

		}

		if (tempG < 0) {

			tempG = 0;

		}

		if (tempR < 0) {

			tempR = 0;

		}

		char b = char(tempB);
		char g = char(tempG);
		char r = char(tempR);

		// Pixel pixel = Pixel(blueBP, greenBP, redBP);

		Pixel pixel = Pixel(b, g, r);
		t.Add(pixel);

	}

	return t;
}

Image screen(Image& top, Image& one, Image& two) {

	Image t(top.returnHeader());

	Image m(multiply(one, two));

	for (int n = 0; n < (top.returnSize()); n++) {

		float blueTP = (float(top.returnPixelAt(n).returnColor(1)) / 255.0);
		float greenTP = (float(top.returnPixelAt(n).returnColor(2)) / 255.0);
		float redTP = (float(top.returnPixelAt(n).returnColor(3)) / 255.0);

		float blueBP = (float(m.returnPixelAt(n).returnColor(1)) / 255.0);
		float greenBP = (float(m.returnPixelAt(n).returnColor(2)) / 255.0);
		float redBP = (float(m.returnPixelAt(n).returnColor(3)) / 255.0);

		float tempB = (1.0 - ((1.0 - blueTP) * (1.0 - blueBP)));
		float tempG = (1.0 - ((1.0 - greenTP) * (1.0 - greenBP)));
		float tempR = (1.0 - ((1.0 - redTP) * (1.0 - redBP)));

		if (tempB < 0) {

			tempB = 0;

		}

		if (tempG < 0) {

			tempG = 0;

		}

		if (tempR < 0) {

			tempR = 0;

		}

		char b = char(tempB * 255 + 0.5f);
		char g = char(tempG * 255 + 0.5f);
		char r = char(tempR * 255 + 0.5f);

		Pixel pixel = Pixel(b, g, r);
		t.Add(pixel);

	}

	return t;
}

Image overlay(Image& top, Image& bottom) {

	Image t(top.returnHeader());

	for (int n = 0; n < (top.returnSize()); n++) {

		float blueTP = (float(top.returnPixelAt(n).returnColor(1)) / 255.0);
		float greenTP = (float(top.returnPixelAt(n).returnColor(2)) / 255.0);
		float redTP = (float(top.returnPixelAt(n).returnColor(3)) / 255.0);

		float blueBP = (float(bottom.returnPixelAt(n).returnColor(1)) / 255.0);
		float greenBP = (float(bottom.returnPixelAt(n).returnColor(2)) / 255.0);
		float redBP = (float(bottom.returnPixelAt(n).returnColor(3)) / 255.0);

		unsigned char b = 0;
		unsigned char g = 0;
		unsigned char r = 0;

		if (blueBP <= 0.5) {

			b = (unsigned char)((2.0 * blueTP * blueBP) * 255.0 + 0.5f);

		}
		else if (blueBP > 0.5) {

			b = (unsigned char)((1.0 - (2.0 * (1.0 - blueTP) * (1.0 - blueBP))) * 255.0 + 0.5f);

		}

		if (greenBP <= 0.5) {

			g = (unsigned char)((2.0 * greenTP * greenBP) * 255.0 + 0.5f);

		}
		else if (greenBP > 0.5) {

			g = (unsigned char)((1.0 - (2.0 * (1.0 - greenTP) * (1.0 - greenBP))) * 255.0 + 0.5f);

		}

		if (redBP <= 0.5) {

			r = (unsigned char)((2.0 * redTP * redBP) * 255.0 + 0.5f);

		}
		else if (redBP > 0.5) {

			r = (unsigned char)((1.0 - (2.0 * (1.0 - redTP) * (1.0 - redBP))) * 255.0 + 0.5f);

		}

		Pixel pixel = Pixel(b, g, r);
		t.Add(pixel);

	}

	return t;

}

Image addBGR(Image& top, unsigned char blue, unsigned char green, unsigned char red) {

	Image t(top.returnHeader());

	for (int n = 0; n < (top.returnSize()); n++) {

		int blueTP = ((top.returnPixelAt(n).returnColor(1)));
		int greenTP = ((top.returnPixelAt(n).returnColor(2)));
		int redTP = ((top.returnPixelAt(n).returnColor(3)));

		int tempB = (blueTP + blue);
		int tempG = (greenTP + green);
		int tempR = (redTP + red);

		if (tempB > 255) {

			tempB = 255;

		}

		if (tempG > 255) {

			tempG = 255;

		}

		if (tempR > 255) {

			tempR = 255;

		}

		char b = char(tempB);
		char g = char(tempG);
		char r = char(tempR);

		// Pixel pixel = Pixel(blueBP, greenBP, redBP);

		Pixel pixel = Pixel(b, g, r);
		t.Add(pixel);

	}

	return t;
}

Image multiplyBGR(Image& top, unsigned char blue, unsigned char green, unsigned char red) {

	Image t(top.returnHeader());

	for (int n = 0; n < (top.returnSize()); n++) {

		int blueTP = ((top.returnPixelAt(n).returnColor(1)));
		int greenTP = ((top.returnPixelAt(n).returnColor(2)));
		int redTP = ((top.returnPixelAt(n).returnColor(3)));

		int tempB = (blueTP * blue);
		int tempG = (greenTP * green);
		int tempR = (redTP * red);

		if (tempB > 255) {

			tempB = 255;

		}

		if (tempG > 255) {

			tempG = 255;

		}

		if (tempR > 255) {

			tempR = 255;

		}

		char b = char(tempB);
		char g = char(tempG);
		char r = char(tempR);

		// Pixel pixel = Pixel(blueBP, greenBP, redBP);

		Pixel pixel = Pixel(b, g, r);
		t.Add(pixel);

	}

	return t;

}

vector<Image> seperate(Image& top) {

	vector<Image> images;
	Image blue(top.returnHeader());
	Image green(top.returnHeader());
	Image red(top.returnHeader());

	for (int n = 0; n < (top.returnSize()); n++) {

		float blueTP = (float(top.returnPixelAt(n).returnColor(1)));
		float greenTP = (float(top.returnPixelAt(n).returnColor(2)));
		float redTP = (float(top.returnPixelAt(n).returnColor(3)));

		Pixel bluePixel = Pixel(blueTP, blueTP, blueTP);
		blue.Add(bluePixel);

		Pixel greenPixel = Pixel(greenTP, greenTP, greenTP);
		green.Add(greenPixel);

		Pixel redPixel = Pixel(redTP, redTP, redTP);
		red.Add(redPixel);

	}

	images.push_back(blue);
	images.push_back(green);
	images.push_back(red);

	return images;

}

Image combine(Image& red, Image& green, Image& blue) {

	Image t(blue.returnHeader());

	for (int n = 0; n < (blue.returnSize()); n++) {

		float blueTP = (float(blue.returnPixelAt(n).returnColor(1)));
		float greenTP = (float(green.returnPixelAt(n).returnColor(2)));
		float redTP = (float(red.returnPixelAt(n).returnColor(3)));

		Pixel pixel = Pixel(blueTP, greenTP, redTP);
		t.Add(pixel);

	}

	return t;

}

Image flip(Image& top) {

	Image t(top.returnHeader());

	for (int n = (top.returnSize() - 1); n >= 0; n--) {

		Pixel pixel = top.returnPixelAt(n);

		t.Add(pixel);

	}

	return t;

}

bool checkTGA(string file, string ending) {

	if (file.length() < ending.length()) {

		return false;

	}

	return equal(ending.rbegin(), ending.rend(), file.rbegin());

}

bool checkInt(string input) {

	for (int i = 0; i < input.length(); i++) {

		if (!isdigit(input[i])) {

			return false;

		}
	}

	return true;

}