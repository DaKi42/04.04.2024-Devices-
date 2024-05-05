#include <iostream>
using namespace std;

class Device {
public:
    virtual void Print() = 0;
    virtual ~Device() {}
};

class Videocard : public Device {
public:
    void Print() override { cout << "Nvidia GeForce RTX 4050" << endl; }
};

class CPU : public Device {
public:
    void Print() override { cout << "AMD RYZEN 9 7940HS 4 Ghz" << endl; }
};

class HDD : public Device {
public:
    void Print() override { cout << "WD Black SN850X 2 TB" << endl; }
};

class RAM : public Device {
public:
    void Print() override { cout << "Micron LTSQSD 32 Gb LPDDR5 5500 Mhz" << endl; }
};

class iPrint {
protected:
    Device* ptr;
public:
    iPrint(Device* device) : ptr(device) {}
    virtual void PrintToConsole() = 0;
    virtual ~iPrint() {}
};

class PrintDevice : public iPrint {
public:
    PrintDevice(Device* device) : iPrint(device) {}
    void PrintToConsole() override { ptr->Print(); }
    ~PrintDevice() override { delete ptr; }
};

int main() {
    Device* GPU = new Videocard();
    iPrint* printGPU = new PrintDevice(GPU);
    printGPU->PrintToConsole();
    Device* cpu = new CPU();
    iPrint* printCPU = new PrintDevice(cpu);
    printCPU->PrintToConsole();
    Device* SSD = new HDD();
    iPrint* printSSD = new PrintDevice(SSD);
    printSSD->PrintToConsole();
    Device* ram = new RAM();
    iPrint* printRAM = new PrintDevice(ram);
    printRAM->PrintToConsole();
    system("pause");
    return 0;
}