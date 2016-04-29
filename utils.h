/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.h
 * Author: gabo
 *
 * Created on February 29, 2016, 10:13 PM
 */


#ifndef UTILS_H
#define UTILS_H

#include <opencv2/core/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;
void read_img(char * img_name, Mat &img){
    img = imread(img_name, IMREAD_COLOR);
    if(!img.data){
        cout << "Error loading image" << endl;
        exit(1);
    }
}
void show_img(const Mat &img, char* win_name){
    // Show the image
    namedWindow(win_name, WINDOW_AUTOSIZE);
    imshow(win_name, img);
}

#endif /* UTILS_H */

