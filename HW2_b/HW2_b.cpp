#include "HW2_b.h"

void HW2_b()
{
	Mat img = Mat::zeros(Size(512, 512), CV_8UC3);
	img.setTo(255);

	// head
	circle(img, Point(256, 256), 204, Scalar(0, 0, 0), 7);
	circle(img, Point(256, 256), 200, Scalar(128, 128, 128), -1);

	// face
	ellipse(img, Point(256, 256), Size(200, 200), 0, 10, 170, Scalar(255, 255, 255), -1);
	ellipse(img, Point(256, 296), Size(196, 108), 0, 0, -180, Scalar(0, 0, 0), 6);
	ellipse(img, Point(256, 296), Size(193, 105), 0, 0, -180, Scalar(255, 255, 255), -1);

	// eyes right
	ellipse(img, Point(205, 175), Size(50, 60), 0, 0, 360, Scalar(0, 0, 0), 5);
	ellipse(img, Point(205, 175), Size(48, 58), 0, 0, 360, Scalar(255, 255, 255), -1);
	ellipse(img, Point(226, 186), Size(10, 14), 0, 0, 360, Scalar(0, 0, 0), 9);

	// eyes left
	ellipse(img, Point(307, 175), Size(50, 60), 0, 0, 360, Scalar(0, 0, 0), 5);
	ellipse(img, Point(307, 175), Size(48, 58), 0, 0, 360, Scalar(255, 255, 255), -1);
	ellipse(img, Point(286, 186), Size(10, 14), 0, 0, 360, Scalar(0, 0, 0), 9);

	// nose
	circle(img, Point(256, 247), 26, Scalar(0, 0, 0), 5);
	circle(img, Point(256, 247), 23, Scalar(128, 128, 128), -1);
	circle(img, Point(251, 241), 6, Scalar(255, 255, 255), -1);

	// mouth
	line(img, Point(256, 274), Point(256, 406), Scalar(0, 0, 0), 5);
	ellipse(img, Point(256, 305), Size(128, 101), 0, 5, 175, Scalar(0, 0, 0), 5);

	// whiskers right
	line(img, Point(179, 284), Point(56, 249), Scalar(0, 0, 0), 5);
	line(img, Point(179, 306), Point(61, 296), Scalar(0, 0, 0), 5);
	line(img, Point(179, 329), Point(87, 364), Scalar(0, 0, 0), 5);

	// whiskers left
	line(img, Point(333, 284), Point(456, 249), Scalar(0, 0, 0), 5);
	line(img, Point(333, 306), Point(451, 296), Scalar(0, 0, 0), 5);
	line(img, Point(333, 329), Point(425, 364), Scalar(0, 0, 0), 5);

	// student ID
	putText(img, "112318053", Point(168, 500), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 0), 2);

	imwrite("2_b.png", img);
	imshow("Doraemon", img);
	waitKey();
}

