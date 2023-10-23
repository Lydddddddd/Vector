// vector.cpp

#include "vector.h"
#include <stdexcept>

//template <typename T>
//Vector<T>::Vector(){}

template <typename T>
Vector<T>::Vector(size_t dim) : size(dim), data(NULL) {}

template <typename T>
Vector<T>::~Vector() {}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
    size = other.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
size_t Vector<T>::getDimension() const {
    return size;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vector dimensions do not match");
    }
    Vector<T> result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = data[i] + other[i];
    }
    return result;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& other) const {
    bool f = true;
    if (size != other.size)
    {
        f = false;
        return f;
    }
    for (int i = 0; i < size; i++)
    {
        if (data[i] != other.data[i])
        {
            f = false;
            return f;
        }
    }
    return f;
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& other) const {
    return !(*this == other);
}

template <typename U>
std::ostream& operator<<(std::ostream& out, const Vector<U>& vec) {
    out << "(";
    for (size_t i = 0; i < vec.size; ++i) {
        out << vec.date[i]; 
        if (i < vec.size - 1) {
            out << ", ";
        }
    }
    out << ")";
    return out;
}

template <typename U>
std::istream& operator>>(std::istream& in, Vector<U>& vec) {
    for (size_t i = 0; i < vec.size; ++i) {
        in >> vec.data[i];
    }
    return in;
}
