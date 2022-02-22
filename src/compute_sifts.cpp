/*
 *  This is the default license template.
 *
 *  File: compute_sifts.cpp
 *  Author: abdullah
 *  Copyright (c) 2022 abdullah
 *
 *  To edit this license information: Press Ctrl+Shift+P and press 'Create new License Template...'.
 */

#include <tuple>
#include <opencv2/opencv.hpp>
// #include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/xfeatures2d.hpp>
std::tuple<cv::Mat, cv::Mat> ComputeSifts(const cv::Mat& kInput)
{
  // detect keypoints
  auto detector = cv::SIFT::create();
  std::vector<cv::KeyPoint> keypoints;
  detector->detect(kInput, keypoints);

  // draw the keypoints on the image
  cv::Mat image_with_keypoints;
  drawKeypoints(kInput, keypoints, image_with_keypoints);

  // Show features on image
  cv::namedWindow("SIFT Features");
  cv::imshow("SIFT Features", image_with_keypoints);

  // extract the SIFT descriptors
  cv::Mat descriptors;
  auto extractor = cv::SIFT::create();
  extractor->compute(kInput, keypoints, descriptors);

  return std::make_tuple(descriptors, image_with_keypoints);
}