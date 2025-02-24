#ifndef PNG_DATA_EMBED_H
#define PNG_DATA_EMBED_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

class PngDataEmbedder
{
private:
    cv::Mat image;
    std::string imageFilePath;

    std::vector<bool> dataToBinary(const std::string &data) const;
    std::string binaryToData(const std::vector<bool> &binData) const;

public:
    PngDataEmbedder(std::string filePath);
    bool embedData(const std::string &data);
    std::string extractData();
    bool saveImage(const std::string &outputPath) const;
};

#endif