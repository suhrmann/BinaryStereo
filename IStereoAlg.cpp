/***************************************************************/
/* File: IStereoAlg.cpp                                        */
/* Usage: basic methods for stereo matching                    */
/* Author: Zhang Kang                                          */
/* Date:                                                       */
/***************************************************************/
#include "IStereoAlg.h"

/***************************************************************/
/* Function: IStereoAlg                                        */
/* Usage: initial class member variables                       */
/* In:                                                         */
/*    const int mD - disparity levels                          */
/*    const int dS - disparity scale                           */
/* Out:                                                        */
/***************************************************************/
IStereoAlg::IStereoAlg(const int mD, const int dS)
{
	width = 0;        
	height = 0;
	imgSize = 0;
	lClr = NULL;
	rClr = NULL;
	lDis = NULL;
	rDis = NULL;
	maxDis = mD;
	disScale = dS;  
}
/***************************************************************/
/* Function: ~IStereoAlg                                       */
/* Usage: free class member variables                          */
/* In:                                                         */
/* Out:                                                        */
/***************************************************************/
IStereoAlg::~IStereoAlg(void)
{
    lClr.release();
    rClr.release();

    lDis.release();
    rDis.release();
}

/***************************************************************/
/* Function: LoadImage                                         */
/* Usage: loading left&right images                            */
/* In:                                                         */
/*    const char *lFn - left image file name                   */
/*    const char *rFn - right image file name                  */
/* Out:                                                        */
/***************************************************************/
void IStereoAlg::LoadImg(const char *lFn, const char *rFn)
{
	lClr = cv::imread( lFn, cv::IMREAD_COLOR );
	rClr = cv::imread( rFn, cv::IMREAD_COLOR );

	
	width = lClr.size().width;
	height = lClr.size().height;
	imgSize = width * height;
	
	// create depth map
	lDis = cv::Mat( cv::Size( width, height ), CV_8U); // TODO Missing param channels? IplImage* cvCreateImage(CvSize size, int depth, int channels)
    lDis = cv::Mat::zeros(lDis.size(), CV_8U); // Fill Mat with zeros
	rDis = cv::Mat( cv::Size( width, height ), CV_8U);
    rDis = cv::Mat::zeros(rDis.size(), CV_8U); // Fill Mat with zeros
}
/***************************************************************/
/* Function: SaveDep                                           */
/* Usage: save left&right depth maps                           */
/* In:                                                         */
/*    const char *lFn - left depth file name                   */
/*    const char *rFn - right depth file name                  */
/* Out:                                                        */
/***************************************************************/
void IStereoAlg::SaveDep(const char* lFn, const char* rFn)
{
	cv::imwrite(lFn, lDis);
    cv::imwrite(rFn, rDis);
}