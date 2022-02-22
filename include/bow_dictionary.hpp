#pragma once

#include <algorithm>
#include <chrono>
#include <convert_dataset.hpp>
#include <ctime>
// #include <execution>
#include <fstream>
#include <functional>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <serialize.hpp>
#include <string>
#include <thread>
#include <vector>
#include <experimental/filesystem>

class BowDictionary
{
private:
  BowDictionary() = default;
  ~BowDictionary() = default;

public:
  BowDictionary(const BowDictionary&) = delete;
  void operator=(const BowDictionary&) = delete;
  BowDictionary(const BowDictionary&&) = delete;
  void operator=(const BowDictionary&&) = delete;

  static BowDictionary& GetInstance();

private:
  cv::Mat computed_dictionary_;

public:
  // Getters methods
  int size();  // number of centroids / codewords
  cv::Mat vocabulary() const
  {
    return computed_dictionary_;
  };
  cv::Mat& vocabulary()
  {
    return computed_dictionary_;
  };
  bool empty();

  // Setters methods
  void build(int iter, int dict_size, const std::vector<cv::Mat>& descriptors);
  void set_vocabulary(const std::string& filename);
  void save_vocabulary(const std::string& filename);
};

class Histogram
{
public:
  Histogram();
  Histogram(std::vector<float>& data);
  Histogram(cv::Mat& descriptors, cv::Mat& dictionary, std::experimental::filesystem::path filename = "");

  friend std::ostream& operator<<(std::ostream& out, const Histogram& histogram)
  {
    for (const auto& data_point : histogram.data_)
    {
      out << data_point << " ";
    }
    out << std::endl;
    return out;
  }
  void WriteToCSV(const std::string& filename);
  void ReadFromCSV(const std::string& filename);

  float& operator[](int i)
  {
    return data_[i];
  };
  float operator[](int i) const
  {
    return data_[i];
  };
  std::vector<float> data() const
  {
    return data_;
  };
  int size() const
  {
    return data_.size();
  };
  bool empty() const
  {
    return data_.size() > 0 ? true : false;
  }
  std::experimental::filesystem::path filename() const
  {
    return filename_;
  };
  std::vector<float>::const_iterator begin() const
  {
    return data_.begin();
  }
  std::vector<float>::const_iterator cbegin() const
  {
    return data_.cbegin();
  }
  std::vector<float>::const_iterator end() const
  {
    return data_.end();
  }
  std::vector<float>::const_iterator cend() const
  {
    return data_.cend();
  }

private:
  // data members:
  std::vector<float> data_;
  std::experimental::filesystem::path filename_;
  inline static cv::Ptr<cv::DescriptorMatcher> matcher_ = nullptr;
  inline static std::vector<std::vector<cv::DMatch>> knn_matches;
  inline static std::ifstream fin = std::ifstream();
  inline static std::ofstream fout = std::ofstream();
};