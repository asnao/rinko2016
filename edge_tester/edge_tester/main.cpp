#include <opencv2/opencv.hpp>
#include <opencv2/opencv_lib.hpp>

using namespace cv;


void edgeDiff();
void edgeSobel();
void edgeLaplacian();


int main(){

	edgeDiff();
	edgeSobel();
	edgeLaplacian();

	//OpenCVの関数．何かしらのボタンの入力があるまで，プログラムを止める．
	waitKey(0);
	return 0;
}

void edgeDiff(){

	//Mat型変数の宣言
	Mat inputImage, outputImage, tempImage;

	//画像の読み込み
	inputImage = imread("lena.jpg");

	//RGB画像をグレースケールに変換
	GaussianBlur(inputImage, outputImage, Size(11,11), 10, 10);

	//画像の表示
	imshow("gaussian",outputImage);
	//画像の書き出し
	imwrite("gaussian_lena.jpg",outputImage);

}

void edgeSobel(){

	//Mat型変数の宣言
	Mat inputImage, outputImage, tempImage;

	//画像の読み込み
	inputImage = imread("lena.jpg");
	
	cv::Sobel(inputImage, tempImage, CV_32F, 1, 1);
	cv::convertScaleAbs(tempImage, outputImage, 1, 0);
	
	//画像の表示
	imshow("Sobel",outputImage);
	//画像の書き出し
	imwrite("Sobel_lena.jpg",outputImage);

}

void edgeLaplacian(){

	//Mat型変数の宣言
	Mat inputImage, outputImage, tempImage;

	//画像の読み込み
	inputImage = imread("lena.jpg");

	Laplacian(inputImage, tempImage, CV_32F, 3);
	convertScaleAbs(tempImage, outputImage, 1, 0);

	//画像の表示
	imshow("median",outputImage);
	//画像の書き出し
	imwrite("median_lena.jpg",outputImage);

}


