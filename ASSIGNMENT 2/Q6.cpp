#include <iostream>
using namespace std;
void showTriplets(int r[], int c[], int v[], int n)
{
    cout << "Row Col Val" << endl;
    for (int i = 0; i < n; i++)
        cout << r[i] << "   " << c[i] << "   " << v[i] << endl;
}
void findTranspose(int r[], int c[], int v[], int n, int tr[], int tc[], int tv[])
{
    for (int i = 0; i < n; i++)
    {
        tr[i] = c[i];
        tc[i] = r[i];
        tv[i] = v[i];
    }
}
int addTriplets(int r1[], int c1[], int v1[], int n1,
                int r2[], int c2[], int v2[], int n2,
                int r3[], int c3[], int v3[])
{
    int i = 0, j = 0, t = 0;
    while (i < n1 && j < n2)
    {
        if (r1[i] < r2[j] || (r1[i] == r2[j] && c1[i] < c2[j]))
        {
            r3[t] = r1[i];
            c3[t] = c1[i];
            v3[t] = v1[i];
            i++;
            t++;
        }
        else if (r2[j] < r1[i] || (r2[j] == r1[i] && c2[j] < c1[i]))
        {
            r3[t] = r2[j];
            c3[t] = c2[j];
            v3[t] = v2[j];
            j++;
            t++;
        }
        else
        {
            r3[t] = r1[i];
            c3[t] = c1[i];
            v3[t] = v1[i] + v2[j];
            i++;
            j++;
            t++;
        }
    }
    while (i < n1)
    {
        r3[t] = r1[i];
        c3[t] = c1[i];
        v3[t] = v1[i];
        i++;
        t++;
    }
    while (j < n2)
    {
        r3[t] = r2[j];
        c3[t] = c2[j];
        v3[t] = v2[j];
        j++;
        t++;
    }
    return t;
}

int multiplyTriplets(int r1[], int c1[], int v1[], int n1,
                     int r2[], int c2[], int v2[], int n2,
                     int r3[], int c3[], int v3[])
{
    int t = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (c1[i] == r2[j])
            {
                r3[t] = r1[i];
                c3[t] = c2[j];
                v3[t] = v1[i] * v2[j];
                t++;
            }
        }
    }
    return t;
}
int main()
{
    int rA[] = {0, 1, 2};
    int cA[] = {1, 0, 2};
    int valA[] = {2, 3, 4};
    int nA = 3;
    int rB[] = {0, 1, 2};
    int cB[] = {0, 1, 2};
    int valB[] = {5, 6, 7};
    int nB = 3;
    cout << "Matrix A triplets:" << endl;
    showTriplets(rA, cA, valA, nA);
    cout << "Matrix B triplets:" << endl;
    showTriplets(rB, cB, valB, nB);
    int trA[10], tcA[10], tvA[10];
    findTranspose(rA, cA, valA, nA, trA, tcA, tvA);
    cout << "Transpose of A:" << endl;
    showTriplets(trA, tcA, tvA, nA);
    int rC[20], cC[20], valC[20];
    int sC = addTriplets(rA, cA, valA, nA, rB, cB, valB, nB, rC, cC, valC);
    cout << "Addition:" << endl;
    showTriplets(rC, cC, valC, sC);
    int rM[20], cM[20], valM[20];
    int sM = multiplyTriplets(rA, cA, valA, nA, rB, cB, valB, nB, rM, cM, valM);
    cout << "Multiplication:" << endl;
    showTriplets(rM, cM, valM, sM);
    return 0;
}
