#include "img_processing.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
int main(int argc, char** argv){
	Mat img = imread(argv[1]);
	Mat img_hsv;
	Mat field, lines, fieldLine, posts, ball;
	resize(img, img, Size(0,0), 2, 2);
	cvtColor(img, img_hsv, COLOR_BGR2HSV);
	fieldLine = img.clone();
	std::vector<cv::Point> background_border_points;
	vector<Point> goalRoots;
	double hor_hist[img_hsv.cols];
	int ver_hist[img_hsv.rows];

	remove_background(img_hsv, field, lines, background_border_points);
	cvtColor(field, field, COLOR_HSV2BGR);
	for(auto& point : background_border_points){
		circle(fieldLine, point, 2, Scalar(255, 0, 200));

	}
	imshow("img original", img);
	imshow("field Line", fieldLine);
	imshow("field", field);
	// imshow("lines", lines);
	waitKey();

	return 0;
}

