#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    // 1. 이미지 로드
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 조건 1: 모든 원소가 1/9(약 0.1111)인 3x3 필터 마스크 정의
    float data[] = {
        1.0f / 9.0f, 1.0f / 9.0f, 1.0f / 9.0f,
        1.0f / 9.0f, 1.0f / 9.0f, 1.0f / 9.0f,
        1.0f / 9.0f, 1.0f / 9.0f, 1.0f / 9.0f
    };
    Mat blur_kernel(3, 3, CV_32FC1, data);

    Mat dst;

    // 조건 2: delta 매개변수를 128에서 -> 0으로 설정
    filter2D(src, dst, -1, blur_kernel, Point(-1, -1), 0);

    // 결과 출력
    imshow("src", src);
    imshow("dst", dst);
    waitKey();

    return 0;
}