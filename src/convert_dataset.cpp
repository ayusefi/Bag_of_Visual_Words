/*
 *  This is the default license template.
 *
 *  File: convert_dataset.cpp
 *  Author: abdullah
 *  Copyright (c) 2022 abdullah
 *
 *  To edit this license information: Press Ctrl+Shift+P and press 'Create new License Template...'.
 */

#include <opencv2/opencv.hpp>
#include "bag_of_visual_words.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

void ConvertDataset(const std::experimental::filesystem::path& img_path)
{
  static const fs::path bin_path = img_path.parent_path().parent_path();

  std::cout << bin_path << std::endl;
  fs::create_directories(bin_path / "bin");
  for (const auto& p : fs::directory_iterator(img_path))
  {
    if (p.path().extension() == ".png")
    {
      auto read_image = cv::imread(p.path().u8string(), cv::IMREAD_GRAYSCALE);
      fs::path bin_path_img = bin_path / "bin" / p.path().stem();  // append with a forward slash
      bin_path_img += ".bin";                                      // concatenate
      std::cout << bin_path_img << std::endl;
      Serialize(read_image, bin_path_img);
    }
  }
}

std::vector<std::pair<cv::Mat, std::experimental::filesystem::path>>
LoadDataset(const std::experimental::filesystem::path& bin_path)
{
  std::vector<std::pair<cv::Mat, std::experimental::filesystem::path>> image_vector;
  image_vector.reserve((std::size_t)std::distance(std::experimental::filesystem::directory_iterator{ bin_path },
                                                  std::experimental::filesystem::directory_iterator{}));
  for (const auto image_path : std::experimental::filesystem::directory_iterator(bin_path))
  {
    cv::Mat image = Deserialize(image_path.path().string());
    image_vector.push_back(std::make_pair(image, image_path.path()));
  }
  return image_vector;
}