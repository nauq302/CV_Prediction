//
// Created by nauq302 on 01/11/2021.
//

#ifndef CV_PREDICTION_ASSERT_HPP
#define CV_PREDICTION_ASSERT_HPP

#include <stdexcept>
#include <string>

#define NQ_ASSERT(x, ...) { if (!(x)) throw std::runtime_error(__VA_ARGS__); }

namespace nq {
    inline void aassert(bool expression, const std::string& msg = "ada") {
        if (!expression) {
            throw std::runtime_error(msg);
        }
    }


}


#endif //CV_PREDICTION_ASSERT_HPP
