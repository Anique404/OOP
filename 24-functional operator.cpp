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
            array = NULL;
        }
    }

    ~MyArray() {
        if (array != NULL) {
            delete[] array;
            array = NULL;
        }
    }

    MyArray operator()(int start, int n) {
        if (start < 0 || start >= size || n < 0) {
            cout << "Invalid values" << endl;
            return MyArray();
        }

        MyArray a;
        a.size = n;
        a.array = new int[a.size];
        for (int i = 0; i < n; i++) {
            if (start + i < size) {
                a.array[i] = array[start + i];
            } else {
                a.array[i] = 0;
            }
        }
        return a;
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
    int list[6] = {1, 3, 2, 4, 7, 8};
    MyArray a1(5);
    MyArray a2(list, 6);
    cout<<a1;
    cout<<a2;

    a2 = a2(2, 3);
    cout << a2;

    return 0;
}

