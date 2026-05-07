#ifndef LOSSES_HPP
#define LOSSES_HPP

struct Losses{
    static constexpr float EPSILON = 1e-7f; // the standard, using MIN_FLT would be too small

    static inline float cross_entropy(const Matrix& predictions, int observed_label){
        float p = predictions.data[observed_label];

        p = std::max(p, EPSILON);

        return -std::log(p);
    }

};

#endif
