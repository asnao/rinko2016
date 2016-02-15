#include <opencv2/opencv.hpp>
#include <opencv2/opencv_lib.hpp>

using namespace cv;


int main(){

	const char th = 20;
	//Mat�^�ϐ��̐錾
	Mat inImg, bgImg, diffClrImg, diffGryImg, biBgImg, outImg;
	//�摜�̓ǂݍ���
	inImg = imread("input2.jpg");
	bgImg = imread("background2.jpg");

	imshow("in", inImg);
	imshow("bg", bgImg);
	waitKey(10);



	absdiff(inImg,bgImg,diffClrImg);//�w�i�摜�Ƃ̍������擾
    cvtColor(diffClrImg,diffGryImg,CV_BGR2GRAY);//�����摜���O���C�X�P�[����
    threshold(diffGryImg, biBgImg, th, 255, THRESH_BINARY);//��l���摜��
	
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
	
	//�摜�̕\��
	imshow("subtraction",outImg);
	//�摜�̏����o��
	imwrite("subtraction.jpg",outImg);


	//OpenCV�̊֐��D��������̃{�^���̓��͂�����܂ŁC�v���O�������~�߂�D
	waitKey(0);
	return 0;
}

