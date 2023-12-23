#include <iostream>
#include <chrono>
#include <unistd.h>
#include <windows.h>
#include <clocale>
#include "laba_1/main.cpp"
#include "laba_2/main.cpp"
#include "laba_3/main.cpp"
#include "laba_4/main.cpp"
using namespace std;

int main() {
    int choice;
    cout << "Navigation:" << "\n"
    << "Lab. 1"  << "\n"
    << "Lab. 2" << "\n"
    << "Lab. 3" << "\n"
    << "Lab. 4" << "\n";


while(true) {
        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();
        short int workPoint;
        
        cout << "Select laboratory work (number 1 to 4): ";
        cin >> workPoint;

        switch (workPoint)
        {   
            case 1: {
                laba_1::main();
                break;
            }
            case 2: {
                laba_2::main();
                break;
            }
            case 3: {
                laba_3::main();
                break;
            }
            case 4: {   
                laba_4::main();
                break;
            }
            default: {
                cout << "\n" << "You did not enter a number in the range from 1 to 4";
                break;
            }
        }

        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();

        char stopFlag;
        cout << "\n" << "Continue the main program? (Y/N) ";
        cin >> stopFlag;
        
        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}
