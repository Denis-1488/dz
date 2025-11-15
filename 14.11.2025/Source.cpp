#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int age;
    string group;

public:
    Student(string name, int age, string group)
        : name(name), age(age), group(group) {
    }

    void Print() const {
        cout << "Student: " << name
            << "\nAge: " << age
            << "\nGroup: " << group << endl;
    }
};

class Aspirant : public Student {
private:
    string thesisTopic;

public:


    Aspirant(string name, int age, string group)
        : Student(name, age, group), thesisTopic("") {
    }

    void Print() const {
        cout << "Aspirant: " << name
            << "\nAge: " << age
            << "\nGroup: " << group
            << "\ntopic git : " << thesisTopic << endl;
    }
};

int main() {
    setlocale(LC_ALL, "");
    Student st("Денис Тишковський", -99, "ПВ-521");
    Aspirant asp("Petro Ivanov", 25, "ПВ-521");

    st.Print();
    cout << endl;
    asp.Print();

    return 0;
}
