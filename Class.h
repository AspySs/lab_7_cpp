#pragma once
#include <iostream>
#include "String.h"
/*.ƒанный класс имеет три пол€ (номер рейса, врем€ отправлени€, пункт назначени€), имеет перегруженные операторы ++ пост\преф, + - < > = << >>.*/

class Bus_trip
{
public:
	Bus_trip();
	Bus_trip(int num, String dest_name, String time);
	Bus_trip(const Bus_trip& other);
	~Bus_trip();
	void operator +(Bus_trip& trip);
	friend void operator - (Bus_trip& trip, int num);
	bool operator < (Bus_trip& trip_2);
	friend bool operator > (Bus_trip& trip_1, Bus_trip& trip_2);
	bool operator > (int num);
	bool operator < (int num);
	Bus_trip& operator =(const Bus_trip& other);
	friend Bus_trip& operator++(Bus_trip& other);
	friend Bus_trip operator++(Bus_trip& trip, int);
	friend std::istream& operator >> (std::istream& stream, Bus_trip& trip);
	friend std::ostream& operator << (std::ostream& stream, const Bus_trip& trip);
	String get_name();
	String get_time();
	int get_number();
	void set_name(String name);
	void set_time(String time);
	void set_number(int numb);

private:
	int number_;
	String destination_;
	String time_;
};