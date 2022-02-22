#pragma once

void Serialize(const cv::Mat& m, const std::string& filename);

cv::Mat Deserialize(const std::string& filename);