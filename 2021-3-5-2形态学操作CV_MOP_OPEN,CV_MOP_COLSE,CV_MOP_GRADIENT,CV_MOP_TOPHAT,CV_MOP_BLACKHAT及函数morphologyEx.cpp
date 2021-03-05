//形态学操作（CV_MOP_OPEN,CV_MOP_COLSE,CV_MOP_GRADIENT,CV_MOP_TOPHAT,CV_MOP_BLACKHAT）(函数:morphologyEx)
#include<opencv2/opencv.hpp>
#include<opencv2\imgproc.hpp>
//#include<opencv2\imgproc\types.c_h>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src;
	Mat dst = Mat::zeros(src.size(), src.type());
	Mat dst1 = Mat::zeros(src.size(), src.type());
	src = imread("F:/image/1.9.png");
	if (src.empty())
	{
		printf("can not find the picture");
		return -1;
	}
	char input[] = "input";
	char output[] = "CV_MOP_OPEN";
	char output1[] = "CV_MOP_OPEN+filter2D";
	namedWindow(input, WINDOW_AUTOSIZE);
	imshow(input, src);
	Mat kernel = getStructuringElement(MORPH_RECT,Size(15,15),Point(-1,-1));//size参数大小影响腐蚀效果
	morphologyEx(src, dst, MORPH_OPEN, kernel);//kernel结构体元素
	namedWindow(output, WINDOW_AUTOSIZE);
	imshow(output, dst);
	Mat kernel1 = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);//掩膜操作
	filter2D(dst,dst1, -1, kernel1);//提高对比度
	namedWindow(output1, WINDOW_AUTOSIZE);
	imshow(output1, dst1);
	waitKey();
	return 0;
}