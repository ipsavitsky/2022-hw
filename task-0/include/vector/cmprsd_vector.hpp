#ifndef CMPRSD_VECTOR_HPP_
#define CMPRSD_VECTOR_HPP_

#include <unordered_map>

template <typename T> class compressed_vector {
  private:
    std::unordered_map<std::size_t, T> container;
    std::size_t vec_size;

  public:
    compressed_vector(std::size_t size) {
        vec_size = size;
    }

    T operator()(std::size_t access) {
        if (access >= vec_size) {
            throw ":(";
        }
        return container[access];
    }

    compressed_vector operator+(const T &additive) {
        compressed_vector res = *this;
        for (auto [key, val] : res) {
            res[key] = val + additive;
        }
        return res;
    }

    compressed_vector operator-(const T &additive) {
        compressed_vector res = *this;
        for (auto [key, val] : res) {
            res[key] = val - additive;
        }
        return res;
    }

    compressed_vector operator*(const T &additive) {
        compressed_vector res = *this;
        for (auto [key, val] : res) {
            res[key] = val * additive;
        }
        return res;
    }

    compressed_vector operator/(const T &ladditive) {
        compressed_vector res = *this;
        for (auto [key, val] : res) {
            res[key] = val / ladditive;
        }
        return res;
    }

    compressed_vector operator+=(const T &additive) {
        for (auto [key, val] : container) {
            container[key] = val + additive;
        }
        return *this;
    }

    compressed_vector operator-=(const T &additive) {
        for (auto [key, val] : container) {
            container[key] = val - additive;
        }
        return *this;
    }

    compressed_vector operator*=(const T &additive) {
        for (auto [key, val] : container) {
            container[key] = val * additive;
        }
        return *this;
    }

    compressed_vector operator/=(const T &ladditive) {
        for (auto [key, val] : container) {
            container[key] = val / ladditive;
        }
        return *this;
    }
};

#endif