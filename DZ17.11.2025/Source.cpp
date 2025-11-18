#include "Header.h"

int main() {
    Employer* arr[3];

    arr[0] = new President();
    arr[1] = new Manager();
    arr[2] = new Worker();

    for (int i = 0; i < 3; i++) {
        arr[i]->Print();
    }

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    return 0;
}
