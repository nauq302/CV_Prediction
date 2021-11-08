//
// Created by nauq302 on 01/11/2021.
//



#include "Assert.hpp"
#include "LinearRegression.hpp"


double LinearRegression::getValue(const cv::Mat1d& row) const
{
//    NQ_ASSERT(row.rows == 1 &&  row.cols == weights.rows, "Input matrix must be a row and has same dimension with weights");
    return cv::Mat1d(row * weights)[0][0];
}

double LinearRegression::getError(const cv::Mat1d& x_bar, const cv::Mat1d& y) const
{
    double norm = cv::norm(y - x_bar * weights, 2);
    return 0.5 * cv::pow(norm, 2);
}

void LinearRegression::train(const cv::Mat1d& x_bar, const cv::Mat1d& y, int steps) const
{
    double rate = 0.0001;
    for (int i = 1; i <= steps; ++i) {
        cv::Mat1d grad = gradient(x_bar, y);
        weights -= rate * grad;

        std::cout << getError(x_bar, y) << '\n';
//        std::cout << weights << '\n';
//        std::cout << '\n';
    }
}

