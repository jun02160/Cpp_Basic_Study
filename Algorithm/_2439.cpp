#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = N-1; j >= 0; j--) {
            if (i >= j)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
}