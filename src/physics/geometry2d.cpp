#include "physics/geometry2d.h"

#include <iostream>

#define CMP(x, y)                          \
    (fabsf((x) - (y)) <= __FLT_EPSILON__ * \
                             fmaxf(1.0f, fmaxf(fabsf(x), fabsf(y))))

#define CLAMP(number, minimum, maximum)                                  \
    number = (number < minimum) ? minimum : (number > maximum) ? maximum \
                                                               : number;

inline double deg2rad(double degrees)
{
    static const double pi_on_180 = 4.0 * atan(1.0) / 180.0;
    return degrees * pi_on_180;
}

// Todo: understand Slope Intercept
bool PointOnLine(const Point &point, const Line &line)
{
    float dx = (line.end.x - line.start.x);
    float dy = (line.end.y - line.start.y);
    float m = dy / dx;
    // find the Y-Intercept
    float b = line.start.y - m * line.start.x;

    //Check line equations
    // 98
    return CMP(point.y, m * point.x + b);
}

bool PointInCircle(const Point &point, const Circle &circle)
{
    Line line(point, circle.position);

    if (line.lengthSquared() < circle.radius * circle.radius)
    {
        return true;
    }

    return false;
}

bool PointInRectangle(const Point &point, const Rectangle &rectangle)
{
    Vec2 min = rectangle.position;
    Vec2 max = rectangle.position + rectangle.size;

    return min.x <= point.x && min.y <= point.y &&
           point.x <= max.y && point.y <= max.y;
}

// Todo: Not implemented
// bool PointInOrientedRectangle(const Point &point, const OrientedRectangle &rectangle)
// {
//     // Vec2 rotVector = point - rectangle.position;
//     // float theta = -deg2rad(rectangle.rotation);

//     // float xRotation2x2[] =
//     // {
//     //     cosf(theta), sinf(theta),
//     //     -sinf(theta), cosf(theta)
//     // };

//     return false;
// }

bool LineOnCircle(const Line &line, const Circle &circle)
{
    Vec2 ab = line.end - line.start;
    float t = (circle.position - line.start).dot(ab) / ab.dot(ab);

    if (t < 0.0f || t > 1.0f)
    {
        return false;
    }

    Point closestPoint = line.start + ab * t;

    Line circleToClosest(circle.position, closestPoint);

    return circleToClosest.lengthSquared() < circle.radius * circle.radius;
}

bool LineOnRectangle(const Line &line, const Rectangle &rectangle)
{
    // The simple part
    if (PointInRectangle(line.start, rectangle) ||
        PointInRectangle(line.end, rectangle))
    {
        return true;
    }

    // Lest raycast the line to the rectangle
    Vec2 norm = (line.end - line.start).normalized();
    norm.x = (norm.x != 0) ? 1.0f / norm.x : 0;
    norm.y = (norm.y != 0) ? 1.0f / norm.y : 0;
    Vec2 min = (rectangle.position - line.start) * norm;
    Vec2 max = (rectangle.position + rectangle.size - line.start) * norm;

    float tmin = fmaxf(
        fminf(min.x, max.x),
        fminf(min.y, max.y));

    float tmax = fminf(
        fmaxf(min.x, max.x),
        fmaxf(min.y, max.y));

    if (tmax < 0 || tmin > tmax)
    {
        return false;
    }

    float t = (tmin < 0.0f) ? tmax : tmin;

    return t > 0.0f && (t * t) < line.lengthSquared();
}

bool CircleOnCircle(const Circle &circle1, const Circle &circle2)
{
    Line line(circle1.position, circle2.position);

    float radiiSum = circle1.radius + circle2.radius;

    return line.lengthSquared() <= radiiSum * radiiSum;
}

bool CircleOnRectangle(const Circle &circle, const Rectangle &rectangle)
{
    Vec2 min = rectangle.position;
    Vec2 max = rectangle.position + rectangle.size;

    Point closesPoint = circle.position;

    CLAMP(closesPoint.x, min.x, max.x);
    CLAMP(closesPoint.y, min.y, max.y);

    Line line(circle.position, closesPoint);

    return line.lengthSquared() <= circle.radius * circle.radius;
}

bool RectangleOnRectangle(const Rectangle &rectangle1, const Rectangle &rectangle2)
{
    Vec2 aMin = rectangle1.position;
    Vec2 aMax = rectangle1.position + rectangle1.size;
    
    Vec2 bMin = rectangle2.position;
    Vec2 bMax = rectangle2.position + rectangle2.size;

    bool overX = ((bMin.x <= aMax.x) && (aMin.x <= bMax.x));
    bool overY = ((bMin.y <= aMax.y) && (aMin.y <= bMax.y));

    return overX && overY;
}

Circle ContainingCircle(Point *points, int arrayCount)
{
    Point center;
    for (int i = 0; i < arrayCount; i++)
    {
        center += points[i];
    }

    center = center * (1.0f / (float) arrayCount);

    Circle result(center, 1.0f);

    result.radius = (center - points[0]).lengthSquared();

    for (int i = 1; i < arrayCount; i++)
    {
        float distance = (center - points[i]).lengthSquared();

        if (distance > result.radius)
        {
            result.radius = distance;
        }
    }
    
    result.radius = sqrtf(result.radius);

    return result;
}

Rectangle ContainingRectangle(Point *points, int arrayCount)
{
    Vec2 min = points[0];
    Vec2 max = points[0];

    for (int i = 0; i < arrayCount; i++)
    {
        min.x = points[i].x < min.x ? points[i].x : min.x;
        min.y = points[i].y < min.y ? points[i].y : min.y;
        max.x = points[i].x > max.x ? points[i].x : max.x;
        max.y = points[i].y > max.y ? points[i].y : max.y;
    }
    
    return Rectangle(min, max - min);
}
