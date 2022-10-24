#ifndef CMPRSD_VECTOR_HPP_
#define CMPRSD_VECTOR_HPP_

#include <unordered_map>
#include "exceptions.hpp"

template <typename T>
class compressed_vector {
   private:
    std::unordered_map<std::size_t, T> container;
    std::size_t vec_size;

   public:
    class matrix_equality_proxy {
       private:
        compressed_vector<T>* outer_vec;
        std::size_t index;
        double eps = 10e-7;

       public:
        matrix_equality_proxy(compressed_vector<T>* vec, std::size_t elem_num)
            : outer_vec(vec), index(elem_num) {}

        operator T() { return outer_vec->operator()(index); }

        matrix_equality_proxy& operator=(T elem) {
            if (elem > eps) {
                outer_vec->container[index] = elem;
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os,
                                        const matrix_equality_proxy& rn) {
            os << rn;
            return os;
        }
    };

    compressed_vector(std::size_t size) : vec_size(size) {}

    std::size_t get_size() { return vec_size; }

    matrix_equality_proxy& operator()(std::size_t access) {
        if (access >= vec_size) {
            throw out_of_bounds_exception();
        }
        auto ret = matrix_equality_proxy(this, access); 
        return ret;
    }

    T at(std::size_t access) const {
        if (access >= vec_size) {
            throw out_of_bounds_exception();
        }
        return container.at(access);
    }

    compressed_vector<T> operator+(const compressed_vector<T>& other) {
        if (vec_size != other.vec_size) {
            throw incorrect_dimensions();
        }
        compressed_vector<T> res_vec(vec_size);
        for (std::size_t i = 0; i < vec_size; ++i) {
            T res = container.contains(i) && other.container.contains(i)
                        ? container[i] + other.at(i)
                    : container.contains(i)       ? container[i]
                    : other.container.contains(i) ? other.at(i)
                                                  : 0;
            res_vec(i) = res;
        }
        return res_vec;
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

    friend std::ostream& operator<<(std::ostream& os,
                                    const compressed_vector<T>& rn) {
        for (int i = 0; i < rn.get_size(); ++i) {
            os << rn(i);
        }
        return os;
    }
};

#endif