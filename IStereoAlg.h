/***************************************************************/
/* File: IStereoAlg.h                                          */
/* Usage: header file for stereo matching interface            */
/* Author: Zhang Kang                                          */
/* Date:                                                       */
/***************************************************************/
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class IStereoAlg
{
public:

	int width;             // image size
	int height;
	int imgSize;

	cv::Mat lClr;		   // left&right images
    cv::Mat rClr;

	cv::Mat lDis;		   // output depth maps
	cv::Mat rDis;

    // ¹«¹²²ÎÊý
	int      maxDis;    //  dataset    levels  scale
	int      disScale;  //  Tsukuba 	0..15 	16 	
						//  Venus 	    0..19 	8 	
						//  Teddy 	    0..59 	4 	
						//  Cones 	    0..59 	4
public:
	IStereoAlg(const int mD, const int dS);
	~IStereoAlg(void);
public:
	void LoadImg( const char* lFn, const char* rFn );			
	void SaveDep( const char* lFn, const char* rFn );	

	virtual void PreProcess()=0;		
	virtual void Match()=0;		
	virtual void PostProcess()=0;
};
