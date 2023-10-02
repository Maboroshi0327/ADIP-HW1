#ifndef HW1_2
#define HW1_2

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int HW1_2_a_1(unsigned char* data, int column, int row, int width, int height);
int HW1_2_a_2(unsigned char* data, int v, int width, int height);
void HW1_2_c(unsigned char* img_lena, int width, int height);
void HW1_2_d(unsigned char* img_lena, int width, int height);

static string number2ordinal(size_t number);
static void new_array(uint8_t*** Area, int width, int height);
static void delete_array(uint8_t*** Area, int width, int height);
static void cut_image(unsigned char* img_lena, uint8_t*** Area, int width, int height);
static void rotation_img(uint8_t*** Area, int width, int height);
static void rotation_90(uint8_t** Area, int width, int height);
static void add_img(unsigned char* img_lena, uint8_t*** Area, int width, int height);

#endif /* HW1_2 */