#include "HW1_2.h"

int HW1_2_a_1(unsigned char* data, int row, int column, int width, int height)
{
	if (0 <= column && column < width && 0 <= row && row < height)
	{
		cout << number2ordinal(row) << " row & " << number2ordinal(column) << " column intensity: "
			<< (int)data[column + row * width] << endl;
		return 0;
	}
	else
	{
		cout << "error: column(" << column << "), row(" << row << ") is outside the range. <HW1_2_a_1>" << endl;
		return -1;
	}
}

int HW1_2_a_2(unsigned char* data, int v, int width, int height)
{
	int size = width * height;
	if (0 <= v && v < size)
	{
		int column = v % width;
		int row = v / width;
		cout << number2ordinal(v) << " intensity: " << (int)data[column + row * width] << endl;
		cout << "pixel coordinate: " << number2ordinal(row) << " row & " << number2ordinal(column) << " column" << endl;
		return 0;
	}
	else
	{
		cout << "error: " << v << " is outside the range. <HW1_2_a_2>" << endl;
		return -1;
	}
}

void HW1_2_c(unsigned char* img_lena, int width, int height)
{
	uint8_t** Area[8];
	new_array(Area, width, height);
	cut_image(img_lena, Area, width, height);
	rotation_img(Area, width, height);
	add_img(img_lena, Area, width, height);
	delete_array(Area, width, height);
}

void HW1_2_d(unsigned char* img_lena, int width, int height)
{
	for (int i = 0; i < height; i += 8)
	{
		for (int j = 0; j < width; j += 8)
		{
			unsigned char min = 255;
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					int index = (j + y) + (i + x) * width;
					if (min > img_lena[index])
						min = img_lena[index];
				}
			}
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					int index = (j + y) + (i + x) * width;
					img_lena[index] = min;
				}
			}
		}
	}
}

static string number2ordinal(size_t number)
{
	string suffix = "th";
	if (number % 100 < 11 || number % 100 > 13)
	{
		switch (number % 10)
		{
		case 1:
			suffix = "st";
			break;
		case 2:
			suffix = "nd";
			break;
		case 3:
			suffix = "rd";
			break;
		}
	}
	return to_string(number) + suffix;
}

static void new_array(uint8_t*** Area, int width, int height)
{
	for (int a = 0; a < 8; a++)
	{
		Area[a] = new uint8_t * [height];
		for (int i = 0; i < height; i++)
			Area[a][i] = new uint8_t[width];

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				Area[a][i][j] = 0;
	}
}

static void delete_array(uint8_t*** Area, int width, int height)
{
	for (int a = 0; a < 8; a++)
	{
		for (int i = 0; i < height; i++)
			delete[] Area[a][i];
		delete[] Area[a];
	}
}

static void cut_image(unsigned char* img_lena, uint8_t*** Area, int width, int height)
{
	// Area[0]
	for (int i = 0; i <= 126; i++)
		for (int j = 0; j <= (126 - i); j++)
			Area[0][i][j] = img_lena[j + i * width];

	// Area[1]
	for (int i = 0; i <= 127; i++)
		for (int j = (127 - i); j <= 127; j++)
			Area[1][i][j] = img_lena[j + i * width];

	// Area[2]
	for (int i = 0; i <= 127; i++)
		for (int j = 128; j <= (128 + i); j++)
			Area[2][i][j] = img_lena[j + i * width];

	// Area[3]
	for (int i = 0; i <= 126; i++)
		for (int j = (129 + i); j <= 255; j++)
			Area[3][i][j] = img_lena[j + i * width];

	// Area[4]
	for (int i = 129; i <= 255; i++)
		for (int j = 0; j <= (i - 129); j++)
			Area[4][i][j] = img_lena[j + i * width];

	// Area[5]
	for (int i = 128; i <= 255; i++)
		for (int j = (i - 128); j <= 127; j++)
			Area[5][i][j] = img_lena[j + i * width];

	// Area[6]
	for (int i = 128; i <= 255; i++)
		for (int j = 128; j <= (255 + 128 - i); j++)
			Area[6][i][j] = img_lena[j + i * width];

	// Area[7]
	for (int i = 129; i <= 255; i++)
		for (int j = (255 + 129 - i); j <= 255; j++)
			Area[7][i][j] = img_lena[j + i * width];
}

static void rotation_img(uint8_t*** Area, int width, int height)
{
	// Area[0]
	rotation_90(Area[0], width, height);

	// Area[1]

	// Area[2]
	rotation_90(Area[2], width, height);
	rotation_90(Area[2], width, height);

	// Area[3]
	rotation_90(Area[3], width, height);

	// Area[4]

	// Area[5]
	rotation_90(Area[5], width, height);
	rotation_90(Area[5], width, height);

	// Area[6]

	// Area[7]
	rotation_90(Area[7], width, height);
	rotation_90(Area[7], width, height);
}

static void rotation_90(uint8_t** Area, int width, int height)
{
	uint8_t** output = new uint8_t * [height];
	for (int i = 0; i < height; i++)
		output[i] = new uint8_t[width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			output[i][j] = 0;

	for (int i = 0; i < height; i++)
		for (int j = -255; j <= 0; j++)
			output[i][j + 255] = Area[-j][i];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			Area[i][j] = output[i][j];

	for (int i = 0; i < height; i++)
		delete[] output[i];
	delete[] output;
}

static void add_img(unsigned char* img_lena, uint8_t*** Area, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img_lena[j + i * width] = 0;
			for (int a = 0; a < 8; a++)
				img_lena[j + i * width] += Area[a][i][j];
		}
	}
}
