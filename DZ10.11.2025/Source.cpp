#include "Header.h"

int main() {
    setlocale(LC_ALL, "");
    Mouse mouse("Hator Pulsar 2 Pro", 16000, true);
    Keyboard keyboard("AULA F75", true, 80);
    Processor proc("Ryzen 5 5500", 6, 3.6, "AMD");
    RAM ram("DDR4", 16, 3600, "Kingston");

    PC myPC(proc, ram, &mouse, &keyboard);
    myPC.showInfo();

    return 0;
}
