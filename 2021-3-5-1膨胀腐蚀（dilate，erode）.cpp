
//膨胀腐蚀（dilate，erode）
#include<opencv2/opencv.hpp>
#include<opencv2\imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
char input[] = "input";
char output[] = "imageWindow";
int start = 3;
int end1 = 15;//end和库函数一样导致不明确
//int end1 = 15;//end和库函数一样导致不明确
void callBack(int ,void* );
Mat src;
Mat dst = Mat::zeros(src.size(), src.type());
Mat dst1 = Mat::zeros(src.size(), src.type());
int main()
{
	
	//Mat src;
	src = imread("F:/image/1.8.png");
	if (src.empty())
	{
		printf("can not find the picture");
		return -1;
	}
	
	namedWindow(input,WINDOW_AUTOSIZE);
	imshow(input,src);
	namedWindow(output, WINDOW_AUTOSIZE);
	createTrackbar("digtal",output,&start,end1,callBack);//里面有一个窗口的命名，使用时，先使用namedWindow
	callBack(0,0);
	
	waitKey();
	return 0;
}

void callBack(int ,void*)
{
	int s = start * 2 + 1;
	Mat structeElement = getStructuringElement(MORPH_RECT,Size(s,s),Point(-1,-1));
	//dilate(src,dst,structeElement,Point(-1,-1),1);//膨胀
	//imshow(output, dst);
	//namedWindow("imageWindow", WINDOW_AUTOSIZE);
	erode(src, dst1, structeElement);//腐蚀
	imshow(output, dst1);
}