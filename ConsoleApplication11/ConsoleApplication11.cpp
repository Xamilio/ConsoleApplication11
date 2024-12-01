#include <iostream>
using namespace std;

int main() {
    const int SIZE = 1000;
    int array[SIZE];
    int max = 30;
    int min = -30;
    for (int i = 0; i < SIZE; ++i) 
    {
        array[i] = rand() % (max - min) + min;
    }

    int stupid[SIZE], gnome[SIZE], bubble[SIZE];
    for (int i = 0; i < SIZE; ++i) 
    {
        stupid[i] = array[i];
        gnome[i] = array[i];
        bubble[i] = array[i];
    }

    int itr_stupid = 0;
    bool sorted = false;
    while (!sorted) 
    {
        sorted = true;
        for (int i = 0; i < SIZE - 1; ++i) 
        {
            itr_stupid++;
            if (stupid[i] > stupid[i + 1]) 
            {
                swap(stupid[i], stupid[i + 1]);
                sorted = false;
            }
        }
    }

    int itr_gnome = 0;
    int index = 0;
    while (index < SIZE) 
    {
        itr_gnome++;
        if (index == 0 || gnome[index] >= gnome[index - 1]) 
        {
            index++;
        }
        else 
        {
            swap(gnome[index], gnome[index - 1]);
            index--;
        }
    }

    int itr_bubble = 0;
    for (int i = 0; i < SIZE - 1; ++i) 
    {
        for (int j = 0; j < SIZE - i - 1; ++j) 
        {
            itr_bubble++;
            if (bubble[j] > bubble[j + 1]) 
            {
                swap(bubble[j], bubble[j + 1]);
            }
        }
    }

    cout << "Stupid Sort iterations: " << itr_stupid << endl;
    cout << "Gnome Sort iterations: " << itr_gnome << endl;
    cout << "Bubble Sort iterations: " << itr_bubble << endl;

}
