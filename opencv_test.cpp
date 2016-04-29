/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabo
 *
 * Created on February 6, 2016, 12:00 PM
 */

#include <cstdlib>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


/*
 * 
 */
int main1(int argc, char** argv) {
    Mat img = imread("/home/gabo/NetBeansProjects/opencvApplication/comp_vision.jpg", IMREAD_COLOR);
    if(img.data != NULL){
        namedWindow("Test image",  WINDOW_AUTOSIZE);
        imshow("Test image", img);
    }else{
        cout << "No image" << endl;
    }
    waitKey(0);
    return 0;
}

