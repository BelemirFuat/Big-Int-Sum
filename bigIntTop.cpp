#include <iostream>

using namespace std;

int charToInt(char);
char intToChar(int);
int getLen(char *);

int main()
{
    char int1[100];
    char int2[100];
    cout << "Int 1 giriniz: ";
    cin >> int1;
    cout << "Int 2 giriniz: ";
    cin >> int2;
    int len1 = getLen(int1);
    int len2 = getLen(int2);

    int max, min;

    if (len1 > len2)
    {
        max = len1;
        min = len2;
    }
    else
    {
        max = len2;
        min = len1;
    }
    cout << "Int1 : " << int1 << endl;
    cout << "Int2 : " << int2 << endl;
    cout << "Len1 : " << len1 << endl;
    cout << "Len2 : " << len2 << endl;
    cout << "Max : " << max << endl;
    cout << "Min : " << min << endl;
    int topla, elde = 0;
    char *toplam = new char[max + 1]; // Dynamic memory allocation
    for (int i = 1; i <= max; i++)
    {
        int gec1, gec2;
        if (len1 - i >= 0)
            gec1 = charToInt(int1[len1 - i]);
        else
            gec1 = 0;
        if (len2 - i >= 0)
            gec2 = charToInt(int2[len2 - i]);
        else
            gec2 = 0;
        int gec3 = (gec1 + gec2 + elde);
        cout << "i : " << i << endl;
        cout << "Gec 1 : " << gec1 << endl;
        cout << "Gec 2 : " << gec2 << endl;
        cout << "Gec 3 : " << gec3 << endl;
        if (gec3 > 9)
        {
            topla = gec3 % 10;
            elde = gec3 / 10;
        }
        else
        {
            topla = gec3;
            elde = 0;
        }
        cout << "Topla :" << topla << endl;
        cout << "Elde : " << elde << endl;
        toplam[max-i] = intToChar(topla);
        cout << endl;
    }
    toplam[max] = '\0'; // Add null character at the end of the string
    cout << "toplam : " << toplam << endl;

    delete[] toplam; // Deallocate the dynamically allocated memory
}

int charToInt(char harf)
{
    if ((harf >= '0') && (harf <= '9'))
        return harf - '0';
    return 0;
}

char intToChar(int sayi)
{
    if ((sayi < 10) && (sayi >= 0))
    {
        return '0' + sayi;
    }
    return 0;
}

int getLen(char *int1)
{
    int length = 0;
    while (int1[length] != '\0')
    {
        length++;
    }
    return length;
}
