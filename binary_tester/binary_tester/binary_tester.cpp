#include <opencv2/opencv.hpp>
#include <opencv2/opencv_lib.hpp>

using namespace cv;


int main(){

	const char th = 20;
	//Mat型変数の宣言
	Mat inImg, bgImg, diffClrImg, diffGryImg, biBgImg, outImg;
	//画像の読み込み
	inImg = imread("input2.jpg");
	bgImg = imread("background2.jpg");

	imshow("in", inImg);
	imshow("bg", bgImg);
	waitKey(10);



	absdiff(inImg,bgImg,diffClrImg);//背景画像との差分を取得
    cvtColor(diffClrImg,diffGryImg,CV_BGR2GRAY);//差分画像をグレイスケールに
    threshold(diffGryImg, biBgImg, th, 255, THRESH_BINARY);//二値化画像化
	
	Mat bi3BgImg(inImg.rows,inImg.cols, CV_8UC3);

	for(int y = 0; y < inImg.rows; y++){
		for(int x = 0; x < inImg.cols; x++){
			for(int c = 0; c < 3; c++){
				bi3BgImg.data[y * inImg.cols * 3 + x * 3 + c] = biBgImg.data[y * inImg.cols + x];
			}
		}
	}

	bitwise_and(inImg,bi3BgImg,outImg);

	cv::erode(outImg, outImg, cv::Mat(), cv::Point(-1,-1), 10);
	cv::dilate(outImg, outImg, cv::Mat(), cv::Point(-1,-1), 10);
//	cv::dilate(outImg, outImg, cv::Mat(), cv::Point(-1,-1), 2);
//	cv::erode(outImg, outImg, cv::Mat(), cv::Point(-1,-1), 2);
	
	//画像の表示
	imshow("subtraction",outImg);
	//画像の書き出し
	imwrite("subtraction.jpg",outImg);


	//OpenCVの関数．何かしらのボタンの入力があるまで，プログラムを止める．
	waitKey(0);
	return 0;
}

