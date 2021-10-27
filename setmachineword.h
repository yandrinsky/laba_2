#ifndef SETMACHINEWORD_H_INCLUDED
#define SETMACHINEWORD_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
class Set
{
private:
    int n;
    char arr[17];
    short word;
public:
    Set()
    {
        n = 0; arr[0] = '\0'; word = 0;
    }

    Set(char* pArr)
    {
        n = strlen(pArr);
        for (int i = 0; i < n; i++)
        {
            arr[i] = pArr[i];
        }
        arr[n] = '\0';

        word = 0;
        array_to_word(*this);
        word_to_array(*this);
    }

    Set(const Set& other)
    {
        n = other.n;
        for (int i = 0; i < 17; i++)
        {
            arr[i] = other.arr[i];
        }
        word = other.word;
    }

    void array_to_word(Set& thisObj)
    {
        int a;

        for (int i = 0; thisObj.arr[i]; i++)
        {
            a = thisObj.arr[i] <= '9' ? thisObj.arr[i] - '0' : thisObj.arr[i] - 'A' + 10;
            thisObj.word |= (1 << a);
        }
    }

    void word_to_array(Set& thisObj)
    {
        for (int i = 0, k = 0; i < 16; i++)
        {
            thisObj.arr[k + 1] = '\0';
            if ((thisObj.word >> i) & 0x1)
            {
                thisObj.arr[k++] = i <= 9 ? i + '0' : i + 'A' - 10;
            }
            thisObj.n = strlen(thisObj.arr);
        }
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
        word |= B.word;
        word_to_array(*this);

        return *this;
    }

    Set operator | (const Set& B)
    {
        Set A(*this);
        return (A |= B);
    }

    Set WITHOUT(const Set& B)
    {
        Set res;

        res.word = word & ~B.word;
        word_to_array(res);
        return res;
    }

    Set operator = (const Set& other)
    {
        n = other.n;
        for (int i = 0; i < 17; i++)
        {
            arr[i] = other.arr[i];
        }
        word = other.word;

        return *this;
    }
};


#endif // SETMACHINEWORD_H_INCLUDED
