#pragma once
#include <iostream>

#define NUMBER_SYSTEM_BASE_CODE -1;
#define NUMBER_SYSTEM_BASE_TEXT "The base of the number system is less than 2!";

#define NUMBER_NOT_NULL_CODE 101;
#define NUMBER_NOT_NULL_TEXT "The number must not be zero!";


using namespace std;

class NumberError {
    public:
        virtual const char* getMessage() = 0;
        virtual int getCode() = 0;

};


class NumberSystemBase:NumberError {
    public:
        virtual const char* getMessage() { return NUMBER_SYSTEM_BASE_TEXT; };
        virtual int getCode() { return NUMBER_SYSTEM_BASE_CODE; };

};

class NumberNotNull:NumberError {
public:
    virtual const char* getMessage() { return NUMBER_NOT_NULL_TEXT; };
    virtual int getCode() { return NUMBER_NOT_NULL_CODE; };
};


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

int integerPart(int a, int p, char* s) {
    
    if (p < 2) {
        throw new NumberSystemBase();
    }

    int num = (int)a;
    int rest = num % p;
    num /= p;
    if (num == 0)
    {
        s[0] = digit(rest); return 1;
    }
    int k = integerPart(num, p, s);
    s[k++] = digit(rest);
    return k;
}

// Получение дробной части числа
void doublePart(double a, int p, char* s)
{
    int iter = 0;
    int k = 0;
    double a1 = a;
    do {
        a1 = a1 * p;
        int num = (int)(a1);
        s[k++] = digit(num);
        a1 -= (int)a1;
        iter++;
    } while (a1 > 0.00000001 && iter < 10);
    s[k] = '\0';
}


int main()
{
    double a;
    char s[80] = { 0 };
    int p;

    try
    {
        cout << "Enter a number: ";
        cin >> a;
        if (a == 0)
            throw new NumberNotNull;

        cout << "Enter the base of the number system: ";
        cin >> p;

        try {
            int k = integerPart(a, p, s);
            s[k++] = ',';

            int intA;
            intA = (int)a;
            doublePart(a - intA, p, &s[k]);

            cout << s;
            delete[] s;
            
        }
        catch (NumberSystemBase * ex) {
            cout << ex->getMessage() << " Code: " << ex->getCode();
            delete[] s;
        }

    }
    catch (NumberNotNull * ex)
    {
        cout << ex->getMessage() << " Code: " << ex->getCode();
        delete[] s;
    }

    
}
