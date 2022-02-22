/*
 *  This is the default license template.
 *
 *  File: kmeans.cpp
 *  Author: abdullah
 *  Copyright (c) 2022 abdullah
 *
 *  To edit this license information: Press Ctrl+Shift+P and press 'Create new License Template...'.
 */

#include <opencv2/opencv.hpp>

#include "bag_of_visual_words.h"

/**
 * @brief
 * 1. Given cluster centroids i initialized in some way,
 * 2. For iteration t=1..T:
 * 1. Compute the distance from each point x to each cluster centroid ,
 * 2. Assign each point to the centroid it is closest to,
 * 3. Recompute each centroid as the mean of all points assigned to it,
 *
 * @param descriptors The input SIFT descriptors to cluster.
 * @param k The size of the dictionary, ie, number of visual words.
 * @param max_iterations Maximum number of iterations before convergence.
 * @return cv::Mat One unique Matrix representing all the $k$-means(stacked).
 */

cv::Mat kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter)
{
  std::vector<cv::Mat> stacked_centroids;
  cv::Mat all_descriptors;
  cv::vconcat(descriptors, all_descriptors);
  cv::Mat converted_descriptor = convertDescriptorToFloatMat(all_descriptors);
  // cv::Mat converted_descriptor = convertDescriptorToFloatMat(descriptors[0]);
  cv::Mat centroids = initializeCentroids(converted_descriptor, k);
  std::vector<int> assigned_points;
  std::cout << "Running kmeans to cluster descriptors...\n";
  std::cout << "Descriptors Size: " << converted_descriptor.rows << "     Clusters Size: " << k
            << "     Max Interations: " << max_iter << std::endl;
  for (int i = 0; i < max_iter; i++)
  {
    std::cout << "Iteration " << i + 1 << ":\t";
    assigned_points = assignPointsToClusters(converted_descriptor, centroids);
    centroids = ComputeNewCentroids(converted_descriptor, assigned_points, k);
    stacked_centroids.emplace_back(centroids);
    for (int i = 0; i < centroids.rows; i++)
      std::cout << centroids.row(i) << "\t";
    std::cout << std::endl;
  }
  cv::Mat centroids_ = stacked_centroids[max_iter - 1];
  return centroids;
}