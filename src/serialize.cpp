/*
 *  This is the default license template.
 *
 *  File: serialize.cpp
 *  Author: abdullah
 *  Copyright (c) 2022 abdullah
 *
 *  To edit this license information: Press Ctrl+Shift+P and press 'Create new License Template...'.
 */

#include <opencv2/opencv.hpp>
#include "bag_of_visual_words.h"

void Serialize(const cv::Mat& m, const std::string& filename)
{
  // auto [descriptors, image_with_kp] = ComputeSifts(m);

  std::ofstream fs(filename, std::fstream::binary);

  // Header
  int type = m.type();
  int channels = m.channels();
  fs.write((char*)&m.rows, sizeof(int));    // rows
  fs.write((char*)&m.cols, sizeof(int));    // cols
  fs.write((char*)&type, sizeof(int));      // type
  fs.write((char*)&channels, sizeof(int));  // channels

  // Data
  if (m.isContinuous())
  {
    fs.write(m.ptr<char>(0), (m.dataend - m.datastart));
  }
  else
  {
    int rowsz = CV_ELEM_SIZE(type) * m.cols;
    for (int r = 0; r < m.rows; ++r)
    {
      fs.write(m.ptr<char>(r), rowsz);
    }
  }
}

cv::Mat Deserialize(const std::string& filename)
{
  std::ifstream fs(filename, std::fstream::binary);

  // Header
  int rows, cols, type, channels;
  fs.read((char*)&rows, sizeof(int));      // rows
  fs.read((char*)&cols, sizeof(int));      // cols
  fs.read((char*)&type, sizeof(int));      // type
  fs.read((char*)&channels, sizeof(int));  // channels

  // Data
  cv::Mat mat(rows, cols, type);
  fs.read((char*)mat.data, CV_ELEM_SIZE(type) * rows * cols);

  return mat;
}