#pragma once
#include <iostream>
#include "fstream"
#include "String.h"
#include "Class.h"
#include "Array.h"
/*тут будут лежать дополнительные функции которые понадобились мне дл€ выполнени€ задани€*/

int str_to_int(String& str);
int str_len(const char* ch);
int validate_number(int number);
String validate_time(String time);
int file_size(String str);
Array <Bus_trip> read_file();

void print_array(Array<Bus_trip>& arr);
template <class T>
void sort(Array <T>& array);
void answer_to_file(Array<Bus_trip>& arr);
void work_with_trips();
void find_min_number(Array<Bus_trip>& trips);