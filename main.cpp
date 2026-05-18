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

    // 조건 1: 제시된 3x3 소벨 필터 마스크 정의
    float data[] = {
        -1.0f,  0.0f,  1.0f,
        -2.0f,  0.0f,  2.0f,
        -1.0f,  0.0f,  1.0f
    };
    Mat sobel_kernel(3, 3, CV_32FC1, data);

    Mat dst_0;
    Mat dst_128;

    // 조건 2: delta 매개변수를 0과 128 두 가지로 설정하여 각각 연산
    filter2D(src, dst_0, -1, sobel_kernel, Point(-1, -1), 0);
    filter2D(src, dst_128, -1, sobel_kernel, Point(-1, -1), 128);

    // 결과 출력
    imshow("src", src);
    imshow("dst (delta = 0)", dst_0);
    imshow("dst (delta = 128)", dst_128);
    waitKey();

    return 0;
}