#include "non-linear.h"

namespace PrivLR_BFV {
    double NonLinear::mul2add(const double in) const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(-1, 1);
        std::uniform_real_distribution<> positive_dist1(0, 0.5);
        std::uniform_real_distribution<> positive_dist2(0.5, 1);
        std::uniform_real_distribution<> negative_dist(-0.5, 0);
        double r1, r2;
        
        return 0;
    }

    vector<double> NonLinear::mul2add(const vector<double> &in) const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(-1, 1);
        std::uniform_real_distribution<> positive_dist1(0, 0.5);
        std::uniform_real_distribution<> positive_dist2(0.5, 1);
        std::uniform_real_distribution<> negative_dist(-0.5, 0);
        size_t size = in.size();

        return vector<double>(1);
    }

    double NonLinear::sigmoid(const double in) const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(-1, 1);
        double r = dist(gen), exp_neg_in = exp(-in) * r;
        double r_add = mul2add(r), exp_neg_in_add = mul2add(exp_neg_in);
        double theta = r_add + exp_neg_in_add, theta_remote;
        io_pack->send_data(&theta, sizeof(double));
        io_pack->recv_data(&theta_remote, sizeof(double));
        return r_add / (theta + theta_remote);
    }

    vector<double> NonLinear::sigmoid(const vector<double> &in) const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(-1, 1);
        double size = in.size();
        vector<double> res(size), r(size), exp_neg_in(size), theta(size), theta_remote(size);
        for (size_t i = 0; i < size; i++) {
            r[i] = dist(gen);
            exp_neg_in[i] = exp(-in[i]) * r[i];
        }
        vector<double> r_add = mul2add(r), exp_neg_in_add = mul2add(exp_neg_in);
        for (size_t i = 0; i < size; i++) {
            theta[i] = r_add[i] + exp_neg_in_add[i];
        }
        io_pack->send_data(theta.data(), sizeof(double) * size);
        io_pack->recv_data(theta_remote.data(), sizeof(double) * size);
        for (size_t i = 0; i < size; i++) {
            r_add[i] = r_add[i] / (theta[i] + theta_remote[i]);
        }
        return r_add;
    }
}