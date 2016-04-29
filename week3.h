/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   week3.h
 * Author: gabo
 *
 * Created on February 29, 2016, 10:09 PM
 */

#ifndef WEEK3_H
#define WEEK3_H
#include <opencv2/core.hpp>
#include <iostream>
#include "utils.h"
using namespace cv;
using namespace std;

/**
 *  Convolutes src image with 5x5 Kernel. smooths edges
 * @param src image
 * @param dst image
 */
void convolution(Mat &src, Mat &dst){
    Mat kernel;
    kernel = Mat::ones(5, 5, CV_32F) / (float)(5 * 5);
    cout << "kernel: " << kernel << endl;

    filter2D(src, dst, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
}

void geom_transformation(){
    Mat src, dst;
    read_img("coche-semana2.jpg", src);
    resize(src, dst, Size(0, 0), 0.5, 0.5, INTER_LINEAR);
    show_img(src, "Original");
    show_img(dst, "Resized");
    //Translation
    Mat dst2 = Mat::zeros(src.size(), src.type());
    src(Rect(100, 100, src.cols -100, src.rows - 100)).copyTo(dst2(cv::Rect(0, 0, src.cols-100, src.rows-100)));
    show_img(dst2, "translated");
    
    //Rotate
    int len = max(src.cols, src.rows);
    double angle = 60;
    Point2f pt(len/2.0, len/2.0);
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    Mat dst3;
    warpAffine(src, dst3, r, Size(len, len));
    show_img(dst3, "Rotated");

    //Reflection
    Mat dst4;
    flip(src, dst4, 1);
    show_img(dst4, "Flipped");
}

#endif /* WEEK3_H */

