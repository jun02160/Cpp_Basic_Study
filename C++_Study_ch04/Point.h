#pragma once
#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
    int x;
    int y;

public:
    bool InitMembers(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
    void ShowPointInfo() const;

    // 생성자 추가
    Point(const int& xpos, const int& ypos);
};
#endif