#pragma once
#include <iostream>
#include <string>
using namespace std;

// ---------------------- IPayment ------------------------
class IPayment {
public:
    virtual void pay(double sum) = 0;
    virtual ~IPayment() {}
};

// ---------------------- Оплати ------------------------
class CashPayment : public IPayment {
public:
    void pay(double sum) override { cout << "Готівка: " << sum << " грн\n"; }
};

class CardPayment : public IPayment {
public:
    void pay(double sum) override { cout << "Карта: " << sum << " грн\n"; }
};

// ---------------------- ProductBase ----------------------
class ProductBase {
protected:
    string title;
    double price;

public:
    ProductBase(string t, double p) : title(t), price(p) {}

    virtual void showInfo() {
        cout << title << ", " << price << " грн\n";
    }

    void pay(IPayment* p, double sum) { p->pay(sum); }
};

// ---------------------- OnlineStore ----------------------
class OnlineStore : virtual public ProductBase {
public:
    OnlineStore(string t, double p) : ProductBase(t, p) {}
    void orderOnline() { cout << "Онлайн замовлення.\n"; }
    void showInfo() override { cout << "[Online] "; ProductBase::showInfo(); }
};

// ---------------------- LocalStore -----------------------
class LocalStore : virtual public ProductBase {
public:
    LocalStore(string t, double p) : ProductBase(t, p) {}
    void sellOffline() { cout << "Продаж офлайн.\n"; }
    void showInfo() override { cout << "[Local] "; ProductBase::showInfo(); }
};

// ---------------------- HybridStore ----------------------
class HybridStore : public OnlineStore, public LocalStore {
public:
    HybridStore(string t, double p)
        : ProductBase(t, p), OnlineStore(t, p), LocalStore(t, p) {
    }

    void showInfo() override {
        ProductBase::showInfo();
    }
};


