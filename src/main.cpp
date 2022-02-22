#include <opencv2/opencv.hpp>
#include <experimental/filesystem>

#include "bag_of_visual_words.h"

int main()
{
  PlaceRecognizer place_recognizer =
      PlaceRecognizer("/home/abdullah/modern_cpp/Bag_of_Visual_Words/data/freiburg/bin/imageCompressedCam0_0000000.bin",
                      "/home/abdullah/modern_cpp/Bag_of_Visual_Words/data/freiburg/bin",
                      "/home/abdullah/modern_cpp/Bag_of_Visual_Words/data/freiburg/"
                      "images");

  for (const auto image_path : std::experimental::filesystem::directory_iterator("/home/abdullah/modern_cpp/"
                                                                                 "Bag_of_Visual_Words/data/"
                                                                                 "freiburg/images"))
  {
    if (image_path.path().extension().string() == ".png")
    {
      place_recognizer.find_places(image_path.path().string());
    }
  }

  std::cout << "Loading serialized binary files...\n";
  //   std::vector<cv::Mat> loaded_descriptors = LoadDataset(bin_path);
  //   std::cout << "Loading completed!\n";

  //   auto& bow_dictionary_instance = BowDictionary::GetInstance();
  //   std::cout << "BowDictionary object created!\n";

  //   bow_dictionary_instance.build(40, 5, loaded_descriptors);
  //   std::cout << "BowDictionary object params has been set!\n";

  //   if (bow_dictionary_instance.GetInstance().empty())
  //     std::cout << "BowDictionary object is Empty!" << std::endl;
  //   else
  //     std::cout << "BowDictionary object size is: " << bow_dictionary_instance.size() << std::endl;

  //   bow_dictionary_instance.save_vocabulary("bow_dictionary.bin");
  //   std::cout << "bow_dictionary saved to bow_dictionary.bin" << std::endl;

  //   Histogram histogram = Histogram(loaded_descriptors[1], bow_dictionary_instance.vocabulary());
  //   std::cout << "Histogram Create." << std::endl;

  //   histogram.WriteToCSV("histogram.csv");
  //   std::cout << "Histogram saved to histogram.csv" << std::endl;

  return 0;
}