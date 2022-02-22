#pragma once

#include <opencv2/opencv.hpp>

cv::Mat kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter);
