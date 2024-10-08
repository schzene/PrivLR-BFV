#include "linear.h"

namespace PrivLR_BFV {
    double Linear::dot_product(const vector<double> &in_a, const vector<double> &in_b) const {
        assert(in_a.size() == in_b.size());
        size_t size = in_a.size();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(-1, 1);
        std::uniform_real_distribution<> positive_dist(0, 1);

        double res = 0;
        
        return res;
    }

    vector<double> Linear::dot_product(const vector<vector<double>> &in_a, const vector<double> &in_b, double transpose) const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(-1, 1);
        std::uniform_real_distribution<> positive_dist(0, 1);
        size_t data_size = transpose ? in_a[0].size() : in_a.size(), size = in_b.size();
        vector<double> in_a_flatten(data_size * size);
        if (transpose) {
            for (size_t i = 0; i < data_size; i++) {
                for (size_t j = 0; j < size; j++) {
                    in_a_flatten[i * size + j] = in_a[j][i];
                }
            }
        } else {
            for (size_t i = 0; i < data_size; i++) {
                for (size_t j = 0; j < size; j++) {
                    in_a_flatten[i * size + j] = in_a[i][j];
                }
            }
        }
        vector<double> res(data_size), in_b_flatten(data_size * size);
        
        return res;
    }
}