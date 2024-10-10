#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>

class Complex2D 
{
private:
    double real;
    double imag;

public:
    Complex2D();
    Complex2D(double real, double imag);
    Complex2D(Complex2D& c);
    double getReal() const;
    double getImag() const;
    int setReal(double real);
    int setImag(double imag);
    friend Complex2D operator+(const Complex2D& c1, const Complex2D& c2);
    friend Complex2D operator-(const Complex2D& c1, const Complex2D& c2);
    friend Complex2D operator*(const Complex2D& c1, const Complex2D& c2);
    friend Complex2D operator/(const Complex2D& c1, const Complex2D& c2);
    friend bool operator<(const Complex2D& c1, const Complex2D& c2);
    friend bool operator>(const Complex2D& c1, const Complex2D& c2);

};

#endif