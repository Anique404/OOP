#include <iostream>
using namespace std;

class MyArray {
    int size;
    int *array;

    friend istream &operator>>(istream &input, MyArray &s);
    friend ostream &operator<<(ostream &output, const MyArray &s);

public:
    MyArray() : size(0), array(NULL) {}

    MyArray(int value, int n = 0) {
        size = n > 0 ? n : 5;
        array = new int[size];
        for (int index = 0; index < size; index++) {
            array[index] = value;
        }
    }

    MyArray(int *a, int n) {
        size = n > 0 ? n : 5;
        array = new int[size];
        for (int index = 0; index < size; index++) {
            array[index] = a[index];
        }
    }

    MyArray(const MyArray &a) {
        if (a.size != 0) {
            size = a.size;
            array = new int[size];
            for (int index = 0; index < size; index++) {
                array[index] = a.array[index];
            }
        } else {
            size = 0;
            array = NULL
			;
        }
    }

    ~MyArray() {
        if (array != NULL) {
            delete[] array;
            array = NULL;
        }
    }

    const int &operator[](int b) const {
        return array[b];
    }
    
    
    int &operator[](int b)  {
        return array[b];
    }
    
    
};



istream &operator>>(istream &input, MyArray &s) {
    while (s.size <= 0) {
        cout << "Enter size: ";
        input >> s.size;
    }
    s.array = new int[s.size];
    cout << "Enter elements: ";
    for (int i = 0; i < s.size; i++) {
        input >> s.array[i];
    }
    return input;
}



ostream &operator<<(ostream &output, const MyArray &s) {
    output << "Array elements: ";
    for (int i = 0; i < s.size; i++) {
        output << s.array[i] << " ";
    }
    output << endl;
    return output;
}



int main() {
    MyArray a3, a4;

    int list[6] = {1, 3, 2, 4, 7, 8};
    MyArray a1(5);
    MyArray a2(list, 6);

    cout << "Enter elements for a3:" << endl;
    cin >> a3;

    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;
    cout << "a3: " << a3 << endl;

    cout << "Accessing elements using [] operator:" << endl;
    cout << "a2[2]: " << a2[2] << endl;
    cout << "a3[0]: " << a3[0] << endl;

    MyArray a5 = a2; 
    cout << "a5 (copied from a2): " << a5 << endl;
    
    a2[2]=15;
    cout<<"a2:"<<a2;

    return 0;
}

