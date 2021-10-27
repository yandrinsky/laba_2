#ifndef SETLIST_H_INCLUDED
#define SETLIST_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
class Set
{
    struct List
    {
        char element;
        List* next;
        List(char c, List* n = nullptr) : element(c), next(n) {}
        ~List() { delete next; }
    };
private:
    const int Nmax = 16;
    int n; char S;
    List* mList;
public:
    List* make_set_from_array(char* arr)
    {
        List* prev = nullptr;
        for (int i = strlen(arr) - 1; i >= 0; i--)
        {
            bool added = false;
            for(int j = strlen(arr)-1; j > i && !added; j--)
            {
                if(arr[i] == arr[j])
                {
                    added = true;
                }
            }
            if(!added) prev = new List(arr[i], prev);
        }
        return prev;
    }
    void insert_to_set(List** s, char e)
    {
        if (!*s)
        {
            *s = new List(e, nullptr);
            return;
        }
        List* last = *s;
        while (last && last->next) last = last->next;
        List* new_el = new List(e, nullptr);
        if (last) last->next = new_el;
    }
    Set() : Nmax(16), n(0), S('R')
    {
        mList = nullptr;
    }
    Set(char* vals) : Nmax(16), n(strlen(vals)), S('R')
    {
        mList = make_set_from_array(vals);
    }
    Set(const Set& sl) : Nmax(16), n(sl.n), S(sl.S)
    {
        mList = nullptr;
        for (List* ptr = sl.mList; ptr; ptr = ptr->next)
        {
            insert_to_set(&mList, ptr->element);
        }
    }

    bool contains(char s) const
    {
        bool b(false);
        for (List* ptr = mList; ptr && !b; ptr = ptr->next) b |= ptr->element == s;
        return b;
    }

    int power() const { return n; }

    void print() const
    {
        cout << '[';
        for (List* ptr = mList; ptr; ptr = ptr->next)
        {
            cout << ptr->element;
            if (ptr && ptr->next) cout << ' ';
        }
        cout << "]\n";
    }
    Set& operator = (const Set& B)
    {
        if (this != &B)
        {
            n = B.n;
            S = 'R';
            mList = nullptr;
            for (List* ptr = B.mList; ptr; ptr = ptr->next)
            {
                insert_to_set(&mList, ptr->element);
            }
        }
        return *this;
    }
    Set& operator &= (const Set& B)
    {
        Set C(*this);
        for (List* ptrC = C.mList; ptrC; ptrC = ptrC->next) {
            for (List* ptrB = B.mList; ptrB; ptrB = ptrB->next)
                if (ptrC->element == ptrB->element) insert_to_set(&mList, ptrC->element);
        }
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
        mList = nullptr;
        for (List* ptr = res.mList; ptr; ptr = ptr->next)
        {
            insert_to_set(&mList, ptr->element);
        }
        for (List* ptr = B.mList; ptr; ptr = ptr->next)
        {
            if (!res.contains(ptr->element))
            {
                insert_to_set(&mList, ptr->element);
            }
        }
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
        for (List* ptr = mList; ptr; ptr = ptr->next) if (!B.contains(ptr->element)) insert_to_set(&E.mList, ptr->element);
        return E;
    }
};


#endif // SETLIST_H_INCLUDED
