cmake_minimum_required(VERSION 3.20)
project(CV_Prediction)

set(CMAKE_CXX_STANDARD 20)

add_executable(CV_Prediction main.cpp LinearRegression.inl.hpp LinearRegression.hpp Assert.hpp)

find_package(unofficial-curlpp CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

find_package(OpenCV REQUIRED)

target_link_libraries(CV_Prediction PRIVATE nlohmann_json nlohmann_json::nlohmann_json)
target_link_libraries(CV_Prediction PRIVATE unofficial::curlpp::curlpp)

target_link_libraries(CV_Prediction PRIVATE ${OpenCV_LIBS})

message(STATUS ${OpenCV_LIBS})
