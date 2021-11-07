# Exercise

Implement the following functions:

```cpp
std::string to_upper_case(std::string_view text);

std::string to_lower_case(std::string_view text);

std::size_t string_length(std::string_view text);

const char *char_search(std::string_view text, char character);

bool string_equal(std::string_view string1, std::string_view string2);
```

## Main Function

```cpp
int main()
{
    auto input_text = std::string{};
    auto compare_text1 = std::string{"jan"};
    auto compare_text2 = std::string{"ja"};

    std::cout << "Please enter any result: ";
    std::cin >> input_text;

    std::cout << "to_upper_case: " << to_upper_case(input_text) << std::endl;
    std::cout << "to_lower_case: " << to_lower_case(input_text) << std::endl;
    std::cout << "string_length: " << string_length(input_text) << std::endl;
    std::cout << "char_search: " << char_search(input_text, 'a') << std::endl;
    std::cout << std::boolalpha;
    std::cout << "equal(jan, jan): " << string_equal(input_text, compare_text1) << std::endl;
    std::cout << "equal(jan, ja): " << string_equal(input_text, compare_text2) << std::endl;

    return 0;
}
```