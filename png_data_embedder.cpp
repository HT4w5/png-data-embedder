#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include "png_data_embedder.h"

PngDataEmbedder::PngDataEmbedder(std::string filePath)
{
    imageFilePath = filePath;
    image = cv::imread(imageFilePath);
    if (image.empty())
    {
        std::cerr << "Failed to read image: " << imageFilePath << std::endl;
        throw std::runtime_error("Can't open file");
    }
}

std::vector<bool> PngDataEmbedder::dataToBinary(const std::string &data) const
{
    std::vector<bool> result;
    for (char c : data)
    {
        std::bitset<8> bits(c);
        for (int i = 7; i >= 0; i--)
        {
            result.push_back(bits[i]);
        }
    }

    return result;
}

std::string PngDataEmbedder::binaryToData(const std::vector<bool> &binData) const
{
    // Validate given data.
    //if (binData.size() % 8 != 0)
    //{
    //    throw std::invalid_argument("The size of the vector must be a multiple of 8.");
    //}
    std::string result;
    for (size_t i = 0; i < binData.size(); i += 8)
    {
        std::bitset<8> bits;
        for (int j = 0; j < 8; j++)
        {
            bits[7 - j] = binData[i + j];
        }
        result += static_cast<char>(bits.to_ulong());
    }

    return result;
}

bool PngDataEmbedder::embedData(const std::string &data)
{
    std::vector<bool> binData = dataToBinary(data);
    if (binData.empty())
    {
        return true; // Nothing to embed.
    }
    else
    {
        // Check image size.
        size_t availableSize = image.rows * image.cols * 3;
        if (availableSize < binData.size())
        {
            std::cerr << "Insufficient file size" << std::endl;
            return false;
        }
        // Iterate through every pixel.
        size_t index = 0;
        for (size_t i = 0; i < image.rows; i++)
        {
            for (size_t j = 0; j < image.cols; j++)
            {
                cv::Vec3b &pixel = image.at<cv::Vec3b>(i, j);
                for (int k = 0; k < 3; k++)
                {
                    // Clear least significant bit.
                    pixel[k] &= 0xFE;
                    pixel[k] |= binData[index];
                    index++;
                    if (index >= binData.size())
                    {
                        return true;
                    }
                }
            }
        }

        std::cerr << "Implemention error" << std::endl;
        return false;
    }
}

std::string PngDataEmbedder::extractData()
{
    std::vector<bool> binData;
    for (size_t i = 0; i < image.rows; i++)
    {
        for (size_t j = 0; j < image.cols; j++)
        {
            cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
            for (int k = 0; k < 3; ++k)
            {
                binData.push_back(pixel[k] & 1);
            }
        }
    }
    return binaryToData(binData);
}

bool PngDataEmbedder::saveImage(const std::string &outputPath) const
{
    return cv::imwrite(outputPath, image);
}