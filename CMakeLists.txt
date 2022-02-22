cmake_minimum_required(VERSION 3.1)
# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

project(bag_of_visual_words)

SET(OpenCV_DIR /home/abdullah/opencv/build/share/OpenCV)

find_package(Boost 1.78.0 COMPONENTS filesystem)
include_directories(${Boost_INCLUDE_DIRS}) 


# Include OpenCV
find_package(TBB REQUIRED tbb)
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(fmt-8.1.1)
find_package(fmt)


add_library(serialize src/compute_sifts.cpp src/serialize.cpp) 
target_link_libraries(serialize tbb)


add_library(bow_dictionary src/bow_dictionary.cpp)
target_link_libraries(bow_dictionary tbb serialize kmeans stdc++fs ${OpenCV_LIBS})


add_library(htmlwriter src/html_writer.cpp)
target_link_libraries(htmlwriter fmt::fmt)
link_directories(htmlwriter ${Boost_LIBRARY_DIRS})

target_link_libraries(htmlwriter ${Boost_LIBRARIES})

add_library(imagebrowser src/image_browser.cpp)
target_link_libraries(imagebrowser htmlwriter)

add_library(place_recognizer src/place_recognizer.cpp)
target_link_libraries(place_recognizer tbb serialize bow_dictionary kmeans imagebrowser stdc++fs ${OpenCV_LIBS})


add_library(convert_dataset src/convert_dataset.cpp src/serialize.cpp src/compute_sifts.cpp) 

target_link_libraries(convert_dataset serialize stdc++fs ${OpenCV_LIBS})

add_library(kmeans src/kmeans.cpp src/kmeans_utils.cpp ) 
target_link_libraries(kmeans ${OpenCV_LIBS})


add_executable(main src/main.cpp)
target_link_libraries(main place_recognizer tbb convert_dataset bow_dictionary stdc++fs ${OpenCV_LIBS} ${Boost_LIBRARIES})