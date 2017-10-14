#include "SceneLoader.h"

#include <iostream>
#include <fstream>

#include <regex>

bool SceneLoader::loadSceneFromFile(const std::string& fileName, Scene &scene)
{
    std::ifstream file;
    file.open(fileName);

    if (!file.is_open())
    {
        return false;
    }
    std::string line;
    std::regex fileNameRegex("fileName\\s+(.*)");
    std::regex cameraRegex("camera\\s+(.*)");
    std::regex materialRegex("material\\s+(.*)");
    std::regex lightRegex("light\\s+(.*)");
    std::regex sphereRegex("sphere\\s+(.*)");

    while(getline(file, line))
    {
        std::smatch matches;
        if (std::regex_match(line, matches, fileNameRegex))
        {

        }
        else if (std::regex_match(line, matches, cameraRegex))
        {
            std::cout << "camera" << std::endl;
            if(!loadCameraFromString(matches[1].str(), scene))
            {
                return false;
            }
        }
        else if (std::regex_match(line, matches, materialRegex))
        {
            std::cout << "material" << std::endl;
            if(!loadMaterialFromString(matches[1].str(), scene))
            {
                return false;
            }
        }
        else if (std::regex_match(line, matches, lightRegex))
        {
            std::cout << "light" << std::endl;
            if(!loadLightFromString(matches[1].str(), scene))
            {
                return false;
            }
        }
        else if (std::regex_match(line, matches, sphereRegex))
        {
            std::cout << "sphere" << std::endl;
            if(!loadSphereFromString(matches[1].str(), scene))
            {
                return false;
            }
        }
    }
    file.close();
    return true;
}

bool SceneLoader::loadCameraFromString (const std::string& line, Scene &scene)
{
    // Camera: width height pos focalLength
    std::regex cameraRegex("(\\d+)\\s+(\\d+)\\s+\\((.+)\\)\\s+(\\d+\\.?\\d*)");
    return false;
}
bool SceneLoader::loadMaterialFromString (const std::string& line, Scene &scene)
{
    // Material: materialName radius origin
    std::regex materialRegex("([a-zA-Z0-9_]+)\\s+\\((.+)\\)\\s+\\((.+)\\)\\s+\\((.+)\\)\\s+(\\d+\\.?\\d*)");
    return false;
}
bool SceneLoader::loadLightFromString (const std::string& line, Scene &scene)
{
    // Light: pos color power
    std::regex lightRegex("\\((.+)\\)\\s+\\((.+)\\)\\s+(\\d+\\.?\\d*)");
    return false;
}
bool SceneLoader::loadSphereFromString (const std::string& line, Scene &scene)
{
    // Sphere: materialName radius origin
    std::regex sphereRegex("([a-zA-Z0-9_]+)\\s+(\\d+\\.?\\d*)\\s+\\((.+)\\)");
    return false;
}

bool SceneLoader::loadColorFromString (const std::string& line, Color &color)
{
    std::regex colorRegex("(-?\\d+\\.?\\d*),(-?\\d+\\.?\\d*),(-?\\d+\\.?\\d*)");

    return false;
}

bool loadVectorFromString    (const std::string& line, Vector3f &point)
{
    std::regex vectorRegex("(-?\\d+\\.?\\d*),(-?\\d+\\.?\\d*),(-?\\d+\\.?\\d*)");

    return false;
}
