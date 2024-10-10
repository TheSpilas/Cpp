#include "main.h"


Complex2D::Complex2D() : real(0), imag(0) {}

Complex2D::Complex2D(double real, double imag) : real(real), imag(imag) {}

Complex2D::Complex2D(const Complex2D& c) : real(c.getReal()), imag(c.getImag()) {}

double Complex2D::getReal() const {
    return real;
}

double Complex2D::getImag() const {
    return imag;
}

int Complex2D::setReal(double real) {
    this->real = real;
    return 0;
}

int Complex2D::setImag(double imag) {
    this->imag = imag;
    return 0;
}

Complex2D operator+(const Complex2D& c1, const Complex2D& c2) {
    return Complex2D(c1.real + c2.real, c1.imag + c2.imag);
}

Complex2D operator-(const Complex2D& c1, const Complex2D& c2) {
    return Complex2D(c1.real - c2.real, c1.imag - c2.imag);
}

Complex2D operator*(const Complex2D& c1, const Complex2D& c2) {
    return Complex2D(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real);
}

Complex2D operator/(const Complex2D& c1, const Complex2D& c2) {
    double denominateur = c2.real * c2.real + c2.imag * c2.imag;
    return Complex2D((c1.real * c2.real + c1.imag * c2.imag) / denominateur, (c1.imag * c2.real - c1.real * c2.imag) / denominateur);
}

bool operator<(const Complex2D& c1, const Complex2D& c2) {
    return (c1.real * c1.real + c1.imag * c1.imag) < (c2.real * c2.real + c2.imag * c2.imag);
}

bool operator>(const Complex2D& c1, const Complex2D& c2) {
    return (c1.real * c1.real + c1.imag * c1.imag) > (c2.real * c2.real + c2.imag * c2.imag);
}


int main() {
    Complex2D c1(1.0, 3.0);
    Complex2D c2(1.0, 2.0);
    Complex2D c3 = c1 + c2;
    Complex2D c4 = c1 - c2;
    Complex2D c5 = c1 * c2;
    Complex2D c6 = c1 / c2;
    std::cout << "c1 + c2 = " << c3.getReal() << " + " << c3.getImag() << "i" << std::endl;
    std::cout << "c1 - c2 = " << c4.getReal() << " + " << c4.getImag() << "i" << std::endl;
    std::cout << "c1 * c2 = " << c5.getReal() << " + " << c5.getImag() << "i" << std::endl;
    std::cout << "c1 / c2 = " << c6.getReal() << " + " << c6.getImag() << "i" << std::endl;
    std::cout << "c1 < c2 = " << (c1 < c2) << std::endl;
    std::cout << "c1 > c2 = " << (c1 > c2) << std::endl;
    return 0;
}