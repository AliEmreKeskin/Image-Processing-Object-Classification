#pragma once
#include <Windows.h>
//#include "mergesort.h"
//#include "ImgObj.h"

BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile);

BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height);

bool  SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile);

BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long* newsize);

int* getHistogram(BYTE* buffer, int width, int height);

BYTE* KMeans(int* hist, BYTE* image, int imgSize, int numOfT);

BYTE* Kmeans_Mahalanobis(int* hist, BYTE* image, int imgSize, int numOfT);

BYTE* Dilation(BYTE* image, int width, int height, int r);

BYTE* Erosion(BYTE* image, int width, int height, int r);

BYTE* Boundary_Extraction(BYTE* image, int width, int height);

///////

BYTE* Sobel_Vertical_Func(BYTE* Raw_Intensity, int width, int height);
BYTE* Sobel_Horizontal_Func(BYTE* Raw_Intensity, int width, int height);
BYTE* Sobel(BYTE* Raw_Intensity, int width, int height, BYTE* vertical, BYTE* horizontal);
BYTE* NMS_Vertical(BYTE* Edge_Image, int width, int height);
BYTE* NMS_Horizontal(BYTE* Edge_Image, int width, int height);
BYTE* NMS(BYTE* Edge_Image, int width, int height, BYTE* vertical, BYTE* horizontal);
BYTE* Hysteresis_Threshold_Horizontal(BYTE* NMS_Vertical, int width, int height, int upper, int lower);
BYTE* Hysteresis_Threshold_Vertical(BYTE* NMS_Horizontal, int width, int height, int upper, int lower);
BYTE* Hysteresis_Threshold(BYTE* NMS_Vertical, BYTE* NMS_Horizontal, int width, int height, BYTE* HT_Vertical, BYTE* HT_Horizontal);
BYTE* Gaussian_Smoothing(BYTE* Raw_Intensity, int width, int height);
BYTE* Hough_Space(BYTE* Canny_Image, BYTE* Sobel_Vertical, BYTE* Sobel_Horizontal, int Width, int Height);
BYTE* Histogram_Equalization(BYTE* Raw_Intensity, int Width, int Height);
void Draw_Line_Polar(BYTE* image, int w, int h, int r, int q);
void Draw_Line_Polar_2(BYTE* image, int w, int h, int r, int q);
BYTE* Hough_Translation(BYTE* Raw_Intensity, int Raw_Width, int Raw_Height, BYTE* Hough, int Hough_Width, int Hough_Height);
