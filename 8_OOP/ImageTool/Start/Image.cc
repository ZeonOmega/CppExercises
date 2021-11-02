﻿#include <cstdlib>
#include <cstring>
#include <iostream>

#include "Image.h"

Image::Image(const std::uint32_t width, const std::uint32_t height)
    : m_width(width), m_height(height),
      m_matrix(GrayscaleMatrix(m_width, std::vector<uchar>(m_height, 0)))
{
    std::cout << "Created image object with shape=(" << m_width << "," << m_height << ")!"
              << std::endl;
    std::cout << "Matrix size: (" << m_matrix.size() << "," << m_matrix[0].size() << ")"
              << std::endl;
}

std::uint32_t Image::get_width() const
{
    return m_width;
}

std::uint32_t Image::get_height() const
{
    return m_height;
}

void Image::clear_image()
{
    m_matrix.clear();
    m_height = 0;
    m_width = 0;
}

void Image::set_pixel(const std::uint32_t x, const std::uint32_t y, const uchar value)
{
    m_matrix[x][y] = value;
}

void Image::resize_image(const std::uint32_t new_width, const std::uint32_t new_height)
{
    if (new_width != m_width)
    {
        m_matrix.resize(new_width);
        m_width = new_width;
    }

    if (new_height != m_height)
    {
        for (auto &col : m_matrix)
        {
            col.resize(new_height);
        }

        m_height = new_height;
    }
}

void Image::fill_image(const uchar value)
{
    for (auto &col : m_matrix)
    {
        std::fill(col.begin(), col.end(), value);
    }
}

void Image::draw_line(const std::uint32_t x1,
                      const std::uint32_t y1,
                      const std::uint32_t x2,
                      const std::uint32_t y2,
                      const uchar value)
{
    int length = 0;

    if ((x1 < m_width) && (x2 < m_width) && (y1 < m_height) && (y2 < m_height) &&
        ((x1 == x2) || (y1 == y2)))
    {
        if (x1 == x2)
        {
            if (y1 < y2)
            {
                length = y2 - y1;

                for (int i = 0; i != length; ++i)
                {
                    set_pixel(x1, y1 + i, value);
                }
            }
            else
            {
                length = y1 - y2;

                for (int i = 0; i != length; ++i)
                {
                    set_pixel(x1, y2 + i, value);
                }
            }
        }
        else if (y1 == y2)
        {
            if (x1 < x2)
            {
                length = x2 - x1;

                for (int i = 0; i != length; ++i)
                {
                    set_pixel(x1 + i, y1, value);
                }
            }
            else
            {
                length = x1 - x2;

                for (int i = 0; i != length; ++i)
                {
                    set_pixel(x2 + i, y1, value);
                }
            }
        }
    }
    else
    {
        std::cout << "Line Error" << std::endl;
        std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << std::endl;
    }
}

void Image::save_image(std::string_view file_name) const
{
    FILE *f = nullptr;

    std::uint32_t num_bytes = 3 * m_width * m_height;
    uchar *img = new uchar[num_bytes]{};

    int filesize = 54 + 3 * m_width * m_height;

    for (std::uint32_t x = 0; x < m_width; ++x)
    {
        for (std::uint32_t y = 0; y < m_height; y++)
        {
            img[(x + y * m_width) * 3 + 2] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 1] = m_matrix[x][y] % 256;
            img[(x + y * m_width) * 3 + 0] = m_matrix[x][y] % 256;
        }
    }

    uchar bmpfileheader[14]{'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    uchar bmpinfoheader[40]{40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    uchar bmppad[3]{0, 0, 0};

    bmpfileheader[2] = static_cast<uchar>(filesize);
    bmpfileheader[3] = static_cast<uchar>(filesize >> 8);
    bmpfileheader[4] = static_cast<uchar>(filesize >> 16);
    bmpfileheader[5] = static_cast<uchar>(filesize >> 24);

    bmpinfoheader[4] = static_cast<uchar>(m_width);
    bmpinfoheader[5] = static_cast<uchar>(m_width >> 8);
    bmpinfoheader[6] = static_cast<uchar>(m_width >> 16);
    bmpinfoheader[7] = static_cast<uchar>(m_width >> 24);
    bmpinfoheader[8] = static_cast<uchar>(m_height);
    bmpinfoheader[9] = static_cast<uchar>(m_height >> 8);
    bmpinfoheader[10] = static_cast<uchar>(m_height >> 16);
    bmpinfoheader[11] = static_cast<uchar>(m_height >> 24);

    f = fopen(file_name.data(), "wb");
    if (f == nullptr)
    {
        delete[] img;
        img = nullptr;

        return;
    }

    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for (std::uint32_t i = 0; i < m_height; i++)
    {
        fwrite(img + (m_width * (m_height - i - 1) * 3), 3, m_width, f);
        fwrite(bmppad, 1, (4 - (m_width * 3) % 4) % 4, f);
    }

    fclose(f);
    f = nullptr;

    delete[] img;
    img = nullptr;
}
