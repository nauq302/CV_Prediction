//
// Created by nauq302 on 01/11/2021.
//

#ifndef CV_PREDICTION_LINEARREGRESSION_HPP
#define CV_PREDICTION_LINEARREGRESSION_HPP

#include <opencv2/opencv.hpp>

enum class LeadingOne : bool {
    YES = true,
    NO = false
};

class LinearRegression
{
private:
    cv::Mat1d weights;

public:
    explicit LinearRegression(int dimension) : weights(cv::Mat1d::zeros(dimension, 1)) {}

public:
    [[nodiscard]] inline const cv::Mat1d& getWeights() const { return weights; }

    [[nodiscard]] double getValue(const cv::Mat1d& row) const;

    [[nodiscard]] inline cv::Mat1d gradient(const cv::Mat1d& x_bar, const cv::Mat1d& y) const { return x_bar.t() * (x_bar * weights - y); }

    [[nodiscard]] double getError(const cv::Mat1d& x_bar, const cv::Mat1d& y) const;

    void train(const cv::Mat1d& x, const cv::Mat1d& y, int steps) const;



private:
    [[nodiscard]] inline double w(int index) const { return weights[index][0]; }
};

#include "LinearRegression.inl.hpp"

#endif //CV_PREDICTION_LINEARREGRESSION_HPP
