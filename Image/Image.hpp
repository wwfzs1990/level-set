/**
 * \class Image
 *
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstdio>
#include <opencv2/opencv.hpp>
#include <gtest/gtest.h> //for FRIEND_TEST FIXME: We don't want gtest required as default
class Image {

private:
	cv::Mat inputImage;

	
	//fimage is a 2d array which is a copy of inputImage
	float** fimage;
	float** phi;
	std::size_t rows;
	std::size_t cols;
	float c1;//averageInside;
	float c2;//averageOutside;
	float mi;
	float eta;
	float ni;
	float lambda1;
	float lambda2;
	float eps;
	float dt;
	
	void initImage(const std::string& filename, int flags);
	void initFimage(); 
	void initPhi();
	void destroyFimage();
	void destroyPhi();
	float Heaviside(float data);
	void updateAverages();

	FRIEND_TEST(Test,basic1); // FIXME
public:
	Image(const std::string& filename, int flags);
	Image(Image const&) = delete;
	Image(Image const&&) = delete;
	~Image();
	void displayPhi();
	void detectBorders();

};
			
#endif // IMAGE_HPP
