#pragma once

#include <cmath>
#include <type_traits>
#include <utility>

template <typename T>
constexpr T PI = T(3.14159265358979323846);

template <typename T, typename U>
[[nodiscard]] constexpr U ms_to_s(const T ms)
{
    static_assert(std::conjunction_v<std::is_integral<T>, std::is_floating_point<U>>, "Invalid types.");

    return ms / static_cast<U>(1000.0);
}

template <typename T>
[[nodiscard]] constexpr T deg_to_rad(const T deg)
{
    static_assert(std::is_floating_point_v<T>, "Must be floating point type.");

    return deg * (PI<float> / static_cast<T>(180.0));
}

template <typename T>
[[nodiscard]] constexpr T kph_to_mps(const T kph)
{
    static_assert(std::is_floating_point_v<T>, "Must be floating point type.");

    return kph / static_cast<T>(3.6);
}

template <typename T>
[[nodiscard]] constexpr T mps_to_kph(const T mps)
{
    static_assert(std::is_floating_point_v<T>, "Must be floating point type.");

    return mps * static_cast<T>(3.6);
}

template <typename T>
[[nodiscard]] constexpr std::pair<T, T> rotate_point(const T theta, const T cx, const T cy, T x, T y)
{
    static_assert(std::is_floating_point_v<T>, "Must be floating point type.");

    x -= cx;
    y -= cy;

    auto x_s = x * std::cos(theta) - y * std::sin(theta);
    auto y_s = x * std::sin(theta) + y * std::cos(theta);

    x_s += cx;
    y_s += cy;

    return std::make_pair(x_s, y_s);
}