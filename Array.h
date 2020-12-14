#pragma once
#include <iostream>
#include "Class.h"

template <class T>
class Array
{
public:
	Array();
	Array(int size);
	Array(const Array& arr);
	~Array();
	T& operator[] (int i) const;
	Array& operator=(const Array& arr);
	int get_size();
	void push_back(T& element);
	friend bool operator==(const Array& arr, const Array& other);
	friend bool operator!=(const Array& arr, const Array& other);
private:
	T* data_;
	int size_;
};

template <class T>
Array<T>::Array()
{
	data_ = nullptr;
	size_ = 0;
}

template <class T>
Array<T>::Array(int size)
{
	if (size == 0) {
		data_ = nullptr;
		size_ = 0;
	}
	else {
		size_ = size;
		data_ = new T[size];
	}
}

template <class T>
Array<T>::Array(const Array& other)
{
	if (other.size_ == 0) {
		data_ = nullptr;
		size_ = 0;
	}
	else {
		size_ = other.size_;
		data_ = new T[size_];
		for (int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
	}
}

template <class T>
T& Array<T>::operator[] (int i) const
{
	if (i < 0 || i > size_) {
		throw "Error";
	}
	return data_[i];
}

template <class T>
bool operator==(const Array<T>& arr, const Array<T>& other)
{
	if (arr.size_ == other.size_) {
		for (int i = 0; i < arr.size_; i++) {
			if (arr.data_[i] != other.data_[i]) {
				return false;
			}
			return true;
		}
	}
	return false;
}

template <class T>
bool operator!=(const Array<T>& arr, const Array<T>& other)
{
	return !(arr == other);
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (data_ != nullptr) {
		delete[] data_;
	}
	size_ = other.size_;
	data_ = new T & [size_];
	for (int i = 0; i < size_; i++) {
		data_[i] = other.data_[i];
	}
}

template <class T>
void Array<T>::push_back(T& element)
{
	if (size_ == 0 || data_ == nullptr) {
		this.data = new T[1];
		this.data[0] = element;
	}
	else {
		Array<T> Temp(this);
		size_++;
		delete[] data_;
		data_ = new T[size_];
		for (int i = 0; i < size_ - 1; i++) {
			data_[i] = Temp[i];
		}
		delete[] Temp;
		data_[size_] = element;
	}
}

template <class T>
std::istream& operator>>(std::istream& stream, Array<T>& arr)
{
	for (int i = 0; i < arr.size_; i++) {
		stream >> arr >> " ";
	}
	return stream;
}

template <class T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& arr)
{
	for (int i = 0; i < arr.size_; i++) {
		stream << arr << " ";
	}
	return stream;
}

template <class T>
int Array<T>::get_size()
{
	return size_;
}

template <class T>
Array<T>::~Array()
{
	delete[] data_;
}