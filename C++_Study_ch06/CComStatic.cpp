#include <iostream>
using namespace std;

void Counter()
{
    static int cnt;    // static ������ ���������� ���������� ���� ���õ��� ������ �⺻ �ʱ�ȭ ���� 0���� �����ȴ�. 
    cnt++;
    cout << "Current cnt : " << cnt << endl;
}

int main()
{
    for (int i = 0; i < 10; i++)
        Counter();
    return 0;
}