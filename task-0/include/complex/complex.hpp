#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

template <typename type_real, typename type_imag> class Complex_number {
  private:
    type_real rl;
    type_imag im;

  public:
    // Complex_number();
    Complex_number(type_real real, type_imag imag);
};

#endif