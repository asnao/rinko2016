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

	//OpenCV�̊֐��D��������̃{�^���̓��͂�����܂ŁC�v���O�������~�߂�D
	waitKey(0);
	return 0;
}

void edgeDiff(){

	//Mat�^�ϐ��̐錾
	Mat inputImage, outputImage, tempImage;

	//�摜�̓ǂݍ���
	inputImage = imread("lena.jpg");

	//RGB�摜���O���[�X�P�[���ɕϊ�
	GaussianBlur(inputImage, outputImage, Size(11,11), 10, 10);

	//�摜�̕\��
	imshow("gaussian",outputImage);
	//�摜�̏����o��
	imwrite("gaussian_lena.jpg",outputImage);

}

void edgeSobel(){

	//Mat�^�ϐ��̐錾
	Mat inputImage, outputImage, tempImage;

	//�摜�̓ǂݍ���
	inputImage = imread("lena.jpg");
	
	cv::Sobel(inputImage, tempImage, CV_32F, 1, 1);
	cv::convertScaleAbs(tempImage, outputImage, 1, 0);
	
	//�摜�̕\��
	imshow("Sobel",outputImage);
	//�摜�̏����o��
	imwrite("Sobel_lena.jpg",outputImage);

}

void edgeLaplacian(){

	//Mat�^�ϐ��̐錾
	Mat inputImage, outputImage, tempImage;

	//�摜�̓ǂݍ���
	inputImage = imread("lena.jpg");

	Laplacian(inputImage, tempImage, CV_32F, 3);
	convertScaleAbs(tempImage, outputImage, 1, 0);

	//�摜�̕\��
	imshow("median",outputImage);
	//�摜�̏����o��
	imwrite("median_lena.jpg",outputImage);

}


