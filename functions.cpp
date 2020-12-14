#include <iostream>
#include "fstream"
#include "String.h"
#include "Class.h"
#include "functions.h"
#include "Array.h"
#include <iomanip>

int str_to_int(String& str) {
	int len = str.get_len();
	char* data = str.get_data();
	int num = 0;
	if (len == 0) {
		return 0;
	}
	for (int i = 0; i < len; i++) {
		if (data[i] >= '0' && data[i] <= '9') {
			num += data[i] - '0';
			num = num * 10;
		}
	}
	num = num / 10;
	return num;
}

int str_len(const char* ch) {
	int i = 0;
	while (true) {
		if (ch[i] == '\n' || ch[i] == '\t' || ch[i] == '\0') {
			break;
		}
		i++;
	}
	return i;
}

int validate_number(int number) {
	if (number >= 0) {
		return number;
	}
	else {
		std::cout << "Найдена ошибка в записи данных файла!" << std::endl;
	}
	return number;
}

String validate_time(String time) {
	if (((str_to_int(time) / 100 <= 24) && (str_to_int(time) / 100 >= 0)) && (((str_to_int(time) % 100 <= 59) && (str_to_int(time) % 100 >= 0)))) {
		return time;
	}
	else {
		time = String("###");
	}
	return time;
}

int file_size(String str) {
	std::ifstream stream;
	stream.open(str.get_data());
	int count = 0;
	while (stream.ignore(32265, '\n')) {
		count++;
	}
	stream.close();
	return count;
}

Array <Bus_trip> read_file() {
	String path;
	std::cout << "Введите файл, из которого будет происходить ввод\n";
	std::ifstream stream;
	while (!(std::cin >> path)) {
		std::cout << "Ошибка при попытке чтения файла. Пожалуйста, попробуйте снова.";
		std::cin.clear();
		std::cin.get();
	}
	stream.open(path.get_data());
	int size = file_size(path);

	Array<Bus_trip> arr(size);
	std::cout << "Считанные данные: " << "\n";
	for (int i = 0; i < size; i++) {
		stream >> arr[i];
	}
	stream.close();
	sort(arr);
	print_array(arr);
	return arr;
}
template <class T>
void sort(Array <T>& array)
{
	T temp;
	int len = array.get_size();
	for (int i = 0; i < len - 1; ++i)
	{
		int smallest_index = i;
		for (int current_index = i + 1; current_index < len; ++current_index)
		{
			if (array[current_index].get_number() < array[smallest_index].get_number())
				smallest_index = current_index;
		}
		std::swap(array[i], array[smallest_index]);
	}
}
void print_array(Array <Bus_trip>& arr) {
	int size = arr.get_size();
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << std::setw(10) << std::endl;
	}
}
void answer_to_file(Array<Bus_trip>& arr) {
	std::ofstream stream("output.txt");
	int size = arr.get_size();
	String num_head = String("Номер автобуса:");
	String name_head = String("Пункт назначения:");
	String time_head = String("Время отправления:");
	stream << std::setw(10) << "|" << num_head << std::setw(24 - num_head.get_len()) << "|" << name_head << std::setw(23 - name_head.get_len()) << "|" << time_head  << std::setw(23 - time_head.get_len()) << "|"<<"\n" << std::endl;
	for (int i = 0; i < size; i++) {
		stream << std::setw(10) << "|" << arr[i].get_number() << std::setw(23 - sizeof(arr[i].get_number())/sizeof(int)) << "|" << arr[i].get_name() << std::setw(23 - arr[i].get_name().get_len()) << "|" << arr[i].get_time() << std::setw(23- arr[i].get_time().get_len()) << "|" << std::endl;
	}

}
void find_min_number(Array<Bus_trip>& trips) {
	int size = trips.get_size();
	int min = trips[0].get_number();
	for (int i = 0; i < size; i++) {
		if (trips[i] < min) {
			min = trips[i].get_number();
		}
	}
	std::cout << "Найден автобус с наименьшим номером: " << min << std::endl;
}

void work_with_trips() {
	Array<Bus_trip> trips = read_file();
	find_min_number(trips);
	sort(trips);
	answer_to_file(trips);
}

