#include "Header.h"

int main() {
    setlocale(LC_ALL, "");
    CashPayment cash;
    CardPayment card;

    HybridStore hs("iPhone 17", 63999);

    hs.showInfo();
    hs.orderOnline();
    hs.sellOffline();

    hs.pay(&card, 63999);

    return 0;
}
