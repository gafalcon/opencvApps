/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   week4.h
 * Author: gabo
 *
 * Created on March 1, 2016, 10:15 PM
 */

#ifndef WEEK4_H
#define WEEK4_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void noise_reduction(){
    char NombreImagen[] = "ivvi_512x512_gray_rg.jpg";
    char NombreImagenIvvi[] = "ivvi_512x512_gray.jpg";
	Mat src, imBlr, imGus, imMed, imBil, ivvi;

	//Cargamos la imagen y se comprueba que lo ha hecho correctamente
	src = cv::imread(NombreImagen);
	ivvi = cv::imread(NombreImagenIvvi);
	if (!src.data) {
		cout << "Error al cargar la imagen: " << NombreImagen << endl;
		exit(1);
	}

	// Homogeneous blur
	blur(src, imBlr, Size(5, 5), Point(-1, -1), 4);

	// Gaussian blur
	GaussianBlur(src, imGus, Size(5, 5), 0, 0, 4);

	// Median blur
	medianBlur(src, imMed, 5);

	//bilateral filter
	bilateralFilter(src, imBil, 15, 80, 80);

	//Mostrar la imagenes
	namedWindow("Vehiculo IVVI", CV_WINDOW_AUTOSIZE);
	imshow("Vehiculo IVVI", ivvi);

	namedWindow("Original con ruido", CV_WINDOW_AUTOSIZE);
	imshow("Original con ruido", src);

	namedWindow("blur", CV_WINDOW_AUTOSIZE);
	imshow("blur", imBlr);

	namedWindow("Gaussian", CV_WINDOW_AUTOSIZE);
	imshow("Gaussian", imGus);

	namedWindow("Median", CV_WINDOW_AUTOSIZE);
	imshow("Median", imMed);

	namedWindow("bilateral", CV_WINDOW_AUTOSIZE);
	imshow("bilateral", imBil);
}

#endif /* WEEK4_H */

