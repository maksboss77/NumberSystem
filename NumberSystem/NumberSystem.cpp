#include <iostream>

using namespace std;


char digit(int num)
{
    switch (num) {
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
    }
}

int integerPart(char n[256], char s[256], char *str) {
    

    int num = (int) n;
    s = (int) s;
    int rest = num % n;
    num /= s;

    if (num == 0) {
        str[0] = digit(rest);
        return 1;
    }

    int k = integerPart(n, s, str);
    str[k++] = digit(rest);

    return k;
}


int main()
{
    std::cout << "Hello World!\n";

    char num[256] = { 0 }; //число в десятичной системе счисления
    char sys[256] = { 0 }; //основание системы счисления

    char str[80] = { 0 };

    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter the base of the number system: ";
    cin >> sys;

    try {
        
        int k = integerPart(num, sys, str);
    }
    catch() {

    }

    cout << "\n" << str << "\n";

}
