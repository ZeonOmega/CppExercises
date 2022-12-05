#include <cstddef>

#include "lib.h"

/** START PREV FUNCS **/

bool is_upper_case(const char character)
{
    if ((character >= 'A') && (character <= 'Z'))
    {
        return true;
    }

    return false;
}

bool is_lower_case(const char character)
{
    if ((character >= 'a') && (character <= 'z'))
    {
        return true;
    }

    return false;
}

bool is_numeric(const char character)
{
    if ((character >= '0') && (character <= '9'))
    {
        return true;
    }

    return false;
}

bool is_alpha(const char character)
{
    if (is_upper_case(character) || is_lower_case(character))
    {
        return true;
    }

    return false;
}

bool is_alpha_numeric(const char character)
{
    return is_numeric(character) || is_alpha(character);
}

char to_upper_case(const char character)
{
    if (is_lower_case(character))
    {
        return character - 32;
    }

    return character;
}

char to_upper_case_(const char character)
{
    if (is_lower_case(character))
    {
        return character - 32;
    }

    return character;
}

char to_lower_case(const char character)
{
    if (is_upper_case(character))
    {
        return character + 32;
    }

    return character;
}

char to_lower_case_(const char character)
{
    if (is_upper_case(character))
    {
        return character + 32;
    }

    return character;
}

/** END PREV FUNCS **/

char *to_upper_case(char *text)
{
}

char *to_lower_case(char *text)
{
}

std::size_t string_length(char *text)
{
}

char *char_search(char *text, const char character)
{
}

bool string_equal(const char *string1, const char *string2)
{
}
