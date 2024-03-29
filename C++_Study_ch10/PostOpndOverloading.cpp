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
    // 멤버함수의 형태로 오버로딩
    Point& operator++()   // 전위증가
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    const Point operator++(int)   // 후위증가 with 반환형에서의 const 선언과 const 객체
    {
        const Point retobj(xpos, ypos);    // const Point retobj(*this);
        xpos += 1;
        ypos += 1;
        return retobj;
    }

    friend Point& operator--(Point& ref);
    friend const Point operator--(Point& ref, int);
};

// 전역함수의 형태로 오버로딩
Point& operator--(Point& ref)    // 전위감소
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

const Point operator--(Point& ref, int)   // 후위감소 -> 매개변수에 int를 추가함으로써 전위감소와 차이를 준다. 
{
    const Point retobj(ref);    // const 객체
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