/*
 *  This is the default license template.
 *
 *  File: kmeans_utils.cpp
 *  Author: abdullah
 *  Copyright (c) 2022 abdullah
 *
 *  To edit this license information: Press Ctrl+Shift+P and press 'Create new License Template...'.
 */

#include <opencv2/opencv.hpp>

#include <vector>

cv::Mat convertDescriptorToFloatMat(cv::Mat Descriptor)
{
  cv::Mat convertedDescriptor = cv::Mat::zeros(Descriptor.rows * Descriptor.cols, 1, CV_32F);

  for (int r = 0; r < Descriptor.rows; r++)
  {
    for (int c = 0; c < Descriptor.cols; c++)
    {
      convertedDescriptor.at<float>(r * Descriptor.cols + c, 0) = Descriptor.at<float>(r, c);
    }
  }

  return convertedDescriptor;
}

cv::Mat initializeCentroids(const cv::Mat& descriptor, int k)
{
  int n = descriptor.rows;
  cv::Mat centroids = cv::Mat::zeros(k, 1, CV_32F);

  std::vector<int> random_indexes;
  for (unsigned int i = 0; i < n; ++i)
    random_indexes.push_back(i + 1);
  std::random_shuffle(random_indexes.begin(), random_indexes.end());
  // srand(time(0));  // set the random seed
  for (int i = 0; i < k; ++i)
  {
    centroids.at<float>(i, 0) = descriptor.at<float>(random_indexes[i], 0);
  }
  return centroids;
}

std::vector<int> assignPointsToClusters(const cv::Mat& descriptor, const cv::Mat& centroids)
{
  cv::Mat_<float> summed_values;
  cv::Mat_<float> euclidean_distance_values;
  const int k = centroids.rows;
  std::vector<int> assigned_points;
  for (int i = 0; i < descriptor.rows; i++)
  {
    cv::Mat_<float> diff_values = centroids - (cv::repeat(descriptor.row(i), k, 1));
    cv::Mat_<float> squared_values = diff_values.mul(diff_values);
    cv::reduce(squared_values, summed_values, 1, cv::REDUCE_SUM, CV_32F);
    cv::sqrt(summed_values, summed_values);
    euclidean_distance_values = summed_values;
    double minimum_value, maximum_value;
    int minimum_index[2] = {}, maximum_index[2] = {};
    cv::minMaxIdx(euclidean_distance_values, &minimum_value, &maximum_value, minimum_index, maximum_index);
    assigned_points.emplace_back(minimum_index[0]);
  }
  return assigned_points;
}

cv::Mat ComputeNewCentroids(const cv::Mat& descriptor, std::vector<int>& assigned_points, int k)
{
  cv::Mat centroids = cv::Mat::zeros(k, 1, CV_32F);

  cv::Mat summed_cluster_points;
  for (int i = 0; i < k; i++)
  {
    std::vector<int> i_cluster_indexes{};
    for (unsigned int j = 0; j < assigned_points.size(); j++)
    {
      if (assigned_points[j] == i)
      {
        i_cluster_indexes.emplace_back(j);
      }
    }
    // std::vector<int> indexes = FindIndexPosition(idx, i);
    int i_cluster_index_count = std::count(assigned_points.begin(), assigned_points.end(), i);
    cv::Mat i_cluster_descriptors = cv::Mat::zeros(i_cluster_indexes.size(), 1, CV_32F);
    if (i_cluster_index_count >= 1)
    {
      for (unsigned int r = 0; r < i_cluster_indexes.size(); ++r)
      {
        i_cluster_descriptors.at<float>(r, 0) = descriptor.at<float>(i_cluster_indexes[r], 0);
      }
      cv::reduce(i_cluster_descriptors, summed_cluster_points, 0, cv::REDUCE_SUM, CV_32F);
    }
    cv::Mat new_centroid = summed_cluster_points / i_cluster_index_count;
    centroids.at<float>(i, 0) = new_centroid.at<float>(0, 0);
  }

  return centroids;
}