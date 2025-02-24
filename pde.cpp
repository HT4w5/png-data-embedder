#include "png_data_embedder.h"
#include <iostream>

bool embedData(const std::string &path, const std::string &data);
std::string extractData(const std::string &path);
void printHelp();

int main(int argc, char *argv[])
{
    // Parse arguments.
    if (argc == 1)
    {
        std::cerr << "No arguments specified" << std::endl;
        return EXIT_FAILURE;
    }
    std::string verb(argv[1]);
    if (verb == "-h" || verb == "--help")
    {
        printHelp();
    }
    else if (verb == "-m" || verb == "--embed")
    {
        std::string path(argv[2]);
        std::string data;
        std::cout << "Input data to be embedded:" << std::endl;
        std::cin >> data;
        return !embedData(path, data);
    }
    else if (verb == "-x" || verb == "--extract")
    {
        std::string path(argv[2]);
        std::string data = extractData(path);
        std::cout << data;
        return EXIT_SUCCESS;
    }
    else
    {
        std::cerr << "Invalid argument" << std::endl;
        return EXIT_FAILURE;
    }
}

void printHelp()
{
    std::cout << "Png Data Embedder: pde" << '\n';
    std::cout << "Params:" << '\n';
    std::cout << "pde --help    | -h" << '\n';
    std::cout << "pde --embed   | -m  [path/to/file]" << '\n';
    std::cout << "pde --extract | -x  [path/to/file]" << '\n';
}

bool embedData(const std::string &path, const std::string &data)
{
    PngDataEmbedder embedder(path);
    return embedder.embedData(data) && embedder.saveImage("out.png");
}

std::string extractData(const std::string &path)
{
    PngDataEmbedder embedder(path);
    return embedder.extractData();
}