#include <iostream>
using namespace std;

class Student
{
    char* name{ nullptr };
public:
    Student() = default;

    Student(const char* name)
    {
        setName(name);
    }

    Student(const Student& other)
    {
        setName(other.name); //Конструктор копирования
    }

    Student(Student&& obj) noexcept
    {
        this->name = obj.name;
        obj.name = nullptr;
        //Конструктор переміщення
    }

    Student& operator=(const Student& other)
    {
        if (this != &other)
        {
            setName(other.name); //Оператор копирования 
        }
        return *this;
    }

    void setName(const char* name)
    {
        if (this->name)
        {
            delete[] this->name;
            this->name = nullptr;
        }
        if (name)
        {
            unsigned int len = strlen(name);
            this->name = new char[len + 1];
            strcpy_s(this->name, len + 1, name);
        }
    }

    ~Student()
    {
        if (name)
            delete[] name;
    }
};

void printName(const Student& stObj)
{
    cout << "Student name printed from function." << endl;
    //Передача по const посиланню — копіювання не відбувається
}

Student createStudent()
{
    bool flag = true;
    Student s1("Bob");
    Student s2("Alice");

    if (flag) return s1;
    else return s2;
}

int main()
{
    /*Student st5("John");
    Student st6 = move(st5);  
    Student st7 = st6;*/

    Student st4{ createStudent() };

    const unsigned int N = 30;
    char* name = new char[N];
    cout << "Enter student name: ";
    cin.getline(name, N);

    {
        Student st(name);       // Викликається звичайний конструктор
        printName(st);          //Передача по посиланню, без копії
        Student st2{ st };      //Конструктор копирования
        Student st3;
        st3 = st2;              //Оператор копирования
    }

    cout << name;
    delete[] name;

    return 0;
}
