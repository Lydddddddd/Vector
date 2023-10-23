#pragma once
// Vector.h

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
    T* data;
    size_t size;

public:
    /*Vector();*/
    Vector(size_t dim = 0);
    ~Vector();

    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);

    size_t getDimension() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    Vector<T> operator+(const Vector<T>& other) const;
    bool operator==(const Vector<T>& other) const;
    bool operator!=(const Vector<T>& other) const;

    template <typename U>
    friend ostream& operator<<(ostream& out, const Vector<U>& vec);

    template <typename U>
    friend istream& operator>>(istream& in, Vector<U>& vec);
};
