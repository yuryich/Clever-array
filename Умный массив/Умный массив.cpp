#include <iostream>
#include <stdexcept>

using namespace std;

class Clever_array
{
public:
	Clever_array(int p_size) : size(p_size), current_size(0) {
		if (size <= 0) {
			throw invalid_argument("Размер массива должен быть больше нуля.");
		}
		array = new int[size]; 
	}

	void append(int value) {
		if (current_size >= size) {
			throw out_of_range("Превышен размер массива.");
		}
		array[current_size++] = value;
	}

	int get_element(int ind) {
		if (ind < 0 || ind >= current_size) {
			throw out_of_range("Некорректный индекс.");
		}
		return array[ind];
	}

	~Clever_array() {
		delete[] array; 
	}

private:
	int* array;         
	int size;           
	int current_size;   
};

int main()
{
	setlocale(LC_ALL, "rus");
	try {
		Clever_array arr(5);
		arr.append(1);
		arr.append(4);
		arr.append(155);
		arr.append(14);
		arr.append(15);

		cout << arr.get_element(1) << endl;
		cout << arr.get_element(10) << endl;
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}
