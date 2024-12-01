#include <iostream>

using namespace std;

int main() {
    const int SIZE = 1000;
    int array[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        array[i] = rand() % 61 - 30;
    }

    int array_stupid[SIZE], array_gnome[SIZE], array_bubble[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        array_stupid[i] = array[i];
        array_gnome[i] = array[i];
        array_bubble[i] = array[i];
    }

    int iterations_stupid = 0;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < SIZE - 1; ++i) {
            iterations_stupid++;
            if (array_stupid[i] > array_stupid[i + 1]) {
                swap(array_stupid[i], array_stupid[i + 1]);
                sorted = false;
            }
        }
    }

    int iterations_gnome = 0;
    int index = 0;
    while (index < SIZE) {
        iterations_gnome++;
        if (index == 0 || array_gnome[index] >= array_gnome[index - 1]) {
            index++;
        } else {
            swap(array_gnome[index], array_gnome[index - 1]);
            index--;
        }
    }

    int iterations_bubble = 0;
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            iterations_bubble++;
            if (array_bubble[j] > array_bubble[j + 1]) {
                swap(array_bubble[j], array_bubble[j + 1]);
            }
        }
    }

    cout << "Stupid Sort iterations: " << iterations_stupid << endl;
    cout << "Gnome Sort iterations: " << iterations_gnome << endl;
    cout << "Bubble Sort iterations: " << iterations_bubble << endl;

}