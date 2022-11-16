#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) :xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
    // ����Լ��� ���·� �����ε�
    Point& operator++()   // ��������
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    const Point operator++(int)   // �������� with ��ȯ�������� const ����� const ��ü
    {
        const Point retobj(xpos, ypos);    // const Point retobj(*this);
        xpos += 1;
        ypos += 1;
        return retobj;
    }

    friend Point& operator--(Point& ref);
    friend const Point operator--(Point& ref, int);
};

// �����Լ��� ���·� �����ε�
Point& operator--(Point& ref)    // ��������
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

const Point operator--(Point& ref, int)   // �������� -> �Ű������� int�� �߰������ν� �������ҿ� ���̸� �ش�. 
{
    const Point retobj(ref);    // const ��ü
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retobj;
}


int main()
{
    Point pos(3, 5);
    Point cpy;
    cpy = pos--;
    cpy.ShowPosition();
    pos.ShowPosition();

    cpy = pos++;
    cpy.ShowPosition();
    pos.ShowPosition();
    return 0;
}