#pragma once
#include <iostream>
#include "String.h"
#include "Class.h"
#include "functions.h"
#include "Array.h"
/*3. Создать массив из объектов разработанного класса. Ввести в массив данные из текстового
файла. Имя файла со входными данными должны вводиться из потока cin.
4. Определить минимальный номер маршрута. Для сравнения использовать перегруженный
оператор отношения, поиск элемента выполнить в отдельной процедуре.
5. Выполнить сортировку массива методом простого выбора по времени отправления. Для
сортировки написать и использовать шаблон функции. Результат вывести в файл в виде
таблицы, сделать заголовки колонок таблицы.*/


Bus_trip::Bus_trip() {
	int number_ = NULL;
	String time_;
	String destination_;
}

Bus_trip::Bus_trip(int num, String dest_name, String time) {
	number_ = num;
	time_ = time;
	destination_ = dest_name;
}

Bus_trip::Bus_trip(const Bus_trip& other) {
	number_ = other.number_;
	time_ = other.time_;
	destination_ = other.destination_;
}

Bus_trip::~Bus_trip() {

}

void Bus_trip::operator +(Bus_trip& trip) {

}
void operator -(Bus_trip& trip) {

}
bool Bus_trip::operator < (Bus_trip& trip_2) {
	if (str_to_int(time_) < str_to_int(trip_2.time_)) {
		return true;
	}
	else {
		return false;
	}
}

bool operator > (Bus_trip& trip_1, Bus_trip& trip_2) {
	if (str_to_int(trip_1.time_) > str_to_int(trip_2.time_)) {
		return true;
	}
	else {
		return false;
	}
}
bool Bus_trip::operator > (int num) {
	if (number_ > num) {
		return true;
	}
	else {
		return false;
	}
}
bool Bus_trip::operator < (int num) {
	if (number_ < num) {
		return true;
	}
	else {
		return false;
	}
}
Bus_trip& Bus_trip::operator =(const Bus_trip& trip_2) {
	set_number(trip_2.number_);
	set_name(trip_2.destination_);
	set_time(trip_2.time_);
	return *this;
}
Bus_trip& operator++(Bus_trip& trip_1) {
	++trip_1.number_;
	return trip_1;
}
Bus_trip operator++(Bus_trip& trip_1, int) {
	trip_1.number_++;
	return trip_1;
}

std::istream& operator >> (std::istream& stream, Bus_trip& trip) {
	Bus_trip temp;
	int num = 0;
	stream >> num;
	String num_out = validate_int(num);
	stream >> temp.destination_;
	stream >> temp.time_;
	temp.set_number(num);
	int number = temp.get_number();
	String destination = temp.destination_;
	String time = validate_time(temp.time_);
	std::cout << "|" << num_out << "|" << destination << "|" << time << "|" << "\n";
	trip = Bus_trip(number, destination, time);
	return stream;
}
std::ostream& operator << (std::ostream& stream, const Bus_trip& trip) {
	stream << "|" << trip.number_ << "|" << trip.destination_ << "|" << trip.time_ << "|" << "\n";
	return stream;
}

String Bus_trip::get_name() {
	return destination_;
}
String Bus_trip::get_time() {
	return time_;
}
int Bus_trip::get_number() {
	return number_;
}

void Bus_trip::set_name(String name) {
	destination_ = name;
}
void Bus_trip::set_time(String time) {
	time_ = time;
}
void Bus_trip::set_number(int numb) {
	number_ = numb;
}