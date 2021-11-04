#include <cstring>
#include <iostream>

#include "utils.hpp"

void unique_elements(int *array, std::size_t length);
void remove_duplicates(int *array, std::size_t &length);
void rotate_left(int *array, std::size_t length);
void rotate_right(int *array, std::size_t length);

int main()
{
    int array[] = {1, 1, 2, 3, 3, 4};
    std::size_t length = 6;

    std::cout << "unique_elements: " << std::endl;
    unique_elements(array, length);

    remove_duplicates(array, length);
    print_array(array, length);

    rotate_left(array, length);
    print_array(array, length);

    rotate_right(array, length);
    print_array(array, length);

    return 0;
}

void unique_elements(int *array, std::size_t length)
{
    for (std::size_t i = 0; i < length; i++)
    {
        bool unique = true;
        int Current_value = array[i];

        for (std::size_t j = 0; j < length; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (Current_value == array[j])
            {
                unique = false;
            }
        }

        if (unique == true)
        {
            std::cout << "unique element: " << Current_value << std::endl;
        }
    }
}

void remove_duplicates(int *array, std::size_t &length)
{
    for (std::size_t i = 0; i < length; i++)
    {
        std::size_t duplicate_index = std::string::npos;
        int Current_value = array[i];

        for (std::size_t j = i + 1; j < length; j++)
        {
            if (Current_value == array[j])
            {
                duplicate_index = j;
                length--;
                break;
            }
        }

        if (duplicate_index == -1)
        {
            continue;
        }

        for (std::size_t j = duplicate_index; j < length; j++)
        {
            array[j] = array[j + 1];
        }

        array[length] = 0;
    }
}

void rotate_left(int *array, std::size_t length)
{
    int first_element = array[0];

    for (std::size_t i = 1; i < length; i++)
    {
        array[i - 1] = array[i];
    }

    array[length - 1] = first_element;
}

void rotate_right(int *array, std::size_t length)
{
    int Last_element = array[length - 1];

    for (std::size_t i = length - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }

    array[0] = Last_element;
}
