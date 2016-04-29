/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   draw_rectangle.cpp
 * Author: gabo
 *
 * Created on February 10, 2016, 10:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "utils.h"
#include "week3.h"
#include "week4.h"

using namespace std;
using namespace cv;

void draw_rectangle(Mat &img);
void calc_histogram(Mat &img);
void lookup_table(Mat &img);
void convert_color(Mat &img);
/*
 * Draw a rectangle
 */
int main(int argc, char** argv) {
//    Mat img, dst;
//    //char *img_name = "/home/gabo/NetBeansProjects/opencvApplication/comp_vision.jpg";
//    //char *img_name = "ivvi_684x684.jpg";
//    char *img_name = "IMG.jpg";
//    
//    read_img(img_name, img);
//    //read_img(img_name, img);
//    //draw_rectangle(img);
//    //calc_histogram(img);
//    //lookup_table(img);
//    //convert_color(img);
//    
//    convolution(img, dst);
//    show_img(img, "Original");
//    show_img(dst, "Convoluted");
    
    noise_reduction();
     waitKey(0);
    return 0;
}
void calc_histogram(Mat &img){
    // Split img in 3 imgs for the channels R, G and B
    vector<Mat> bgr_planes;
    split(img, bgr_planes);
    
    int hist_size = 256;
    float range[] = { 0, 256};
    const float* histRange = { range };
    
    bool uniform = true;
    bool accumulate = false;
    
    Mat r_hist, b_hist, g_hist;
    
    // Calculate histograms
    calcHist(&bgr_planes[0], 1, 0, Mat(), r_hist, 1, &hist_size, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &hist_size, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), b_hist, 1, &hist_size, &histRange, uniform, accumulate);
    
    cout << "hist: " << b_hist << endl;
    
    //Draw histogram for R, G and B
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double)hist_w/hist_size);
    Mat hist_img(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));
    
    //Normalize result to [0, hist_img.rows]
    normalize(r_hist, r_hist, 0, hist_img.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, hist_img.rows, NORM_MINMAX, -1, Mat());
    normalize(b_hist, b_hist, 0, hist_img.rows, NORM_MINMAX, -1, Mat());
    
    cout << "hist: " << b_hist << endl;
    
    /// Dibujar para  cada canal
    for (int i = 1; i < hist_size; i++)
    {
            line(hist_img, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
                    Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
                    Scalar(255, 0, 0), 2, 8, 0);
            line(hist_img, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
                    Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
                    Scalar(0, 255, 0), 2, 8, 0);
            line(hist_img, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
                    Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
                    Scalar(0, 0, 255), 2, 8, 0);
    }
    show_img(hist_img, "Histogram");
}

void draw_rectangle(Mat &img){
    for(int i = img.rows / 4; i < 3 * img.rows / 4; ++i){
        for(int j = img.cols/4; j < 3 * img.cols / 4; ++j){
            img.at<Vec3b>(i,j) = Vec3b(0, 0, 0);
        }   
    }

    imwrite("Result.jpg", img);   
}
void lookup_table(Mat &img){
    Mat ImagenResultadoLUT;
    Mat lut(1,256,CV_8U); //1rowx256cols matrix
    
    //Initilizes lookup table inversely. 
    // A pixwl with val i woul be transformed to val 255 - i
    for (int i = 0; i < 256; i++){
            lut.at<uchar>(i) = 255 - i; //Función Inversa
    }
    
    LUT(img, lut, ImagenResultadoLUT); //Applies transformation
    show_img(ImagenResultadoLUT, "Transformed img with lookup table");
}
void convert_color(Mat &img){
    Mat cvt_img;
    vector<Mat> channels;
    
    // HSV
    cvtColor(img, cvt_img, COLOR_BGR2HSV);
    
    split(cvt_img, channels);
    show_img(channels[0], "H");
    show_img(channels[1], "S");
    show_img(channels[2], "V");
    
    
    /// LAB
//    cvtColor(img, cvt_img, COLOR_BGR2Lab);
//    
//    split(cvt_img, channels);
//    show_img(channels[0], "L");
//    show_img(channels[1], "a");
//    show_img(channels[2], "b");
}