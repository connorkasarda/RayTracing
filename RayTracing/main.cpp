#include <iostream>
#include <fstream>
#include "Color.h"

int main(int argc, char** argv)
{
	// Open/create ppm file
	std::ofstream image_file("image.ppm");
	if (!image_file)
	{
		std::cerr << "Failed to open ppm image file!" << std::endl;
		return 1;
	}

	// Image size
	int image_width = 256;
	int image_height = 256;

	// Write the header for the PPM file
	image_file << "P3\n" << image_width << " " << image_height << "\n255\n";

	// Render image
	for (int h = 0; h < image_height; ++h)
	{
		// Progress indicator
		std::clog << "\rScanlines remaining: " << (image_height - h) << " " << std::flush;

		// Write pixels
		for (int w = 0; w < image_width; ++w)
		{
			auto pixelColor = Color(
				double(w) / (image_width - 1),
				double(h) / (image_height - 1),
				0.0);

			printColor(image_file, pixelColor);
		}
	}

	// Indicate completion
	std::clog << "\rDone.\t\t\t\t" << std::endl;

	// Finish writing to ppm image file
	image_file.close();

	// End successfully
	return 0;
}