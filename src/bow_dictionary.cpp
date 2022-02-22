/*
 *  This is the default license template.
 *
 *  File: bow_dictionary.cpp
 *  Author: abdullah
 *  Copyright (c) 2022 abdullah
 *
 *  To edit this license information: Press Ctrl+Shift+P and press 'Create new License Template...'.
 */

#include <opencv2/opencv.hpp>

#include <algorithm>
#include <chrono>
#include <convert_dataset.hpp>
#include <ctime>
// #include <execution>
#include <functional>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <serialize.hpp>
#include <string>
#include <thread>
#include <vector>
#include <experimental/filesystem>

#include "bag_of_visual_words.h"

BowDictionary& BowDictionary::GetInstance()
{
  static BowDictionary instance;
  return instance;
}

int BowDictionary::size()
{
  return computed_dictionary_.rows;
}

bool BowDictionary::empty()
{
  return computed_dictionary_.empty();
}

void BowDictionary::build(int iter, int dict_size, const std::vector<cv::Mat>& descriptors)
{
  computed_dictionary_ = kMeans(descriptors, dict_size, iter);
}

// void BowDictionary::set_vocabulary(cv::Mat computed_vocabulary)
// {
//   computed_dictionary_ = computed_vocabulary;
// }
void BowDictionary::set_vocabulary(const std::string& filename)
{
  computed_dictionary_ = Deserialize(filename);
}

void BowDictionary::save_vocabulary(const std::string& filename)
{
  Serialize(computed_dictionary_, filename);
}

Histogram::Histogram(std::vector<float>& data)
{
  matcher_ = cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);
  data_ = data;
}

Histogram::Histogram(cv::Mat& descriptors, cv::Mat& dictionary, std::experimental::filesystem::path filename)
{
  matcher_ = cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);
  knn_matches.clear();
  matcher_->clear();
  matcher_->knnMatch(descriptors, dictionary, knn_matches, 1);
  filename_ = filename;
  data_.resize(dictionary.rows);
  for (const auto& match : knn_matches)
  {
    data_[match[0].trainIdx]++;
  }
}

void Histogram::WriteToCSV(const std::string& filename)
{
  fout.open(filename);
  for (const auto& element : data_)
  {
    fout << element << ",";
  }
  fout.close();
}

void Histogram::ReadFromCSV(const std::string& filename)
{
  fin.open(filename);
  if (fin.is_open())
  {
    std::string csv_value;
    while (std::getline(fin, csv_value, ','))
    {
      data_.emplace_back(stoi(csv_value));
    }
    fin.close();
  }
  else
  {
    std::cerr << "Could not open file " << filename << std::endl;
    fin.close();
  }
}
