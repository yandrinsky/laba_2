#include <bits/stdc++.h>
#include "setbitsarray.h"

using namespace std;


int main()
{
    char* a = (char*)calloc(11, sizeof(char)), * b = (char*)calloc(11, sizeof(char)), * c = (char*)calloc(11, sizeof(char)), * d = (char*)calloc(11, sizeof(char));

    cout << "A = ";  cin >> a;
    cout << "B = ";  cin >> b;
    cout << "C = ";  cin >> c;
    cout << "D = ";  cin >> d;
    Set A(a);
    Set B(b);
    Set C(c);
    Set D(d);
    Set E = (A | B).WITHOUT(C | D);
//    calc(A, B, C, D);
//    Set E = (A | D).AND(B & C);
    cout << "\nA = "; A.print();
    cout << "B = "; B.print();
    cout << "C = "; C.print();
    cout << "D = "; D.print();
    cout << "\nE = "; E.print();
    return 0;
}
