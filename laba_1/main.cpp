#include <iostream>
using namespace std;

namespace laba_1 {
int main () {
    setlocale(LC_ALL, "Russian");

    short int order = sizeof(int) * 8 - 1;

    cout << "Navigation:" << "\n"
    << "1) How much memory (in bytes) is allocated for different data types" << "\n"
    << "2) Binary representation in memory (all bits) of an integer" << "\n"
    << "3) Binary representation in memory (all bits) of type float" << "\n"
    << "4) Binary representation in memory (all bits) of type double" << "\n";

    while(true) {
        unsigned int mask = 1 << order;
        short int workPoint;
        
        cout << "Select point of work (number 1 to 4): ";
        cin >> workPoint;

        switch (workPoint)
        {
            case 1: {
                cout << 
                "int: " << sizeof(int) << "\n" <<
                "short int: " << sizeof(short int) << "\n" <<
                "long int: " << sizeof(long int) << "\n" <<
                "float: " << sizeof(float) << "\n" <<
                "double: " << sizeof(double) << "\n" <<
                "long double: " << sizeof(long double) << "\n" <<
                "char: " << sizeof(char) << "\n" <<
                "bool: " << sizeof(bool) << "\n";
                break;
            }
            case 2: {
                int number;
                cout << "\n" << "Enter an integer: ";
                cin >> number;
                if (!cin.good()) {
                    cout << "\n" << "You entered an incorrect value";
                    break;
                }

                for (int i = 0; i <= order; i++) {
                    cout << ((number & mask) ? 1: 0);
                    mask >>= 1;
                    if ((i + 1) % 8 == 0 || !i) {
                        cout << " ";
                    }
                }

                break;
            }
            case 3: {
                union {
                    int number;
                    float floatNumber;
                };

                cout << "\n" << "Enter a float number: ";
                cin >> floatNumber;
                if (!cin.good()) {
                    cout << "\n" << "You entered an incorrect value";
                    break;
                }

                for (int i = 0; i <= order; i++) {
                    cout << ((number & mask) ? 1 : 0);
                    mask >>= 1;
                    if (i == 8 || !i) {
                        cout << " ";
                    }
                }
                break; 
            } 
            case 4: {
                union {
                    int numberArray [2] = {};
                    double doubleNumber;
                };

                cout << "\n" << "Enter a double precision number: ";
                cin >> doubleNumber;
                if (!cin.good()) {
                    cout << "\n" << "You entered an incorrect value";
                    break;
                }

                // Swap array elements for correct binary representation
                int tempElement = numberArray[1];
                numberArray[1] = numberArray[0];
                numberArray[0] = tempElement;
                
                for (int j = 0; j < 2; j++) {
                    for (int i = 0; i <= order; i++) {
                        cout << ((numberArray[j] & mask) ? 1: 0);
                        mask >>= 1;
                        if (!j && i == 11 || !j && !i) {
                            cout << " ";
                        }
                    }
                    mask = 1 << order;
                }
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
        cout << "\n" << "Continue the program? (Y/N) ";
        cin >> stopFlag;
        
        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}
}