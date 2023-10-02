#include "HW1_3.h"

void HW1_3_a(unsigned char* img_lena, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int value = img_lena[j + i * width] + 70;
			if (value > 255)
				img_lena[j + i * width] = 255;
			else
				img_lena[j + i * width] = value;
		}
	}
}

void HW1_3_b(unsigned char* img_lena, int width, int height)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int value = (int)((double)rand() / RAND_MAX * 120 - 60);
			value = img_lena[j + i * width] + value;
			if (value > 255)
				img_lena[j + i * width] = 255;
			else if (value < 0)
				img_lena[j + i * width] = 0;
			else
				img_lena[j + i * width] = value;
		}
	}
}
