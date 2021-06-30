#ifndef VEC2_H
#define VEC2_H

#include "math.h"

struct Vec2
{
    float x, y;

    Vec2() : x(0), y(0) {}
    Vec2(int x, int y) : x(x), y(y)
    {
    }

    float length()
    {
        return sqrt(lengthSquared());
    }

    float lengthSquared()
    {
        return (x * x) + (y * y);
    }

    float dot(const Vec2 &b)
    {
        return (x * b.x) + (x * b.y);
    }

    // Vec2 &cross(const Vec2 &b)
    // {
    //     Vec2 result;
    //     result.x = x * b.y - y * b.x;
    //     result.y = x * b.y - y * b.x;

    //     return result;
    // }

    Vec2 normalized()
    {
        return *this / length();
    }

    Vec2 &operator+=(const Vec2 &b)
    {
        x = x + b.x;
        y = y + b.y;
        return *this;
    }

    Vec2 operator+(const Vec2 &b) const
    {
        return Vec2(b.x + x, b.y + y);
    }

    Vec2 operator-(const Vec2 &b) const
    {
        return Vec2(b.x - x, b.y - y);
    }

    Vec2 operator*(const Vec2 &b) const
    {
        return Vec2(b.x * x, b.y * y);
    }

    Vec2 operator*(const float b) const
    {
        return Vec2(b * x, b * y);
    }

    Vec2 operator/(const Vec2 &b) const
    {
        return Vec2(b.x / x, b.y / y);
    }

    Vec2 operator/(const float b) const
    {
        return Vec2(b / x, b / y);
    }
};

#endif
