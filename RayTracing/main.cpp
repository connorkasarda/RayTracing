#include <iostream>
#include <fstream>

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
		for (int w = 0; w < image_width; ++w)
		{
			auto r = double(w) / (image_width - 1);
			auto g = double(h) / (image_height - 1);
			auto b = 0.0;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			image_file << ir << " " << ig << " " << ib << std::endl;
		}
	}

	// Finish writing to ppm image file
	image_file.close();

	// End successfully
	return 0;
}