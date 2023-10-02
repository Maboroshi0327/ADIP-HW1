#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstdint>
#include <iostream>
#include "HW1_2/HW1_2.h"
#include "HW1_3/HW1_3.h"
#include "HW2_b/HW2_b.h"

using namespace std;

int main()
{
	//-----------------------1. Initial variable-----------------------//
	char  input_img[] = "lena256.raw";                 // Input  raw image name
	char output_img[] = "lena256_out.raw";              // Output raw image name
	FILE* input_file;
	FILE* output_file;
	int width = 256;
	int height = 256;
	int size = width * height;
	unsigned char* img_lena = new unsigned char[size]; // array for image data

	//-----------------------2. Read File-----------------------//
	// using fopen as example, fstream works too
	input_file = fopen(input_img, "rb");
	if (input_file == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	fread(img_lena, 1, size, input_file);

	//-----------------------3. Homework -----------------------//
	int input_cmd;
	cout << "1:1.2_a anwser\n"
		<< "2:1.2_b anwser\n"
		<< "3:1.2_c anwser\n"
		<< "4:1.2_d anwser\n"
		<< "5:1.3_a anwser\n"
		<< "6:1.3_b anwser\n"
		<< "7:2_b anwser\n"
		<< "Enter the question number to select output result: ";
	cin >> input_cmd;

	switch (input_cmd)
	{
	case 1:
#pragma region 1.2_a
		HW1_2_a_1(img_lena, 42, 145, width, height);
		HW1_2_a_2(img_lena, 42019, width, height);
#pragma endregion 1.2_a
		break;

	case 2:
#pragma region 1.2_b
		output_file = fopen(output_img, "wb");
		fwrite(img_lena, 1, size, output_file);
		fclose(output_file);
#pragma endregion 1.2_b
		break;

	case 3:
#pragma region 1.2_c
		HW1_2_c(img_lena, width, height);

		output_file = fopen("1_2_c.raw", "wb");
		fwrite(img_lena, 1, size, output_file);
		fclose(output_file);
#pragma endregion 1.2_c
		break;

	case 4:
#pragma region 1.2_d
		HW1_2_d(img_lena, width, height);

		output_file = fopen("1_2_d.raw", "wb");
		fwrite(img_lena, 1, size, output_file);
		fclose(output_file);
#pragma endregion 1.2_d
		break;

	case 5:
#pragma region 1.3_a
		HW1_3_a(img_lena, width, height);

		output_file = fopen("1_3_a.raw", "wb");
		fwrite(img_lena, 1, size, output_file);
		fclose(output_file);
#pragma endregion 1.3_a
		break;

	case 6:
#pragma region 1.3_b
		HW1_3_b(img_lena, width, height);

		output_file = fopen("1_3_b.raw", "wb");
		fwrite(img_lena, 1, size, output_file);
		fclose(output_file);
#pragma endregion 1.3_b
		break;

	case 7:
#pragma region 2_b
		HW2_b();
#pragma endregion 2_b
		break;
	}

	//-----------------------4. Release memory-----------------------//
	delete[] img_lena;
	fclose(input_file);
}
