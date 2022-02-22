#pragma once

cv::Mat convertDescriptorToFloatMat(cv::Mat Descriptor);
cv::Mat initializeCentroids(const cv::Mat& descriptor, int k);
std::vector<int> assignPointsToClusters(const cv::Mat& descriptor, const cv::Mat& centroids);
cv::Mat ComputeNewCentroids(const cv::Mat& descriptor, std::vector<int>& assigned_points, int k);