#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

#include <nlohmann/json.hpp>

#include <boost/date_time/gregorian/gregorian.hpp>

#include <opencv2/opencv.hpp>


#include"LinearRegression.hpp"
int main()
{
    std::ostringstream os;
    os << cURLpp::options::Url("https://api.covid19api.com/country/vietnam/status/confirmed?from=2020-03-01&to=2020-04-05");

    nlohmann::json json = nlohmann::json::parse(os.str());

    boost::gregorian::date date(2021, 10, 30);

//    boost::gregorian::date date2(2021, 10, 28);
//
//    std::cout << date2 - date << '\n';

    cv::Mat1d x(0, 2);
    std::cout << x.cols << '\n';
    cv::Mat1d y(0, 1);

    for (int i = 0; i < json.size(); ++i) {
        double rowOfX[] = { 1, static_cast<double>(i) };
        x.push_back(cv::Mat1d(1, 2, rowOfX));
        y.push_back(static_cast<double>(json[i]["Cases"]));

//        std::cout << json[i]["Cases"] << '\n';
    }

    LinearRegression linearRegression(2);
//    cv::hconcat(cv::Mat1d::ones(x.rows, 1), x);

    std::cout << linearRegression.getWeights() << '\n';

    linearRegression.train(x, y, 100);
    double rowOfX[] = { 1, static_cast<double>(1) };
    std::cout << linearRegression.getValue(cv::Mat1d(1, 2, rowOfX)) << "----" << x[1][1] << '\n';

    return 0;
}
