#pragma once

#include <algorithm>
#include <chrono>
#include <convert_dataset.hpp>
#include <ctime>
#include <experimental/filesystem>
#include <functional>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <serialize.hpp>
#include <string>
#include <thread>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/xfeatures2d.hpp>
class PlaceRecognizer
{
public:
  PlaceRecognizer();
  explicit PlaceRecognizer(const std::string& dictionary_path, const std::string& bin_dataset_path,
                           const std::string& raw_dataset_path);
  ~PlaceRecognizer(){};

  void find_places(const std::string& image_path);
  void find_places(cv::Mat image);

private:
  float cosine_distance(Histogram h1, Histogram h2);

  std::vector<std::experimental::filesystem::path> raw_images_;
  BowDictionary& dictionary_ = BowDictionary::GetInstance();
  cv::Ptr<cv::SiftFeatureDetector> detector_ = cv::SiftFeatureDetector::create();
  cv::Ptr<cv::SiftDescriptorExtractor> extractor_ = cv::SiftDescriptorExtractor::create();
  std::vector<Histogram> histograms_;
  std::vector<int> bin_frequency_;
  cv::Mat descriptors_;
  std::vector<cv::KeyPoint> keypoints_;
};