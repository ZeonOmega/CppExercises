#include <cmath>

#include "distance.hpp"
#include "utils.hpp"

#include "Shape.hpp"

double Shape::midpoint_distance(const Shape *other) const
{
    const auto [x_midpoint1, y_midpoint1] = this->get_midpoint();
    const auto [x_midpoint2, y_midpoint2] = other->get_midpoint();

    const auto distance = get_distance(x_midpoint1, y_midpoint1, x_midpoint2, y_midpoint2);

    return distance;
}

Circle::Circle(std::uint32_t x_midpoint_, std::uint32_t y_midpoint_, std::uint32_t radius_)
    : x_midpoint(x_midpoint_), y_midpoint(y_midpoint_), radius(radius_)
{
}

double Circle::get_area() const
{
    return pi * std::pow(radius, 2.0);
}


Coordiante Circle::get_midpoint() const
{
    return std::make_pair(x_midpoint, y_midpoint);
}

Rectangle::Rectangle(std::uint32_t x1_, std::uint32_t y1_, std::uint32_t x2_, std::uint32_t y2_)
    : x1(x1_), y1(y1_), x2(x2_), y2(y2_)
{
}

double Rectangle::get_area() const
{
    return (x1 - x2) * (y1 - y2);
}


Coordiante Rectangle::get_midpoint() const
{
    const auto x_midpoint = (x1 + x2) / 2U;
    const auto y_midpoint = (y1 + y2) / 2U;

    return std::make_pair(x_midpoint, y_midpoint);
}
