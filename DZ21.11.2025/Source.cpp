#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ===== Абстрактний клас Character =====
class Character {
public:
    virtual void attack() = 0;
    virtual string getInfo() = 0;

    virtual ~Character() {}
};

// ===== Похідні класи =====

class Warrior : public Character {
    string name;
public:
    Warrior(string n) : name(n) {}

    void attack() override {
        cout << name << " (Warrior) атакує мечем!" << endl;
    }

    string getInfo() override {
        return "Warrior: " + name;
    }
};

class Mage : public Character {
    string name;
public:
    Mage(string n) : name(n) {}

    void attack() override {
        cout << name << " (Mage) кидає вогняну кулю!" << endl;
    }

    string getInfo() override {
        return "Mage: " + name;
    }
};

class Archer : public Character {
    string name;
public:
    Archer(string n) : name(n) {}

    void attack() override {
        cout << name << " (Archer) стріляє з лука!" << endl;
    }

    string getInfo() override {
        return "Archer: " + name;
    }
};

// ===== Клас Arena =====
class Arena {
    vector<Character*> fighters;

public:
    // Додати персонажа
    void add(Character* c) {
        fighters.push_back(c);
    }

    // Видалити персонажа за індексом
    void removeAt(int index) {
        if (index >= 0 && index < fighters.size()) {
            delete fighters[index];
            fighters.erase(fighters.begin() + index);
        }
    }

    // Запуск атаки всіх бійців
    void startFight() {
        for (auto& f : fighters) {
            f->attack();
        }
    }

    // Перевантаження операторів
    // operator+
    Arena& operator+(Character* c) {
        add(c);
        return *this;
    }

    // operator<<
    friend ostream& operator<<(ostream& os, const Arena& a) {
        os << "Список бійців на арені:\n";
        for (int i = 0; i < a.fighters.size(); i++) {
            os << i << ") " << a.fighters[i]->getInfo() << endl;
        }
        return os;
    }

    // Деструктор – очищає пам'ять
    ~Arena() {
        for (auto f : fighters) delete f;
    }
};

int main() {
    setlocale(LC_ALL, "");
    Arena arena;

    arena = arena + new Warrior("Thor");
    arena = arena + new Mage("Gandalf");
    arena = arena + new Archer("Legolas");

    cout << arena;

    cout << "\n--- Атака всіх бійців ---\n";
    arena.startFight();

    return 0;
}



