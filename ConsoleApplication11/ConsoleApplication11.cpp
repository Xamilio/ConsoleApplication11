#include <iostream>

using namespace std;

int main() {
    const int SIZE = 1000;
    int array[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        array[i] = rand() % 61 - 30;
    }

    int stupid[SIZE], gnome[SIZE], bubble[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        stupid[i] = array[i];
        gnome[i] = array[i];
        bubble[i] = array[i];
    }

    int iterations_stupid = 0;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < SIZE - 1; ++i) {
            iterations_stupid++;
            if (stupid[i] > stupid[i + 1]) {
                swap(stupid[i], stupid[i + 1]);
                sorted = false;
            }
        }
    }

    int iterations_gnome = 0;
    int index = 0;
    while (index < SIZE) {
        iterations_gnome++;
        if (index == 0 || gnome[index] >= gnome[index - 1]) {
            index++;
        } else {
            swap(gnome[index], gnome[index - 1]);
            index--;
        }
    }

    int iterations_bubble = 0;
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            iterations_bubble++;
            if (bubble[j] > bubble[j + 1]) {
                swap(bubble[j], bubble[j + 1]);
            }
        }
    }

    cout << "Stupid Sort iterations: " << iterations_stupid << endl;
    cout << "Gnome Sort iterations: " << iterations_gnome << endl;
    cout << "Bubble Sort iterations: " << iterations_bubble << endl;

}