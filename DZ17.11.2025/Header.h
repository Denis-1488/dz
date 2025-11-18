#pragma once

#include <iostream>
using namespace std;

// Абстрактный базовый класс
class Employer {
public:
    virtual void Print() const = 0;
    virtual ~Employer() {}
};

// Президент
class President : public Employer {
public:
    void Print() const override {
        cout << "I am President of the company\n";
    }
};

// Менеджер
class Manager : public Employer {
public:
    void Print() const override {
        cout << "I am Manager\n";
    }
};

// Рабочий
class Worker : public Employer {
public:
    void Print() const override {
        cout << "I am Worker\n";
    }
};



