#include "Headere.h"

int main() {
    setlocale(LC_ALL, "");
    SinglyLinkedList<int> list;

    list.AddToHead(10);
    list.AddToHead(5);
    list.AddToTail(20);
    list.AddToTail(30);

    cout << "Список: ";
    list.Show();

    list.DeleteFromHead();
    cout << "Після видалення з голови: ";
    list.Show();

    list.DeleteFromTail();
    cout << "Після видалення з хвоста: ";
    list.Show();

    list.DeleteAll();
    cout << "Після видалення всіх: ";
    list.Show();

    return 0;
}
