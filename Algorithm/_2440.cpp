#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int N;

    cin >> N;

    for (int i = N-1; i >=0; i--) {
        for (int j = 0; j < N; j++) {
            if (i >= j)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
}