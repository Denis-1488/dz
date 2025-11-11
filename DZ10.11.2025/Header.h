#pragma once

#include <iostream>
#include <string>
using namespace std;

// ======= Клас Мишка =======
class Mouse {
private:
    string brand;
    int dpi;
    bool wireless;
public:
    Mouse(string brand, int dpi, bool wireless)
        : brand(brand), dpi(dpi), wireless(wireless) {
    }
    void showInfo() const {
        cout << "Mouse: " << brand
            << ", DPI: " << dpi
            << ", Wireless: " << (wireless ? "Yes" : "No") << endl;
    }
};

// ======= Клас Клавіатура =======
class Keyboard {
private:
    string brand;
    bool backlight;
    int keysCount;
public:
    Keyboard(string brand, bool backlight, int keysCount)
        : brand(brand), backlight(backlight), keysCount(keysCount) {
    }
    void showInfo() const {
        cout << "Keyboard: " << brand
            << ", Keys: " << keysCount
            << ", Backlight: " << (backlight ? "Yes" : "No") << endl;
    }
};

// ======= Клас Процесор =======
class Processor {
private:
    string model;
    int cores;
    double frequency;
    string manufacturer;
public:
    Processor(string model, int cores, double frequency, string manufacturer)
        : model(model), cores(cores), frequency(frequency), manufacturer(manufacturer) {
    }
    void showInfo() const {
        cout << "Processor: " << model
            << " (" << manufacturer << "), Cores: " << cores
            << ", " << frequency << " GHz" << endl;
    }
};

// ======= Клас Оперативна пам’ять =======
class RAM {
private:
    string type;
    int sizeGB;
    int frequencyMHz;
    string manufacturer;
public:
    RAM(string type, int sizeGB, int frequencyMHz, string manufacturer)
        : type(type), sizeGB(sizeGB), frequencyMHz(frequencyMHz), manufacturer(manufacturer) {
    }
    void showInfo() const {
        cout << "RAM: " << sizeGB << "GB " << type
            << ", " << frequencyMHz << "MHz (" << manufacturer << ")" << endl;
    }
};

// ======= Головний клас PC =======
class PC {
private:
    Processor processor;
    RAM ram;
    Mouse* mouse;
    Keyboard* keyboard;
public:
    PC(const Processor& proc, const RAM& ram, Mouse* m, Keyboard* k)
        : processor(proc), ram(ram), mouse(m), keyboard(k) {
    }

    void showInfo() const {
        cout << "=== PC Info ===" << endl;
        processor.showInfo();
        ram.showInfo();
        if (mouse) mouse->showInfo();
        if (keyboard) keyboard->showInfo();
    }
};


