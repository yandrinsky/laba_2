#ifndef SETBITSARRAY_H_INCLUDED
#define SETBITSARRAY_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
class Set
{
private:
    int n;
    char arr[17];
    int bits[16];

public:
    Set()
    {
        n = 0;
        arr[0] = '\0';
        for (int i = 0; i < 10; i++) bits[i] = 0;
    }

    Set(char* pArr)
    {
        n = strlen(pArr);
        for (int i = 0; i < n; i++)
        {
            arr[i] = pArr[i];
        }
        arr[n] = '\0';

        for (int i = 0; i < 10; i++) bits[i] = 0;
        array_to_bits(*this);
        bits_to_array(*this);
    }

    Set(const Set& other)
    {
        n = other.n;
        for (int i = 0; i < 10; i++)
        {
            arr[i] = other.arr[i];
            if (i != 16) bits[i] = other.bits[i];
        }
    }

    void array_to_bits(Set& thisObj)
    {
        int a;

        for (int i = 0; thisObj.arr[i]; i++)
        {
           a = thisObj.arr[i] <= '9' ? thisObj.arr[i] - '0' : thisObj.arr[i] - 'A' + 10;
           thisObj.bits[a] = 1;
        }
    }

    void bits_to_array(Set& thisObj)
    {
        for (int i = 0, k = 0; i < 10; i++)
        {
            thisObj.arr[k + 1] = '\0';
            if (thisObj.bits[i])
            {
                thisObj.arr[k++] = i <= 9 ? i + '0' : i + 'A' - 10;
            }
        }
        thisObj.n = strlen(thisObj.arr);
    }

    void print()
    {
        cout << '[';
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if (i != n - 1) cout << ' ';
        }
        cout << "]\n";
    }

    Set& operator |= (const Set& B)
    {
        for (int i = 0; i < 16; i++)
        {
            bits[i] = bits[i] || B.bits[i];
        }
        bits_to_array(*this);

        return *this;
    }

    Set operator | (const Set& B) const
    {
        Set A(*this);


        return (A |= B);
    };

    Set WITHOUT(const Set& B)
    {
        Set res;

        for (int i = 0; i < 10; i++)
        {
            res.bits[i] = bits[i] && !B.bits[i];
        }
        bits_to_array(res);

        return res;
    };

    Set operator = (const Set& other)
    {
        n = other.n;
        for (int i = 0; i < 17; i++)
        {
            arr[i] = other.arr[i];
            if (i != 16) bits[i] = other.bits[i];
        }

        return *this;
    }
};


#endif // SETBITSARRAY_H_INCLUDED
