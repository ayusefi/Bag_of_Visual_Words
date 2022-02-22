
#pragma once

#include <experimental/filesystem>

void ConvertDataset(const std::experimental::filesystem::path& img_path);
std::vector<std::pair<cv::Mat, std::experimental::filesystem::path>>
LoadDataset(const std::experimental::filesystem::path& bin_path);