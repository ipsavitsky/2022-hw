#ifndef CMPRSD_VECTOR_HPP_
#define CMPRSD_VECTOR_HPP_

#include <unordered_map>
#include "exceptions.hpp"

template <typename T>
class compressed_vector {
   private:
    std::unordered_map<std::size_t, T> container;
    std::size_t vec_size;

    double eps = 10e-7;

   public:
    compressed_vector(std::size_t size) : vec_size(size) {}

    std::size_t get_size() { return vec_size; }

    T& operator()(std::size_t access) {
        if (access >= vec_size) {
            throw out_of_bounds_exception();
        }
        return container[access];
    }

    // template <typename L>
    // concept can_sum = requires(T t, L l) {
    //     { t + l } -> std::same_as<decltype(t + l)>;
    // };

    template <typename M>
    auto operator+(const compressed_vector<M>& other)
        -> decltype(this->operator()(0) + other(0)) {
        if (vec_size != other.vec_size) {
            throw incorrect_dimensions();
        }
        using res_elem_t = decltype(this->operator()(0) + other(0));
        compressed_vector<res_elem_t> res_vec(vec_size);
        for (std::size_t i = 0; i < vec_size; ++i) {
            res_elem_t res =
                container.contains(i) && other.container.contains(i)
                    ? container[i] + other(i)
                : container.contains(i)       ? container[i]
                : other.container.contains(i) ? other(i)
                                              : 0;
            res_vec(i) = res;
        }
    }

    template <typename M>
    auto operator-(const compressed_vector<M>& other)
        -> decltype(this->operator()(0) - other(0)) {
        if (vec_size != other.vec_size) {
            throw incorrect_dimensions();
        }
        using res_elem_t = decltype(this->operator()(0) - other(0));
        compressed_vector<res_elem_t> res_vec(vec_size);
        for (std::size_t i = 0; i < vec_size; ++i) {
            res_elem_t res =
                container.contains(i) && other.container.contains(i)
                    ? container[i] - other(i)
                : container.contains(i)       ? container[i]
                : other.container.contains(i) ? other(i)
                                              : 0;
            res_vec(i) = res;
        }
    }

    template <typename M>
    auto operator*(const compressed_vector<M>& other)
        -> decltype(this->operator()(0) * other(0)) {
        if (vec_size != other.vec_size) {
            throw incorrect_dimensions();
        }
        using res_elem_t = decltype(this->operator()(0) * other(0));
        compressed_vector<res_elem_t> res_vec(vec_size);
        for (std::size_t i = 0; i < vec_size; ++i) {
            res_elem_t res =
                container.contains(i) && other.container.contains(i)
                    ? container[i] * other(i)
                : container.contains(i)       ? container[i]
                : other.container.contains(i) ? other(i)
                                              : 0;
            res_vec(i) = res;
        }
    }

    template <typename M>
    auto operator/(const compressed_vector<M>& other)
        -> decltype(this->operator()(0) / other(0)) {
        if (vec_size != other.vec_size) {
            throw incorrect_dimensions();
        }
        using res_elem_t = decltype(this->operator()(0) / other(0));
        compressed_vector<res_elem_t> res_vec(vec_size);
        for (std::size_t i = 0; i < vec_size; ++i) {
            res_elem_t res =
                container.contains(i) && other.container.contains(i)
                    ? container[i] / other(i)
                : container.contains(i)       ? container[i]
                : other.container.contains(i) ? other(i)
                                              : 0;
            res_vec(i) = res;
        }
    }

    compressed_vector<T> operator+(const T& additive) {
        compressed_vector res = *this;
        res += additive;
        return res;
    }

    compressed_vector<T> operator-(const T& additive) {
        compressed_vector res = *this;
        res -= additive;
        return res;
    }

    compressed_vector<T> operator*(const T& additive) {
        compressed_vector res = *this;
        res *= additive;
        return res;
    }

    compressed_vector<T> operator/(const T& additive) {
        compressed_vector res = *this;
        res /= additive;
        return res;
    }

    compressed_vector<T> operator+=(const T& additive) {
        for (std::size_t i = 0; i < vec_size; ++i) {
            container[i] += additive;
        }
        return *this;
    }

    compressed_vector<T> operator-=(const T& additive) {
        for (std::size_t i = 0; i < vec_size; ++i) {
            container[i] -= additive;
        }
        return *this;
    }

    compressed_vector<T> operator*=(const T& additive) {
        for (std::size_t i = 0; i < vec_size; ++i) {
            container[i] *= additive;
        }
        return *this;
    }

    compressed_vector<T> operator/=(const T& additive) {
        for (std::size_t i = 0; i < vec_size; ++i) {
            container[i] /= additive;
        }
        return *this;
    }
};

#endif