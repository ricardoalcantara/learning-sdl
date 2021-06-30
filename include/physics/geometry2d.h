#ifndef GEOMETRY2D_H
#define GEOMETRY2D_H

#include "physics/vec2.h"

#include "math.h"

typedef Vec2 Point;

struct Line
{
    Point start;
    Point end;

    Line() {}
    Line(const Point &s, const Point &e) : start(s), end(e) {}

    float length() const
    {
        return (end - start).length();
    }

    float lengthSquared() const
    {
        return (end - start).lengthSquared();
    }
};

struct Circle
{
    Point position;
    float radius;

    Circle() : radius(1) {}
    Circle(const Point &p, float r) : position(p), radius(r) {}
};

struct Rectangle
{
    // Min
    Point position;
    // Max
    Vec2 size;

    Rectangle() : size(1, 1){};
    Rectangle(const Point &p, const Vec2 &s) : position(p), size(s){};
};

// Todo: Do we really need it?
struct OrientedRectangle
{
    // Min
    Point position;
    // Max
    Vec2 halfExtents;
    float rotation;

    OrientedRectangle() : halfExtents(1, 1){};
    OrientedRectangle(const Point &p, const Vec2 &ext)
        : position(p), halfExtents(ext){};
    OrientedRectangle(const Point &p, const Vec2 &ext, float rot)
        : position(p), halfExtents(ext), rotation(rot){};
};

bool PointOnLine(const Point &point, const Line &line);
bool PointInCircle(const Point &point, const Circle &circle);
bool PointInRectangle(const Point &point, const Rectangle &rectangle);
// bool PointInOrientedRectangle(const Point& point, const OrientedRectangle& rectangle);

bool LineOnCircle(const Line &line, const Circle &circle);
bool LineOnRectangle(const Line &line, const Rectangle &rectangle);
// bool LineOrientedRectangle(const Point& point, const OrientedRectangle& rectangle);

bool CircleOnCircle(const Circle &circle1, const Circle &circle2);
bool CircleOnRectangle(const Circle &circle, const Rectangle &rectangle);

bool RectangleOnRectangle(const Rectangle &rectangle1, const Rectangle &rectangle2);

Circle ContainingCircle(Point *points, int arrayCount);
Rectangle ContainingRectangle(Point *points, int arrayCount);

#endif
