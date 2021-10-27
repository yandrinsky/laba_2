#ifndef SETARRAY_H_INCLUDED
#define SETARRAY_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
class Set
{
private:
    const int Nmax = 16;
    int n; char S;
    char A[11];
public:
    Set() : Nmax(10), n(0), S('R')
    {
        A[0] = 0;
    }
    Set(char* vals) : Nmax(10), S('R')
    {
        n = 0;
        for (int i = 0; i < strlen(vals); ++i)
        {
            bool added = false;
            for(int j = 0; j < i && !added; j++)
            {
                if(A[j] == vals[i])
                {
                    added = true;
                }
            }
            if(!added) A[n++] = vals[i];
        }
        A[n] = 0;
    }

    Set AND(const Set& B)
    {
        Set E;
        for (int i = 0; A[i]; ++i) if (B.contains(A[i])) E.A[E.n++] = A[i];
        E.A[E.n] = 0;
        return E;
    }

    Set OR(const Set& B)
    {
        Set res;
        for (int i = 0; A[i]; i++)
        {
            res.A[res.n++] = A[i];
        }
        for (int i = 0; B.A[i]; i++)
        {
            if (!contains(B.A[i]))
            {
                res.A[res.n++] = B.A[i];
            }
        }
        res.A[res.n] = 0;
        return res;
    }

    bool contains(char s) const
    {
        bool b = false;
        for (int i = 0; A[i] && !b; ++i) b |= A[i] == s;
        return b;
    }

    int power() const { return n; }

    void print()
    {
        cout << '[';
        for (int i = 0; i < n; i++)
        {
            cout << A[i];
            if (i != n - 1) cout << ' ';
        }
        cout << "]\n";
    }

    Set& operator = (const Set& B)
    {
        if (this != &B)
        {
            n = B.n; S = 'R';
            for (int i = 0; B.A[i]; i++)
            {
                A[i] = B.A[i];
            }
        }
        return *this;
    }
    Set& operator &= (const Set& B)
    {
        Set C(*this);
        n = 0;
        for (int i = 0; i < C.n; ++i) {
            for (int j = 0; j < B.n; j++)
                if (C.A[i] == B.A[j]) A[n++] = C.A[i];
        }
        A[n] = 0;
        return *this;
    }
    Set operator & (const Set& B) const
    {
        Set C(*this);
        return (C &= B);
    }

    Set& operator |= (const Set& B)
    {
        Set res(*this);
        n = 0;
        for (int i = 0; i < res.n; i++)
        {
            A[n++] = res.A[i];
        }
        for (int i = 0; i < B.n; i++)
        {
            if (!res.contains(B.A[i]))
            {
                A[n++] = B.A[i];
            }
        }
        A[n] = 0;
        return *this;
    }
    Set operator | (const Set& B) const
    {
        Set C(*this);
        return (C |= B);
    }

    Set WITHOUT(const Set& B)
    {
        Set E;
        for (int i = 0; A[i]; ++i) if (!B.contains(A[i])) E.A[E.n++] = A[i];
        E.A[E.n] = 0;
        return E;
    }
};


#endif // SETARRAY_H_INCLUDED
