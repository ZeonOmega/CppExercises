#pragma once

#include <cstdint>
#include <string_view>
#include <vector>

using uchar = unsigned char;
using GrayscaleMatrix = std::vector<std::vector<uchar>>;

class Image
{
public:
    Image() = delete;
    Image(const std::uint32_t width, const std::uint32_t height);
    ~Image() = default;

    std::uint32_t get_width() const;
    std::uint32_t get_height() const;

    void save_image(std::string_view file_name) const;

    void clear_image();
    void set_pixel(const std::uint32_t x, const std::uint32_t y, const uchar value);
    void resize_image(const std::uint32_t new_width, const std::uint32_t new_height);
    void fill_image(const uchar value);
    void draw_line(const std::uint32_t x1,
                   const std::uint32_t y1,
                   const std::uint32_t x2,
                   const std::uint32_t y2,
                   const uchar value);

    void draw_rectangle(const std::uint32_t x1,
                        const std::uint32_t y1,
                        const std::uint32_t x2,
                        const std::uint32_t y2,
                        const uchar value);

    void draw_circle(const std::uint32_t mid_point_x,
                     const std::uint32_t mid_point_y,
                     const std::uint32_t radius,
                     const uchar value);

private:
    std::uint32_t m_width;
    std::uint32_t m_height;
    GrayscaleMatrix m_matrix;
};
