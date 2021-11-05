#ifndef UTILS_H
#define UTILS_H

#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>
#include <vector>

constexpr double PI = 3.14159265358979311600;

template <typename T>
void print_array(const T *array, const std::size_t length)
{
    for (std::size_t i = 0; i < length - 1; i++)
    {
        std::cout << array[i] << ", ";
    }

    std::cout << array[length - 1] << std::endl;
}

template <typename T, std::size_t S>
void print_array(const std::array<T, S> array)
{
    for (std::size_t i = 0; i < array.size() - 1; i++)
    {
        std::cout << array[i] << ", ";
    }

    std::cout << array[array.size() - 1] << std::endl;
}

template <typename T>
void print_vector(const std::vector<T> vector)
{
    for (std::size_t i = 0; i < vector.size() - 1; i++)
    {
        std::cout << vector[i] << ", ";
    }

    std::cout << vector[vector.size() - 1] << std::endl;
}

void print_vector(const std::vector<std::pair<std::string, std::size_t>> vector)
{
    for (std::size_t i = 0; i < vector.size() - 1; i++)
    {
        std::cout << vector[i].first << ": " << vector[i].second << ", ";
    }

    std::cout << vector[vector.size() - 1].first << ": " << vector[vector.size() - 1].second
              << std::endl;
}

template <typename T, typename U>
void print_map(const std::map<T, U> Map)
{
    for (const auto &[Key, value] : Map)
    {
        std::cout << Key << ": " << value << std::endl;
    }
}

template <typename T, typename U>
void print_map(const std::unordered_map<T, U> Map)
{
    for (const auto &[Key, value] : Map)
    {
        std::cout << Key << ": " << value << std::endl;
    }
}

std::string readFile(std::string_view file_path)
{
    auto str = std::string{};
    auto text = std::string{};

    auto iffile = std::ifstream{};
    iffile.open(file_path.data());

    if (iffile.is_open())
    {
        while (std::getline(iffile, str))
        {
            text += str + '\n';
        }
    }

    iffile.close();

    return text;
}

#endif /* UTILS_H */
