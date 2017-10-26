#include "SceneLoader.h"

#include <iostream>
#include <fstream>
#include <regex>

#include "../Utils/Converter.h"

bool SceneLoader::loadSceneFromFile(const std::string& fileName, Scene &scene)
{
    std::ifstream file;
    file.open(fileName);

    if (!file.is_open())
    {
        return false;
    }
    std::string line;
    std::regex fileNameRegex("^fileName\\s+");
    std::regex cameraRegex("^camera\\s+");
    std::regex materialRegex("^material\\s+");
    std::regex lightRegex("^light\\s+");
    std::regex sphereRegex("^sphere\\s+");

    while(getline(file, line))
    {
        std::smatch matches;
        if (std::regex_search(line, matches, fileNameRegex))
        {

        }
        else if (std::regex_search(line, matches, cameraRegex))
        {
            std::cout << matches[0].str() << matches.suffix() << std::endl;

        }
        else if (std::regex_search(line, matches, materialRegex))
        {
            std::cout << matches[0].str() << matches.suffix() << std::endl;
        }
        else if (std::regex_search(line, matches, lightRegex))
        {
            std::cout << matches[0].str() << matches.suffix() << std::endl;
        }
        else if (std::regex_search(line, matches, sphereRegex))
        {
            std::cout << matches[0].str() << matches.suffix() << std::endl;
        }
    }
    file.close();
    return false;
}

bool SceneLoader::loadNameFromString (const std::string& line, std::string &name)
{
    std::regex nameRegex("([[:w:]]+)\\s*");
    std::smatch matches;
    if (!std::regex_match(line, matches, nameRegex))
    {
        return false;
    }
    for(size_t i = 0; i < matches.size(); ++i)
    {
        std::cout << "match " << i << ": " << matches[i].str() << std::endl;
    }
    return true;
}

bool SceneLoader::loadColorFromString (const std::string& line, Color &color)
{
    std::regex colorRegex("\\((-?\\d+\\.?\\d*),(-?\\d+\\.?\\d*),(-?\\d+\\.?\\d*)\\)");
    std::smatch matches;
    if (!std::regex_match(line, matches, colorRegex))
    {
        return false;
    }
    for(size_t i = 0; i < matches.size(); ++i)
    {
        std::cout << "match " << i << ": " << matches[i].str() << std::endl;
    }
    return true;
}

bool loadVectorFromString    (const std::string& line, Vector3f &point)
{
    std::regex vectorRegex("\\((-?\\d+\\.?\\d*),(-?\\d+\\.?\\d*),(-?\\d+\\.?\\d*)\\)");
    std::smatch matches;
    if (!std::regex_match(line, matches, vectorRegex))
    {
        return false;
    }
    for(size_t i = 0; i < matches.size(); ++i)
    {
        std::cout << "match " << i << ": " << matches[i].str() << std::endl;
    }
    return true;
}
