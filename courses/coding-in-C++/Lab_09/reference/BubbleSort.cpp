#include <iostream>
using namespace std;

int main() {

    int arr[] = {7, 4, 5, 2};
    int n = 4;
    int temp;

    //Ausgabe des unsortierten Arrays
    cout << "Unsortiertes Array:";
    for (int k = 0; k < n; k++)
        cout << arr[k] << " ";
    cout << endl;

    //Bubble Sort Algorithmus
    for (int i = 0; i < n - 1; i++) {

        cout << "\nLauf " << (i+1) << ":" << endl;

        for (int j = 0; j < n - 1 - i; j++) {

            if (arr[j] > arr[j+1]) {
                temp       = arr[j];
                arr[j]     = arr[j+1];
                arr[j+1]   = temp;
                cout << "  Position  " << j+1 << " <-> " << (j+2) << " getauscht -> ";
            } else {
                cout << "  kein Tausch -> ";
            }

            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
            cout << endl;

            cout << "  [Enter]";
            cin.ignore();
        }
    }

    //Ausgabe des sortierten Arrays
    cout << "\nFertig: ";
    for (int k = 0; k < n; k++)
        cout << arr[k] << " ";
    cout << endl;

    return 0;
}